#include "..\Public\Frustum.h"


IMPLEMENT_SINGLETON(CFrustum)

CFrustum::CFrustum()
{
}

HRESULT CFrustum::NativeConstruct(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	if (nullptr == pGraphic_Device)
		return E_FAIL;

	m_pGraphic_Device = pGraphic_Device;

	m_vtx[0].x = -1.0f; m_vtx[0].y = 1.0f; m_vtx[0].z = 0.0f;
	m_vtx[1].x = 1.0f; m_vtx[1].y = 1.0f; m_vtx[1].z = 0.0f;
	m_vtx[2].x = 1.0f; m_vtx[2].y = -1.0f; m_vtx[2].z = 0.0f;
	m_vtx[3].x = -1.0f; m_vtx[3].y = -1.0f; m_vtx[3].z = 0.0f;
	m_vtx[4].x = -1.0f; m_vtx[0].y = 1.0f;  m_vtx[4].z = 1.0f;
	m_vtx[5].x = 1.0f; m_vtx[1].y = 1.0f; m_vtx[5].z = 1.0f;
	m_vtx[6].x = 1.0f; m_vtx[2].y = -1.0f; m_vtx[6].z = 1.0f;
	m_vtx[7].x = -1.0f; m_vtx[3].y = -1.0f; m_vtx[7].z = 1.0f;

	Safe_AddRef(m_pGraphic_Device);

	ZeroMemory(m_Plane, sizeof(m_Plane));

	return S_OK;
}

void CFrustum::Update_Plane()
{
	_float4x4 projMTX;
	D3DXPLANE _plane[6];
	ZeroMemory(_plane, sizeof(_plane));

	m_pGraphic_Device->GetTransform(D3DTS_PROJECTION, &projMTX);
	D3DXMatrixInverse(&projMTX, nullptr, &projMTX);

	for (int i = 0; i < 8; i++)
		D3DXVec3TransformCoord(&m_vtx[i], &m_vtx[i], &projMTX);

	_float4x4		ViewMatrix;
	m_pGraphic_Device->GetTransform(D3DTS_VIEW, &ViewMatrix);
	D3DXMatrixInverse(&ViewMatrix, nullptr, &ViewMatrix);

	for (int i = 0; i < 8; i++)
		D3DXVec3TransformCoord(&m_vtx[i], &m_vtx[i], &ViewMatrix);
	
	//D3DXPlaneFromPoints(&m_Plane[0], &m_vtx[0], &m_vtx[1], &m_vtx[2]);
	D3DXPlaneFromPoints(&_plane[1], &m_vtx[1], &m_vtx[5], &m_vtx[6]);
	//D3DXPlaneFromPoints(&m_Plane[2], &m_vtx[5], &m_vtx[4], &m_vtx[7]);
	D3DXPlaneFromPoints(&_plane[3], &m_vtx[4], &m_vtx[0], &m_vtx[3]);
	D3DXPlaneFromPoints(&_plane[4], &m_vtx[4], &m_vtx[5], &m_vtx[1]);
	D3DXPlaneFromPoints(&_plane[5], &m_vtx[3], &m_vtx[2], &m_vtx[6]);

	memcpy(m_Plane, _plane, sizeof(m_Plane));
}

BOOL CFrustum::IsIn(_float3 _Pos)
{
	//1, 3, 4, 5

	_float fDist;
	fDist = D3DXPlaneDotCoord(&m_Plane[1], &_Pos);
	if (fDist > 0)
		return FALSE;

	fDist = D3DXPlaneDotCoord(&m_Plane[3], &_Pos);
	if (fDist > 0)
		return FALSE;

	fDist = D3DXPlaneDotCoord(&m_Plane[4], &_Pos);
	if (fDist > 0)
		return FALSE;

	fDist = D3DXPlaneDotCoord(&m_Plane[5], &_Pos);
	if (fDist > 0)
		return FALSE;

	return TRUE;
}

void CFrustum::Free()
{
	Safe_Release(m_pGraphic_Device);
}
