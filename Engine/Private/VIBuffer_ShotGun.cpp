#include "..\Public\VIBuffer_ShotGun.h"



CVIBuffer_ShotGun::CVIBuffer_ShotGun(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CVIBuffer(pGraphic_Device)
{
}

CVIBuffer_ShotGun::CVIBuffer_ShotGun(const CVIBuffer_ShotGun & rhs)
	:CVIBuffer(rhs)
{
}

HRESULT CVIBuffer_ShotGun::NativeConstruct_Prototype()
{
	if (FAILED(__super::NativeConstruct_Prototype()))
		return E_FAIL;

	m_iNumVertices = 48;
	m_iStride = sizeof(VTXCUBETEX);

	m_dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);
	m_ePrimitiveType = D3DPT_TRIANGLELIST;
	m_iNumPrimitives = 64;

	if (FAILED(Create_VertexBuffer()))
		return E_FAIL;

	VTXCUBETEX*		pVertices = nullptr;

	

	m_pVB->Lock(0, 0/*m_iStride * m_iNumVertices*/, (void**)&pVertices, 0);
	//¼ÕÀâÀÌ
	_float3 _Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[0].vPosition = _float3(-0.04f, 0.05f, 0.05f);
	pVertices[0].vTexUV = pVertices[0].vPosition;
	pVertices[0].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[1].vPosition = _float3(-0.04f, 0.1f, 0.f);
	pVertices[1].vTexUV = pVertices[1].vPosition;
	pVertices[1].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[2].vPosition = _float3(-0.04f, -0.05f, -0.05f);
	pVertices[2].vTexUV = pVertices[2].vPosition;
	pVertices[2].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[3].vPosition = _float3(-0.04f, -0.1f, 0.f);
	pVertices[3].vTexUV = pVertices[3].vPosition;
	pVertices[3].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[4].vPosition = _float3(0.04f, 0.05f, 0.05f);
	pVertices[4].vTexUV = pVertices[4].vPosition;
	pVertices[4].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[5].vPosition = _float3(0.04f, 0.1f, 0.f);
	pVertices[5].vTexUV = pVertices[5].vPosition;
	pVertices[5].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[6].vPosition = _float3(0.04f, -0.05f, -0.05f);
	pVertices[6].vTexUV = pVertices[6].vPosition;
	pVertices[6].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[7].vPosition = _float3(0.04f, -0.1f, 0.f);
	pVertices[7].vTexUV = pVertices[7].vPosition;
	pVertices[7].vNormal = _Normal;

	//ÃÑ µÞºÎºÐ
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[8].vPosition = _float3(-0.04f, 0.05f, 0.05f);
	pVertices[8].vTexUV = pVertices[8].vPosition;
	pVertices[8].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[9].vPosition = _float3(-0.04f, -0.01f, -0.2f);
	pVertices[9].vTexUV = pVertices[9].vPosition;
	pVertices[9].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[10].vPosition = _float3(-0.04f, -0.15f, -0.2f);
	pVertices[10].vTexUV = pVertices[10].vPosition;
	pVertices[10].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[11].vPosition = _float3(-0.04f, 0.f, 0.04f);
	pVertices[11].vTexUV = pVertices[11].vPosition;
	pVertices[11].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[12].vPosition = _float3(0.04f, 0.05f, 0.05f);
	pVertices[12].vTexUV = pVertices[12].vPosition;
	pVertices[12].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[13].vPosition = _float3(0.04f, -0.01f, -0.2f);
	pVertices[13].vTexUV = pVertices[13].vPosition;
	pVertices[13].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[14].vPosition = _float3(0.04f, -0.15f, -0.2f);
	pVertices[14].vTexUV = pVertices[14].vPosition;
	pVertices[14].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[15].vPosition = _float3(0.04f, 0.f, 0.04f);
	pVertices[15].vTexUV = pVertices[15].vPosition;
	pVertices[15].vNormal = _Normal;

	//¾Õ¼ÕÀâÀÌ
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[16].vPosition = _float3(-0.06f, 0.06f, 0.35f);
	pVertices[16].vTexUV = pVertices[16].vPosition;
	pVertices[16].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[17].vPosition = _float3(-0.06f, 0.06f, 0.18f);
	pVertices[17].vTexUV = pVertices[17].vPosition;
	pVertices[17].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[18].vPosition = _float3(-0.06f, -0.03f, 0.18f);
	pVertices[18].vTexUV = pVertices[18].vPosition;
	pVertices[18].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[19].vPosition = _float3(-0.06f, -0.03f, 0.35f);
	pVertices[19].vTexUV = pVertices[19].vPosition;
	pVertices[19].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[20].vPosition = _float3(0.06f, 0.06f, 0.35f);
	pVertices[20].vTexUV = pVertices[20].vPosition;
	pVertices[20].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[21].vPosition = _float3(0.06f, 0.06f, 0.18f);
	pVertices[21].vTexUV = pVertices[21].vPosition;
	pVertices[21].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[22].vPosition = _float3(0.06f, -0.03f, 0.18f);
	pVertices[22].vTexUV = pVertices[22].vPosition;
	pVertices[22].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[23].vPosition = _float3(0.06f, -0.03f, 0.35f);
	pVertices[23].vTexUV = pVertices[23].vPosition;
	pVertices[23].vNormal = _Normal;

	//ÃÑ ¸öÅë
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[24].vPosition = _float3(-0.04f, 0.1f, 0.47f);
	pVertices[24].vTexUV = pVertices[24].vPosition;
	pVertices[24].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[25].vPosition = _float3(-0.04f, 0.1f, 0.0f);
	pVertices[25].vTexUV = pVertices[25].vPosition;
	pVertices[25].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[26].vPosition = _float3(-0.04f, 0.0f, 0.0f);
	pVertices[26].vTexUV = pVertices[26].vPosition;
	pVertices[26].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[27].vPosition = _float3(-0.04f, 0.0f, 0.47f);
	pVertices[27].vTexUV = pVertices[27].vPosition;
	pVertices[27].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[28].vPosition = _float3(0.04f, 0.1f, 0.47f);
	pVertices[28].vTexUV = pVertices[28].vPosition;
	pVertices[28].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[29].vPosition = _float3(0.04f, 0.1f, 0.0f);
	pVertices[29].vTexUV = pVertices[29].vPosition;
	pVertices[29].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[30].vPosition = _float3(0.04f, 0.0f, 0.0f);
	pVertices[30].vTexUV = pVertices[30].vPosition;
	pVertices[30].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[31].vPosition = _float3(0.04f, 0.0f, 0.47f);
	pVertices[31].vTexUV = pVertices[31].vPosition;
	pVertices[31].vNormal = _Normal;

	//ÃÑ±¸
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[32].vPosition = _float3(-0.02f, 0.08f, 0.5f);
	pVertices[32].vTexUV = pVertices[32].vPosition;
	pVertices[32].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[33].vPosition = _float3(-0.02f, 0.08f, 0.47f);
	pVertices[33].vTexUV = pVertices[33].vPosition;
	pVertices[33].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[34].vPosition = _float3(-0.02f, 0.04f, 0.47f);
	pVertices[34].vTexUV = pVertices[34].vPosition;
	pVertices[34].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[35].vPosition = _float3(-0.02f, 0.04f, 0.5f);
	pVertices[35].vTexUV = pVertices[35].vPosition;
	pVertices[35].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[36].vPosition = _float3(0.02f, 0.08f, 0.5f);
	pVertices[36].vTexUV = pVertices[36].vPosition;
	pVertices[36].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[37].vPosition = _float3(0.02f, 0.08f, 0.47f);
	pVertices[37].vTexUV = pVertices[37].vPosition;
	pVertices[37].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[38].vPosition = _float3(0.02f, 0.04f, 0.47f);
	pVertices[38].vTexUV = pVertices[38].vPosition;
	pVertices[38].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[39].vPosition = _float3(0.02f, 0.04f, 0.5f);
	pVertices[39].vTexUV = pVertices[39].vPosition;
	pVertices[39].vNormal = _Normal;

	//°¡´ÆÀÚ
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[40].vPosition = _float3(-0.01f, 0.13f, 0.47f);
	pVertices[40].vTexUV = pVertices[40].vPosition;
	pVertices[40].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[41].vPosition = _float3(-0.01f, 0.13f, 0.46f);
	pVertices[41].vTexUV = pVertices[41].vPosition;
	pVertices[41].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[42].vPosition = _float3(-0.01f, 0.1f, 0.43f);
	pVertices[42].vTexUV = pVertices[42].vPosition;
	pVertices[42].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[43].vPosition = _float3(-0.01f, 0.1f, 0.47f);
	pVertices[43].vTexUV = pVertices[43].vPosition;
	pVertices[43].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[44].vPosition = _float3(0.01f, 0.13f, 0.47f);
	pVertices[44].vTexUV = pVertices[44].vPosition;
	pVertices[44].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[45].vPosition = _float3(0.01f, 0.13f, 0.46f);
	pVertices[45].vTexUV = pVertices[45].vPosition;
	pVertices[45].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[46].vPosition = _float3(0.01f, 0.1f, 0.43f);
	pVertices[46].vTexUV = pVertices[46].vPosition;
	pVertices[46].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f)+ _float3(0.f, 0.f, 1.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[47].vPosition = _float3(0.01f, 0.1f, 0.47f);
	pVertices[47].vTexUV = pVertices[47].vPosition;
	pVertices[47].vNormal = _Normal;

	m_pVB->Unlock();

	m_iPrimitiveIndicesSize = sizeof(FACELISTINDICES16);
	m_eFormat = D3DFMT_INDEX16;

	if (FAILED(Create_IndexBuffer()))
		return E_FAIL;

	FACELISTINDICES16*		pIndices = nullptr;

	m_pIB->Lock(0, 0, (void**)&pIndices, 0);

	//¼ÕÀâÀÌ
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
	pIndices[5]._1 = 7;
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

	//ÃÑµÞºÎºÐ
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

	//¾Õ¼ÕÀâÀÌ
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

	//ÃÑ»óºÎ
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

	//ÃÑ±¸
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

	//¿ÞÂÊ ¼ÕÀâÀÌ_1
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

	//ÃÑ»óºÎ- ÇÏºÎ
	pIndices[62]._0 = 27;
	pIndices[62]._1 = 26;
	pIndices[62]._2 = 30;

	pIndices[63]._0 = 27;
	pIndices[63]._1 = 30;
	pIndices[63]._2 = 31;



	
	m_pIB->Unlock();
	return S_OK;
}

HRESULT CVIBuffer_ShotGun::NativeConstruct(void * pArg)
{
	if (FAILED(__super::NativeConstruct(pArg)))
		return E_FAIL;

	return S_OK;
}

CVIBuffer_ShotGun * CVIBuffer_ShotGun::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CVIBuffer_ShotGun*	pInstance = new CVIBuffer_ShotGun(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_ShotGun"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CVIBuffer_ShotGun::Clone(void * pArg)
{
	CVIBuffer_ShotGun*	pInstance = new CVIBuffer_ShotGun(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_ShotGun"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CVIBuffer_ShotGun::Free()
{
	__super::Free();
}
