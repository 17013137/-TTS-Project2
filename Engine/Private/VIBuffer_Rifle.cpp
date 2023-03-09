#include "..\Public\VIBuffer_Rifle.h"



CVIBuffer_Rifle::CVIBuffer_Rifle(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CVIBuffer(pGraphic_Device)
{
}

CVIBuffer_Rifle::CVIBuffer_Rifle(const CVIBuffer_Rifle & rhs)
	:CVIBuffer(rhs)
{
}

HRESULT CVIBuffer_Rifle::NativeConstruct_Prototype()
{
	if (FAILED(__super::NativeConstruct_Prototype()))
		return E_FAIL;

	m_iNumVertices = 100;
	m_iStride = sizeof(VTXCUBETEX);

	m_dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);
	m_ePrimitiveType = D3DPT_TRIANGLELIST;
	m_iNumPrimitives = 126;

	if (FAILED(Create_VertexBuffer()))
		return E_FAIL;

	VTXCUBETEX*		pVertices = nullptr;

	

	m_pVB->Lock(0, 0/*m_iStride * m_iNumVertices*/, (void**)&pVertices, 0);

	//손잡이
	_float3 _Normal = (_float3(-1.f, 0.f, 0.f)+ _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[0].vPosition = _float3(-0.05f, 0.2f, 0.05f);
	pVertices[0].vTexUV = pVertices[0].vPosition;
	pVertices[0].vNormal = _Normal;
	
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[1].vPosition = _float3(-0.05f, 0.2f, -0.05f);
	pVertices[1].vTexUV = pVertices[1].vPosition;
	pVertices[1].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[2].vPosition = _float3(-0.05f, -0.1f, -0.08f);
	pVertices[2].vTexUV = pVertices[2].vPosition;
	pVertices[2].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[3].vPosition = _float3(-0.05f, -0.1f, 0.02f);
	pVertices[3].vTexUV = pVertices[3].vPosition;
	pVertices[3].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[4].vPosition = _float3(0.05f, 0.2f, 0.05f);
	pVertices[4].vTexUV = pVertices[4].vPosition;
	pVertices[4].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f)+ _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[5].vPosition = _float3(0.05f, 0.2f, -0.05f);
	pVertices[5].vTexUV = pVertices[5].vPosition;
	pVertices[5].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[6].vPosition = _float3(0.05f, -0.1f, -0.08f);
	pVertices[6].vTexUV = pVertices[6].vPosition;
	pVertices[6].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[7].vPosition = _float3(0.05f, -0.1f, 0.02f);
	pVertices[7].vTexUV = pVertices[7].vPosition;
	pVertices[7].vNormal = _Normal;

	//총 하부
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[8].vPosition = _float3(-0.1f, 0.25f, 0.48f);
	pVertices[8].vTexUV = pVertices[8].vPosition;
	pVertices[8].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[9].vPosition = _float3(-0.1f, 0.25f, -0.05f);
	pVertices[9].vTexUV = pVertices[9].vPosition;
	pVertices[9].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[10].vPosition = _float3(-0.1f, 0.2f, -0.05f);
	pVertices[10].vTexUV = pVertices[10].vPosition;
	pVertices[10].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[11].vPosition = _float3(-0.1f, 0.2f, 0.48f);
	pVertices[11].vTexUV = pVertices[11].vPosition;
	pVertices[11].vNormal = _Normal;
	
	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[12].vPosition = _float3(0.1f, 0.25f, 0.48f);
	pVertices[12].vTexUV = pVertices[12].vPosition;
	pVertices[12].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[13].vPosition = _float3(0.1f, 0.25f, -0.05f);
	pVertices[13].vTexUV = pVertices[13].vPosition;
	pVertices[13].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[14].vPosition = _float3(0.1f, 0.2f, -0.05f);
	pVertices[14].vTexUV = pVertices[14].vPosition;
	pVertices[14].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[15].vPosition = _float3(0.1f, 0.2f, 0.48f);
	pVertices[15].vTexUV = pVertices[15].vPosition;
	pVertices[15].vNormal = _Normal;

	//앞 손잡이
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[16].vPosition = _float3(-0.05f, 0.2f, 0.4f);
	pVertices[16].vTexUV = pVertices[16].vPosition;
	pVertices[16].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[17].vPosition = _float3(-0.05f, 0.2f, 0.3f);
	pVertices[17].vTexUV = pVertices[17].vPosition;
	pVertices[17].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[18].vPosition = _float3(-0.05f, 0.f, 0.33f);
	pVertices[18].vTexUV = pVertices[18].vPosition;
	pVertices[18].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[19].vPosition = _float3(-0.05f,0.f, 0.45f);
	pVertices[19].vTexUV = pVertices[19].vPosition;
	pVertices[19].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);

	pVertices[20].vPosition = _float3(0.05f, 0.2f, 0.4f);
	pVertices[20].vTexUV = pVertices[20].vPosition;
	pVertices[20].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);

	pVertices[21].vPosition = _float3(0.05f, 0.2f, 0.3f);
	pVertices[21].vTexUV = pVertices[21].vPosition;
	pVertices[21].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[22].vPosition = _float3(0.05f, 0.f, 0.33f);
	pVertices[22].vTexUV = pVertices[22].vPosition;
	pVertices[22].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[23].vPosition = _float3(0.05f, 0.f, 0.45f);
	pVertices[23].vTexUV = pVertices[23].vPosition;
	pVertices[23].vNormal = _Normal;

	//총상부
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[24].vPosition = _float3(-0.08f, 0.4f, 0.47f);
	pVertices[24].vTexUV = pVertices[24].vPosition;
	pVertices[24].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[25].vPosition = _float3(-0.08f, 0.4f, -0.05f);
	pVertices[25].vTexUV = pVertices[25].vPosition;
	pVertices[25].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[26].vPosition = _float3(-0.08f, 0.25f, -0.05f);
	pVertices[26].vTexUV = pVertices[26].vPosition;
	pVertices[26].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[27].vPosition = _float3(-0.08f, 0.25f, 0.47f);
	pVertices[27].vTexUV = pVertices[27].vPosition;
	pVertices[27].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[28].vPosition = _float3(0.08f, 0.4f, 0.47f);
	pVertices[28].vTexUV = pVertices[28].vPosition;
	pVertices[28].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[29].vPosition = _float3(0.08f, 0.4f, -0.05f);
	pVertices[29].vTexUV = pVertices[29].vPosition;
	pVertices[29].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[30].vPosition = _float3(0.08f, 0.25f, -0.05f);
	pVertices[30].vTexUV = pVertices[30].vPosition;
	pVertices[30].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[31].vPosition = _float3(0.08f, 0.25f, 0.47f);
	pVertices[31].vTexUV = pVertices[31].vPosition;
	pVertices[31].vNormal = _Normal;

	//총구
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[32].vPosition = _float3(-0.02f, 0.36f, 0.5f);
	pVertices[32].vTexUV = pVertices[32].vPosition;
	pVertices[32].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) ) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[33].vPosition = _float3(-0.02f, 0.36f, 0.47f);
	pVertices[33].vTexUV = pVertices[33].vPosition;
	pVertices[33].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[34].vPosition = _float3(-0.02f, 0.32f, 0.47f);
	pVertices[34].vTexUV = pVertices[34].vPosition;
	pVertices[34].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[35].vPosition = _float3(-0.02f, 0.32f, 0.5f);
	pVertices[35].vTexUV = pVertices[35].vPosition;
	pVertices[35].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[36].vPosition = _float3(0.02f, 0.36f, 0.5f);
	pVertices[36].vTexUV = pVertices[36].vPosition;
	pVertices[36].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[37].vPosition = _float3(0.02f, 0.36f, 0.47f);
	pVertices[37].vTexUV = pVertices[37].vPosition;
	pVertices[37].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[38].vPosition = _float3(0.02f, 0.32f, 0.47f);
	pVertices[38].vTexUV = pVertices[38].vPosition;
	pVertices[38].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[39].vPosition = _float3(0.02f, 0.32f, 0.5f);
	pVertices[39].vTexUV = pVertices[39].vPosition;
	pVertices[39].vNormal = _Normal;

	//왼쪽손잡이_1
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[40].vPosition = _float3(-0.1f, 0.44f,0.4f);
	pVertices[40].vTexUV = pVertices[40].vPosition;
	pVertices[40].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[41].vPosition = _float3(-0.1f, 0.44f, 0.38f);
	pVertices[41].vTexUV = pVertices[41].vPosition;
	pVertices[41].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[42].vPosition = _float3(-0.1f, 0.25f, 0.4f);
	pVertices[42].vTexUV = pVertices[42].vPosition;
	pVertices[42].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[43].vPosition = _float3(-0.1f, 0.25f, 0.42f);
	pVertices[43].vTexUV = pVertices[43].vPosition;
	pVertices[43].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[44].vPosition = _float3(-0.08f, 0.44f, 0.4f);
	pVertices[44].vTexUV = pVertices[44].vPosition;
	pVertices[44].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[45].vPosition = _float3(-0.08f, 0.44f, 0.38f);
	pVertices[45].vTexUV = pVertices[45].vPosition;
	pVertices[45].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f)+ _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[46].vPosition = _float3(-0.08f, 0.25f, 0.4f);
	pVertices[46].vTexUV = pVertices[46].vPosition;
	pVertices[46].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f)+ _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[47].vPosition = _float3(-0.08f, 0.25f, 0.42f);
	pVertices[47].vTexUV = pVertices[47].vPosition;
	pVertices[47].vNormal = _Normal;

	//왼쪽손잡이_2 위
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[48].vPosition = _float3(-0.1f, 0.44f, 0.4f);
	pVertices[48].vTexUV = pVertices[48].vPosition;
	pVertices[48].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[49].vPosition = _float3(-0.1f, 0.44f, 0.2f);
	pVertices[49].vTexUV = pVertices[49].vPosition;
	pVertices[49].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[50].vPosition = _float3(-0.1f, 0.42f, 0.2f);
	pVertices[50].vTexUV = pVertices[50].vPosition;
	pVertices[50].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[51].vPosition = _float3(-0.1f, 0.42f, 0.4f);
	pVertices[51].vTexUV = pVertices[51].vPosition;
	pVertices[51].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[52].vPosition = _float3(-0.08f, 0.44f, 0.4f);
	pVertices[52].vTexUV = pVertices[52].vPosition;
	pVertices[52].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[53].vPosition = _float3(-0.08f, 0.44f, 0.2f);
	pVertices[53].vTexUV = pVertices[53].vPosition;
	pVertices[53].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[54].vPosition = _float3(-0.08f, 0.42f, 0.2f);
	pVertices[54].vTexUV = pVertices[54].vPosition;
	pVertices[54].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[55].vPosition = _float3(-0.08f, 0.42f, 0.4f);
	pVertices[55].vTexUV = pVertices[55].vPosition;
	pVertices[55].vNormal = _Normal;

	//왼쪽손잡이_3
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[56].vPosition = _float3(-0.1f, 0.44f,0.22f);
	pVertices[56].vTexUV = pVertices[56].vPosition;
	pVertices[56].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[57].vPosition = _float3(-0.1f, 0.44f, 0.2f);
	pVertices[57].vTexUV = pVertices[57].vPosition;
	pVertices[57].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[58].vPosition = _float3(-0.1f, 0.25f, 0.13f);
	pVertices[58].vTexUV = pVertices[58].vPosition;
	pVertices[58].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[59].vPosition = _float3(-0.1f, 0.25f, 0.15f);
	pVertices[59].vTexUV = pVertices[59].vPosition;
	pVertices[59].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[60].vPosition = _float3(-0.08f, 0.44f, 0.22f);
	pVertices[60].vTexUV = pVertices[60].vPosition;
	pVertices[60].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[61].vPosition = _float3(-0.08f, 0.44f, 0.2f);
	pVertices[61].vTexUV = pVertices[61].vPosition;
	pVertices[61].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[62].vPosition = _float3(-0.08f, 0.25f, 0.13f);
	pVertices[62].vTexUV = pVertices[62].vPosition;
	pVertices[62].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[63].vPosition = _float3(-0.08f, 0.25f, 0.15f);
	pVertices[63].vTexUV = pVertices[63].vPosition;
	pVertices[63].vNormal = _Normal;

	//오른쪽손잡이_1
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[64].vPosition = _float3(0.1f, 0.44f, 0.4f);
	pVertices[64].vTexUV = pVertices[64].vPosition;
	pVertices[64].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[65].vPosition = _float3(0.1f, 0.44f, 0.38f);
	pVertices[65].vTexUV = pVertices[65].vPosition;
	pVertices[65].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f)  + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[66].vPosition = _float3(0.1f, 0.25f, 0.4f);
	pVertices[66].vTexUV = pVertices[66].vPosition;
	pVertices[66].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f)+ _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[67].vPosition = _float3(0.1f, 0.25f, 0.42f);
	pVertices[67].vTexUV = pVertices[67].vPosition;
	pVertices[67].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[68].vPosition = _float3(0.08f, 0.44f, 0.4f);
	pVertices[68].vTexUV = pVertices[68].vPosition;
	pVertices[68].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);

	pVertices[69].vPosition = _float3(0.08f, 0.44f, 0.38f);
	pVertices[69].vTexUV = pVertices[69].vPosition;
	pVertices[69].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[70].vPosition = _float3(0.08f, 0.25f, 0.4f);
	pVertices[70].vTexUV = pVertices[70].vPosition;
	pVertices[70].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[71].vPosition = _float3(0.08f, 0.25f, 0.42f);
	pVertices[71].vTexUV = pVertices[71].vPosition;
	pVertices[71].vNormal = _Normal;

	//오른쪽손잡이_2 위
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[72].vPosition = _float3(0.1f, 0.44f, 0.4f);
	pVertices[72].vTexUV = pVertices[72].vPosition;
	pVertices[72].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[73].vPosition = _float3(0.1f, 0.44f, 0.2f);
	pVertices[73].vTexUV = pVertices[73].vPosition;
	pVertices[73].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[74].vPosition = _float3(0.1f, 0.42f, 0.2f);
	pVertices[74].vTexUV = pVertices[74].vPosition;
	pVertices[74].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[75].vPosition = _float3(0.1f, 0.42f, 0.4f);
	pVertices[75].vTexUV = pVertices[75].vPosition;
	pVertices[75].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[76].vPosition = _float3(0.08f, 0.44f, 0.4f);
	pVertices[76].vTexUV = pVertices[76].vPosition;
	pVertices[76].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);

	pVertices[77].vPosition = _float3(0.08f, 0.44f, 0.2f);
	pVertices[77].vTexUV = pVertices[77].vPosition;
	pVertices[77].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[78].vPosition = _float3(0.08f, 0.42f, 0.2f);
	pVertices[78].vTexUV = pVertices[78].vPosition;
	pVertices[78].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[79].vPosition = _float3(0.08f, 0.42f, 0.4f);
	pVertices[79].vTexUV = pVertices[79].vPosition;
	pVertices[79].vNormal = _Normal;

	//오른쪽손잡이_3
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[80].vPosition = _float3(0.1f, 0.44f, 0.22f);
	pVertices[80].vTexUV = pVertices[80].vPosition;
	pVertices[80].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[81].vPosition = _float3(0.1f, 0.44f, 0.2f);
	pVertices[81].vTexUV = pVertices[81].vPosition;
	pVertices[81].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[82].vPosition = _float3(0.1f, 0.25f, 0.13f);
	pVertices[82].vTexUV = pVertices[82].vPosition;
	pVertices[82].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[83].vPosition = _float3(0.1f, 0.25f, 0.15f);
	pVertices[83].vTexUV = pVertices[83].vPosition;
	pVertices[83].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[84].vPosition = _float3(0.08f, 0.44f, 0.22f);
	pVertices[84].vTexUV = pVertices[84].vPosition;
	pVertices[84].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[85].vPosition = _float3(0.08f, 0.44f, 0.2f);
	pVertices[85].vTexUV = pVertices[85].vPosition;
	pVertices[85].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[86].vPosition = _float3(0.08f, 0.25f, 0.13f);
	pVertices[86].vTexUV = pVertices[86].vPosition;
	pVertices[86].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[87].vPosition = _float3(0.08f, 0.25f, 0.15f);
	pVertices[87].vTexUV = pVertices[87].vPosition;
	pVertices[87].vNormal = _Normal;

	//뒷부분
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[88].vPosition = _float3(-0.08f, 0.44f, -0.2f);
	pVertices[88].vTexUV = pVertices[88].vPosition;
	pVertices[88].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[89].vPosition = _float3(-0.08f, 0.f, -0.2f);
	pVertices[89].vTexUV = pVertices[89].vPosition;
	pVertices[89].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[90].vPosition = _float3(0.08f, 0.44f, -0.2f);
	pVertices[90].vTexUV = pVertices[90].vPosition;
	pVertices[90].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[91].vPosition = _float3(0.08f, 0.f, -0.2f);
	pVertices[91].vTexUV = pVertices[91].vPosition;
	pVertices[91].vNormal = _Normal;

	//가늠자
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[92].vPosition = _float3(-0.01f, 0.43f, 0.46f);
	pVertices[92].vTexUV = pVertices[92].vPosition;
	pVertices[92].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[93].vPosition = _float3(-0.01f, 0.43f, 0.45f);
	pVertices[93].vTexUV = pVertices[93].vPosition;
	pVertices[93].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[94].vPosition = _float3(-0.01f, 0.4f, 0.43f);
	pVertices[94].vTexUV = pVertices[94].vPosition;
	pVertices[94].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[95].vPosition = _float3(-0.01f, 0.4f, 0.45f);
	pVertices[95].vTexUV = pVertices[95].vPosition;
	pVertices[95].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[96].vPosition = _float3(0.01f, 0.43f, 0.46f);
	pVertices[96].vTexUV = pVertices[96].vPosition;
	pVertices[96].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[97].vPosition = _float3(0.01f, 0.43f, 0.45f);
	pVertices[97].vTexUV = pVertices[97].vPosition;
	pVertices[97].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[98].vPosition = _float3(0.01f, 0.4f, 0.43f);
	pVertices[98].vTexUV = pVertices[98].vPosition;
	pVertices[98].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[99].vPosition = _float3(0.01f, 0.4f, 0.45f);
	pVertices[99].vTexUV = pVertices[99].vPosition;
	pVertices[99].vNormal = _Normal;

	
	m_pVB->Unlock();

	m_iPrimitiveIndicesSize = sizeof(FACELISTINDICES16);
	m_eFormat = D3DFMT_INDEX16;

	if (FAILED(Create_IndexBuffer()))
		return E_FAIL;

	FACELISTINDICES16*		pIndices = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndices, 0);
	
	//손잡이
	pIndices[0]._0 = 0;
	pIndices[0]._1 = 1;
	pIndices[0]._2 = 2;

	pIndices[1]._0 = 0;
	pIndices[1]._1 = 2;
	pIndices[1]._2 = 3;

	pIndices[2]._0 = 1;
	pIndices[2]._1 = 5;
	pIndices[2]._2 = 6;

	pIndices[3]._0 = 1;
	pIndices[3]._1 = 6;
	pIndices[3]._2 = 2;

	pIndices[4]._0 = 5;
	pIndices[4]._1 = 4;
	pIndices[4]._2 = 7;

	pIndices[5]._0 = 5;
	pIndices[5]._1 =7;
	pIndices[5]._2 = 6;

	pIndices[6]._0 = 4;
	pIndices[6]._1 = 0;
	pIndices[6]._2 = 3;

	pIndices[7]._0 = 4;
	pIndices[7]._1 = 3;
	pIndices[7]._2 = 7;

	pIndices[8]._0 = 3;
	pIndices[8]._1 = 2;
	pIndices[8]._2 = 6;

	pIndices[9]._0 = 3;
	pIndices[9]._1 = 6;
	pIndices[9]._2 = 7;

	//총하부
	pIndices[10]._0 = 9;
	pIndices[10]._1 = 13;
	pIndices[10]._2 = 14;

	pIndices[11]._0 = 9;
	pIndices[11]._1 = 14;
	pIndices[11]._2 = 10;

	pIndices[12]._0 = 13;
	pIndices[12]._1 = 12;
	pIndices[12]._2 = 15;

	pIndices[13]._0 = 13;
	pIndices[13]._1 = 15;
	pIndices[13]._2 = 14;

	pIndices[14]._0 = 12;
	pIndices[14]._1 = 13;
	pIndices[14]._2 = 9;

	pIndices[15]._0 = 12;
	pIndices[15]._1 = 9;
	pIndices[15]._2 = 8;

	pIndices[16]._0 = 8;
	pIndices[16]._1 = 9;
	pIndices[16]._2 = 10;

	pIndices[17]._0 = 8;
	pIndices[17]._1 = 10;
	pIndices[17]._2 = 11;

	pIndices[18]._0 = 12;
	pIndices[18]._1 = 8;
	pIndices[18]._2 = 11;

	pIndices[19]._0 = 12;
	pIndices[19]._1 = 11;
	pIndices[19]._2 = 15;

	pIndices[20]._0 = 11;
	pIndices[20]._1 = 10;
	pIndices[20]._2 = 14;

	pIndices[21]._0 = 11;
	pIndices[21]._1 = 14;
	pIndices[21]._2 = 15;

	//앞손잡이
	pIndices[22]._0 = 16;
	pIndices[22]._1 = 17;
	pIndices[22]._2 = 18;

	pIndices[23]._0 = 16;
	pIndices[23]._1 = 18;
	pIndices[23]._2 = 19;

	pIndices[24]._0 = 17;
	pIndices[24]._1 = 21;
	pIndices[24]._2 = 22;

	pIndices[25]._0 = 17;
	pIndices[25]._1 = 22;
	pIndices[25]._2 = 18;

	pIndices[26]._0 = 21;
	pIndices[26]._1 = 20;
	pIndices[26]._2 = 23;

	pIndices[27]._0 = 21;
	pIndices[27]._1 = 23;
	pIndices[27]._2 = 22;

	pIndices[28]._0 = 20;
	pIndices[28]._1 = 16;
	pIndices[28]._2 = 19;

	pIndices[29]._0 = 20;
	pIndices[29]._1 = 19;
	pIndices[29]._2 = 23;

	pIndices[30]._0 = 19;
	pIndices[30]._1 = 18;
	pIndices[30]._2 = 22;

	pIndices[31]._0 = 19;
	pIndices[31]._1 = 22;
	pIndices[31]._2 = 23;

	//총상부
	pIndices[32]._0 = 24;
	pIndices[32]._1 = 25;
	pIndices[32]._2 = 26;

	pIndices[33]._0 = 24;
	pIndices[33]._1 = 26;
	pIndices[33]._2 = 27;

	pIndices[34]._0 = 25;
	pIndices[34]._1 = 29;
	pIndices[34]._2 = 30;

	pIndices[35]._0 = 25;
	pIndices[35]._1 = 30;
	pIndices[35]._2 = 26;

	pIndices[36]._0 = 29;
	pIndices[36]._1 = 28;
	pIndices[36]._2 = 31;

	pIndices[37]._0 = 29;
	pIndices[37]._1 = 31;
	pIndices[37]._2 = 30;

	pIndices[38]._0 = 28;
	pIndices[38]._1 = 24;
	pIndices[38]._2 = 27;

	pIndices[39]._0 = 28;
	pIndices[39]._1 = 27;
	pIndices[39]._2 = 31;

	pIndices[40]._0 = 28;
	pIndices[40]._1 = 29;
	pIndices[40]._2 = 25;

	pIndices[41]._0 = 28;
	pIndices[41]._1 = 25;
	pIndices[41]._2 = 24;

	//총구
	pIndices[42]._0 = 36;
	pIndices[42]._1 = 37;
	pIndices[42]._2 = 33;

	pIndices[43]._0 = 36;
	pIndices[43]._1 = 33;
	pIndices[43]._2 = 32;

	pIndices[44]._0 = 32;
	pIndices[44]._1 = 33;
	pIndices[44]._2 = 34;

	pIndices[45]._0 = 32;
	pIndices[45]._1 = 34;
	pIndices[45]._2 = 35;

	pIndices[46]._0 = 35;
	pIndices[46]._1 = 34;
	pIndices[46]._2 = 38;

	pIndices[47]._0 = 35;
	pIndices[47]._1 = 38;
	pIndices[47]._2 = 39;

	pIndices[48]._0 = 37;
	pIndices[48]._1 = 36;
	pIndices[48]._2 = 39;

	pIndices[49]._0 = 37;
	pIndices[49]._1 = 39;
	pIndices[49]._2 = 38;

	pIndices[50]._0 = 36;
	pIndices[50]._1 = 32;
	pIndices[50]._2 = 35;

	pIndices[51]._0 = 36;
	pIndices[51]._1 = 35;
	pIndices[51]._2 = 39;

	//왼쪽 손잡이_1
	pIndices[52]._0 = 40;
	pIndices[52]._1 = 41;
	pIndices[52]._2 = 42;
				 
	pIndices[53]._0 = 40;
	pIndices[53]._1 = 42;
	pIndices[53]._2 = 43;
				 
	pIndices[54]._0 = 44;
	pIndices[54]._1 = 45;
	pIndices[54]._2 = 41;
				 
	pIndices[55]._0 = 44;
	pIndices[55]._1 = 41;
	pIndices[55]._2 = 40;
				 
	pIndices[56]._0 = 41;
	pIndices[56]._1 = 45;
	pIndices[56]._2 = 46;
				 
	pIndices[57]._0 = 41;
	pIndices[57]._1 = 46;
	pIndices[57]._2 = 42;
				 
	pIndices[58]._0 = 45;
	pIndices[58]._1 = 44;
	pIndices[58]._2 = 47;
				 
	pIndices[59]._0 = 45;
	pIndices[59]._1 = 47;
	pIndices[59]._2 = 46;
				 
	pIndices[60]._0 = 44;
	pIndices[60]._1 = 40;
	pIndices[60]._2 = 43;
				 
	pIndices[61]._0 = 44;
	pIndices[61]._1 = 43;
	pIndices[61]._2 = 47;

	//왼쪽손잡이_2
	pIndices[62]._0 = 48;
	pIndices[62]._1 = 49;
	pIndices[62]._2 = 50;
				 
	pIndices[63]._0 = 48;
	pIndices[63]._1 = 50;
	pIndices[63]._2 = 51;
				 
	pIndices[64]._0 = 52;
	pIndices[64]._1 = 53;
	pIndices[64]._2 = 49;
				 
	pIndices[65]._0 = 52;
	pIndices[65]._1 = 49;
	pIndices[65]._2 = 48;
				 
	pIndices[66]._0 = 53;
	pIndices[66]._1 = 52;
	pIndices[66]._2 = 55;
				 
	pIndices[67]._0 = 53;
	pIndices[67]._1 = 55;
	pIndices[67]._2 = 54;
				 
	pIndices[68]._0 = 51;
	pIndices[68]._1 = 50;
	pIndices[68]._2 = 54;
				 
	pIndices[69]._0 = 51;
	pIndices[69]._1 = 54;
	pIndices[69]._2 = 55;

	//왼쪽손잡이_3
	pIndices[70]._0 = 56;
	pIndices[70]._1 = 57;
	pIndices[70]._2 = 58;
				 
	pIndices[71]._0 = 56;
	pIndices[71]._1 = 58;
	pIndices[71]._2 = 59;
	
	pIndices[72]._0 = 60;
	pIndices[72]._1 = 61;
	pIndices[72]._2 = 57;
				 
	pIndices[73]._0 = 60;
	pIndices[73]._1 = 57;
	pIndices[73]._2 = 56;
				 
	pIndices[74]._0 = 61;
	pIndices[74]._1 = 60;
	pIndices[74]._2 = 63;
				 
	pIndices[75]._0 = 61;
	pIndices[75]._1 = 63;
	pIndices[75]._2 = 62;
				 
	pIndices[76]._0 = 57;
	pIndices[76]._1 = 61;
	pIndices[76]._2 = 62;
				 
	pIndices[77]._0 = 57;
	pIndices[77]._1 = 62;
	pIndices[77]._2 = 58;
				 
	pIndices[78]._0 = 60;
	pIndices[78]._1 = 56;
	pIndices[78]._2 = 59;
				 
	pIndices[79]._0 = 60;
	pIndices[79]._1 = 59;
	pIndices[79]._2 = 63;

	//오른쪽 손잡이_1
	pIndices[80]._0 = 68;
	pIndices[80]._1 = 69;
	pIndices[80]._2 = 70;

	pIndices[81]._0 = 68;
	pIndices[81]._1 = 70;
	pIndices[81]._2 = 71;

	pIndices[82]._0 = 69;
	pIndices[82]._1 = 66;
	pIndices[82]._2 = 70;

	pIndices[83]._0 = 69;
	pIndices[83]._1 = 65;
	pIndices[83]._2 = 66;

	pIndices[84]._0 = 65;
	pIndices[84]._1 = 64;
	pIndices[84]._2 = 67;

	pIndices[85]._0 = 65;
	pIndices[85]._1 = 67;
	pIndices[85]._2 = 66;

	pIndices[86]._0 = 64;
	pIndices[86]._1 = 68;
	pIndices[86]._2 = 71;

	pIndices[87]._0 = 64;
	pIndices[87]._1 = 71;
	pIndices[87]._2 = 67;

	//오른쪽손잡이_2 위
	pIndices[88]._0 = 76;
	pIndices[88]._1 = 77;
	pIndices[88]._2 = 78;

	pIndices[89]._0 = 76;
	pIndices[89]._1 = 78;
	pIndices[89]._2 = 79;

	pIndices[90]._0 = 72;
	pIndices[90]._1 = 73;
	pIndices[90]._2 = 77;

	pIndices[91]._0 = 72;
	pIndices[91]._1 = 77;
	pIndices[91]._2 = 76;

	pIndices[92]._0 = 73;
	pIndices[92]._1 = 72;
	pIndices[92]._2 = 75;

	pIndices[93]._0 = 73;
	pIndices[93]._1 = 75;
	pIndices[93]._2 = 74;

	pIndices[94]._0 = 79;
	pIndices[94]._1 = 78;
	pIndices[94]._2 = 74;

	pIndices[95]._0 = 79;
	pIndices[95]._1 = 74;
	pIndices[95]._2 = 75;

	//왼쪽손잡7이_3
	pIndices[96]._0 = 84;
	pIndices[96]._1 = 85;
	pIndices[96]._2 = 86;

	pIndices[97]._0 = 84;
	pIndices[97]._1 = 86;
	pIndices[97]._2 = 87;

	pIndices[98]._0 = 85;
	pIndices[98]._1 = 81;
	pIndices[98]._2 = 82;

	pIndices[99]._0 = 85;
	pIndices[99]._1 = 82;
	pIndices[99]._2 = 86;

	pIndices[100]._0 = 81;
	pIndices[100]._1 = 80;
	pIndices[100]._2 = 83;

	pIndices[101]._0 = 81;
	pIndices[101]._1 = 83;
	pIndices[101]._2 = 82;

	pIndices[102]._0 = 80;
	pIndices[102]._1 = 84;
	pIndices[102]._2 = 87;

	pIndices[103]._0 = 80;
	pIndices[103]._1 = 87;
	pIndices[103]._2 = 83;

	//뒷부분
	pIndices[104]._0 = 25;
	pIndices[104]._1 = 88;
	pIndices[104]._2 = 89;

	pIndices[105]._0 = 25;
	pIndices[105]._1 = 89;
	pIndices[105]._2 = 10;

	pIndices[106]._0 = 88;
	pIndices[106]._1 = 90;
	pIndices[106]._2 = 91;

	pIndices[107]._0 = 88;
	pIndices[107]._1 = 91;
	pIndices[107]._2 = 89;

	pIndices[108]._0 = 90;
	pIndices[108]._1 = 29;
	pIndices[108]._2 = 14;

	pIndices[109]._0 = 90;
	pIndices[109]._1 = 14;
	pIndices[109]._2 = 91;

	pIndices[110]._0 = 29;
	pIndices[110]._1 = 25;
	pIndices[110]._2 = 10;

	pIndices[111]._0 = 29;
	pIndices[111]._1 = 10;
	pIndices[111]._2 = 14;

	pIndices[112]._0 = 90;
	pIndices[112]._1 = 88;
	pIndices[112]._2 = 25;

	pIndices[113]._0 = 90;
	pIndices[113]._1 = 25;
	pIndices[113]._2 = 29;

	pIndices[114]._0 = 10;
	pIndices[114]._1 = 89;
	pIndices[114]._2 = 91;

	pIndices[115]._0 = 10;
	pIndices[115]._1 = 91;
	pIndices[115]._2 = 14;

	pIndices[116]._0 = 92;
	pIndices[116]._1 = 93;
	pIndices[116]._2 = 94;

	pIndices[117]._0 = 92;
	pIndices[117]._1 = 94;
	pIndices[117]._2 = 95;

	pIndices[118]._0 = 93;
	pIndices[118]._1 = 97;
	pIndices[118]._2 = 98;

	pIndices[119]._0 = 93;
	pIndices[119]._1 = 98;
	pIndices[119]._2 = 94;

	pIndices[120]._0 = 97;
	pIndices[120]._1 = 99;
	pIndices[120]._2 = 98;

	pIndices[121]._0 = 97;
	pIndices[121]._1 = 96;
	pIndices[121]._2 = 99;

	pIndices[122]._0 = 96;
	pIndices[122]._1 = 92;
	pIndices[122]._2 = 95;

	pIndices[123]._0 = 96;
	pIndices[123]._1 = 95;
	pIndices[123]._2 = 99;

	pIndices[124]._0 = 96;
	pIndices[124]._1 = 97;
	pIndices[124]._2 = 93;

	pIndices[125]._0 = 96;
	pIndices[125]._1 = 93;
	pIndices[125]._2 = 92;
	
	m_pIB->Unlock();
	return S_OK;
}

HRESULT CVIBuffer_Rifle::NativeConstruct(void * pArg)
{
	if (FAILED(__super::NativeConstruct(pArg)))
		return E_FAIL;

	return S_OK;
}

CVIBuffer_Rifle * CVIBuffer_Rifle::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CVIBuffer_Rifle*	pInstance = new CVIBuffer_Rifle(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Rifle"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CVIBuffer_Rifle::Clone(void * pArg)
{
	CVIBuffer_Rifle*	pInstance = new CVIBuffer_Rifle(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Rifle"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CVIBuffer_Rifle::Free()
{
	__super::Free();
}
