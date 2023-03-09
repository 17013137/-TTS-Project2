#include "..\Public\VIBuffer_Timber.h"



CVIBuffer_Timber::CVIBuffer_Timber(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CVIBuffer(pGraphic_Device)
{
}

CVIBuffer_Timber::CVIBuffer_Timber(const CVIBuffer_Timber & rhs)
	:CVIBuffer(rhs)
{
}

HRESULT CVIBuffer_Timber::NativeConstruct_Prototype()
{
	if (FAILED(__super::NativeConstruct_Prototype()))
		return E_FAIL;

	m_iNumVertices = 16;
	m_iStride = sizeof(VTXCUBETEX);

	m_dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);
	m_ePrimitiveType = D3DPT_TRIANGLELIST;
	m_iNumPrimitives = 20;

	if (FAILED(Create_VertexBuffer()))
		return E_FAIL;

	VTXCUBETEX*		pVertices = nullptr;

	

	m_pVB->Lock(0, 0/*m_iStride * m_iNumVertices*/, (void**)&pVertices, 0);

	//¼ÕÀâÀÌ
	_float3 _Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[0].vPosition = _float3(-0.1f, 0.1f, -0.1f);
	pVertices[0].vTexUV = _float3(-1.f, 1.f, -1.f);
	pVertices[0].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[1].vPosition = _float3(0.1f, 0.1f, -0.1f);
	pVertices[1].vTexUV = _float3(1.f, 1.f, -1.f);
	pVertices[1].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[2].vPosition = _float3(0.1f, -0.1f, -0.1f);
	pVertices[2].vTexUV = _float3(1.f, -1.f, -1.f);
	pVertices[2].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[3].vPosition = _float3(-0.1f, -0.1f, -0.1f);
	pVertices[3].vTexUV = _float3(-1.f, -1.f, -1.f);
	pVertices[3].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[4].vPosition = _float3(-0.1f, 0.1f, 0.1f);
	pVertices[4].vTexUV = _float3(-1.f, 1.f, -1.f);
	pVertices[4].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[5].vPosition = _float3(0.1f, 0.1f, 0.1f);
	pVertices[5].vTexUV = _float3(1.f, 1.f, -1.f);
	pVertices[5].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[6].vPosition = _float3(0.1f, -0.1f, 0.1f);
	pVertices[6].vTexUV = _float3(1.f, -1.f, -1.f);
	pVertices[6].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[7].vPosition = _float3(-0.1f, -0.1f, 0.1f);
	pVertices[7].vTexUV = _float3(-1.f, -1.f, -1.f);
	pVertices[7].vNormal = _Normal;

	//¸öÅë
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[8].vPosition = _float3(-0.1f, 0.1f, 0.1f);
	pVertices[8].vTexUV = _float3(-1.f, 1.f, -1.f);
	pVertices[8].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[9].vPosition = _float3(0.1f, 0.1f, 0.1f);
	pVertices[9].vTexUV = _float3(1.f, 1.f, -1.f);
	pVertices[9].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[10].vPosition = _float3(0.1f, -0.1f, 0.1f);
	pVertices[10].vTexUV = _float3(1.f, -1.f, -1.f);
	pVertices[10].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[11].vPosition = _float3(-0.1f, -0.1f, 0.1f);
	pVertices[11].vTexUV = _float3(-1.f, -1.f, -1.f);
	pVertices[11].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[12].vPosition = _float3(-0.1f, 0.1f, 0.5f);
	pVertices[12].vTexUV = _float3(-1.f, 1.f, -1.f);
	pVertices[12].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[13].vPosition = _float3(0.1f, 0.1f, 0.5f);
	pVertices[13].vTexUV = _float3(1.f, 1.f, -1.f);
	pVertices[13].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[14].vPosition = _float3(0.1f, -0.1f, 0.5f);
	pVertices[14].vTexUV = _float3(1.f, -1.f, -1.f);
	pVertices[14].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[15].vPosition = _float3(-0.1f, -0.1f, 0.5f);
	pVertices[15].vTexUV = _float3(-1.f, -1.f, -1.f);
	pVertices[15].vNormal = _Normal;
	
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

	pIndices[4]._0 = 4;
	pIndices[4]._1 = 5;
	pIndices[4]._2 = 1;

	pIndices[5]._0 = 4;
	pIndices[5]._1 = 1;
	pIndices[5]._2 = 0;

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

	//¸öÅë
	pIndices[10]._0 = 11;
	pIndices[10]._1 = 10;
	pIndices[10]._2 = 14;

	pIndices[11]._0 = 11;
	pIndices[11]._1 = 14;
	pIndices[11]._2 = 15;

	pIndices[12]._0 = 9;
	pIndices[12]._1 = 13;
	pIndices[12]._2 = 14;

	pIndices[13]._0 = 9;
	pIndices[13]._1 = 14;
	pIndices[13]._2 = 10;

	pIndices[14]._0 = 13;
	pIndices[14]._1 = 12;
	pIndices[14]._2 = 15;

	pIndices[15]._0 = 13;
	pIndices[15]._1 = 15;
	pIndices[15]._2 = 14;

	pIndices[16]._0 = 12;
	pIndices[16]._1 = 8;
	pIndices[16]._2 = 11;

	pIndices[17]._0 = 12;
	pIndices[17]._1 = 11;
	pIndices[17]._2 = 15;

	pIndices[18]._0 = 12;
	pIndices[18]._1 = 13;
	pIndices[18]._2 = 9;

	pIndices[19]._0 = 12;
	pIndices[19]._1 = 9;
	pIndices[19]._2 = 8;
	
	m_pIB->Unlock();
	return S_OK;
}

HRESULT CVIBuffer_Timber::NativeConstruct(void * pArg)
{
	if (FAILED(__super::NativeConstruct(pArg)))
		return E_FAIL;

	return S_OK;
}

CVIBuffer_Timber * CVIBuffer_Timber::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CVIBuffer_Timber*	pInstance = new CVIBuffer_Timber(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Timber"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CVIBuffer_Timber::Clone(void * pArg)
{
	CVIBuffer_Timber*	pInstance = new CVIBuffer_Timber(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Timber"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CVIBuffer_Timber::Free()
{
	__super::Free();
}
