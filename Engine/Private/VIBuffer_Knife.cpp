#include "..\Public\VIBuffer_Knife.h"



CVIBuffer_Knife::CVIBuffer_Knife(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CVIBuffer(pGraphic_Device)
{
}

CVIBuffer_Knife::CVIBuffer_Knife(const CVIBuffer_Knife & rhs)
	:CVIBuffer(rhs)
{
}

HRESULT CVIBuffer_Knife::NativeConstruct_Prototype()
{
	if (FAILED(__super::NativeConstruct_Prototype()))
		return E_FAIL;

	m_iNumVertices = 24;
	m_iStride = sizeof(VTXCUBETEX);

	m_dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);
	m_ePrimitiveType = D3DPT_TRIANGLELIST;
	m_iNumPrimitives = 32;

	if (FAILED(Create_VertexBuffer()))
		return E_FAIL;

	VTXCUBETEX*		pVertices = nullptr;



	m_pVB->Lock(0, 0/*m_iStride * m_iNumVertices*/, (void**)&pVertices, 0);

	//손잡이
	_float3 _Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[0].vPosition = _float3(-0.06f, 0.06f, -0.06f);
	pVertices[0].vTexUV = pVertices[0].vPosition;
	pVertices[0].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[1].vPosition = _float3(0.06f, 0.06f, -0.06f);
	pVertices[1].vTexUV = pVertices[1].vPosition;
	pVertices[1].vNormal = _Normal;

	_Normal = (_float3(+1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[2].vPosition = _float3(0.06f, -0.06f, -0.06f);
	pVertices[2].vTexUV = pVertices[2].vPosition;
	pVertices[2].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[3].vPosition = _float3(-0.06f, -0.06f, -0.06f);
	pVertices[3].vTexUV = pVertices[3].vPosition;
	pVertices[3].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[4].vPosition = _float3(-0.06f, 0.06f, 0.1f);
	pVertices[4].vTexUV = pVertices[4].vPosition;
	pVertices[4].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[5].vPosition = _float3(0.06f, 0.06f, 0.1f);
	pVertices[5].vTexUV = pVertices[5].vPosition;
	pVertices[5].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[6].vPosition = _float3(0.06f, -0.06f, 0.1f);
	pVertices[6].vTexUV = pVertices[6].vPosition;
	pVertices[6].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[7].vPosition = _float3(-0.06f, -0.06f, 0.1f);
	pVertices[7].vTexUV = pVertices[7].vPosition;
	pVertices[7].vNormal = _Normal;

	

	//몸통
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[8].vPosition = _float3(-0.03f, 0.1f, 0.12f);
	pVertices[8].vTexUV = pVertices[8].vPosition;
	pVertices[8].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[9].vPosition = _float3(0.03f, 0.1f, 0.12f);
	pVertices[9].vTexUV = pVertices[9].vPosition;
	pVertices[9].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[10].vPosition = _float3(0.001f, -0.1f, 0.12f);
	pVertices[10].vTexUV = pVertices[10].vPosition;
	pVertices[10].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f)) / 2.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[11].vPosition = _float3(-0.001f, -0.1f, 0.12f);
	pVertices[11].vTexUV = pVertices[11].vPosition;
	pVertices[11].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[12].vPosition = _float3(-0.01f, 0.1f, 0.5f);
	pVertices[12].vTexUV = pVertices[12].vPosition;
	pVertices[12].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[13].vPosition = _float3(0.01f, 0.1f, 0.5f);
	pVertices[13].vTexUV = pVertices[13].vPosition;
	pVertices[13].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[14].vPosition = _float3(0.001f, -0.1f, 0.4f);
	pVertices[14].vTexUV = pVertices[14].vPosition;
	pVertices[14].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[15].vPosition = _float3(-0.001f, -0.1f, 0.4f);
	pVertices[15].vTexUV = pVertices[15].vPosition;
	pVertices[15].vNormal = _Normal;

	//중간부분
	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[16].vPosition = _float3(-0.15f, 0.15f, 0.1f);
	pVertices[16].vTexUV = pVertices[16].vPosition;
	pVertices[16].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[17].vPosition = _float3(0.15f, 0.15f, 0.1f);
	pVertices[17].vTexUV = pVertices[17].vPosition;
	pVertices[17].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[18].vPosition = _float3(0.15f, -0.15f, 0.1f);
	pVertices[18].vTexUV = pVertices[18].vPosition;
	pVertices[18].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, -1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[19].vPosition = _float3(-0.15f, -0.15f, 0.1f);
	pVertices[19].vTexUV = pVertices[19].vPosition;
	pVertices[19].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[20].vPosition = _float3(-0.15f, 0.15f, 0.12f);
	pVertices[20].vTexUV = pVertices[20].vPosition;
	pVertices[20].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, 1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[21].vPosition = _float3(0.15f, 0.15f, 0.12f);
	pVertices[21].vTexUV = pVertices[21].vPosition;
	pVertices[21].vNormal = _Normal;

	_Normal = (_float3(1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[22].vPosition = _float3(0.15f, -0.15f, 0.12f);
	pVertices[22].vTexUV = pVertices[22].vPosition;
	pVertices[22].vNormal = _Normal;

	_Normal = (_float3(-1.f, 0.f, 0.f) + _float3(0.f, -1.f, 0.f) + _float3(0.f, 0.f, 1.f)) / 3.f;
	D3DXVec3Normalize(&_Normal, &_Normal);
	pVertices[23].vPosition = _float3(-0.15f, -0.15f, 0.12f);
	pVertices[23].vTexUV = pVertices[23].vPosition;
	pVertices[23].vNormal = _Normal;


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

	//몸통
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

	//중간부분
	pIndices[20]._0 = 16;
	pIndices[20]._1 = 17;
	pIndices[20]._2 = 18;

	pIndices[21]._0 = 16;
	pIndices[21]._1 = 18;
	pIndices[21]._2 = 19;

	pIndices[22]._0 = 17;
	pIndices[22]._1 = 21;
	pIndices[22]._2 = 22;

	pIndices[23]._0 = 17;
	pIndices[23]._1 = 22;
	pIndices[23]._2 = 18;
				 
	pIndices[24]._0 = 21;
	pIndices[24]._1 = 20;
	pIndices[24]._2 = 23;
				 
	pIndices[25]._0 = 21;
	pIndices[25]._1 = 23;
	pIndices[25]._2 = 22;
				 
	pIndices[26]._0 = 20;
	pIndices[26]._1 = 16;
	pIndices[26]._2 = 19;
				 
	pIndices[27]._0 = 20;
	pIndices[27]._1 = 19;
	pIndices[27]._2 = 23;
				 
	pIndices[28]._0 = 20;
	pIndices[28]._1 = 21;
	pIndices[28]._2 = 17;
				 
	pIndices[29]._0 = 20;
	pIndices[29]._1 = 17;
	pIndices[29]._2 = 16;

	pIndices[30]._0 = 19;
	pIndices[30]._1 =18;
	pIndices[30]._2 = 22;

	pIndices[31]._0 = 19;
	pIndices[31]._1 = 22;
	pIndices[31]._2 = 23;

	m_pIB->Unlock();
	return S_OK;
}

HRESULT CVIBuffer_Knife::NativeConstruct(void * pArg)
{
	if (FAILED(__super::NativeConstruct(pArg)))
		return E_FAIL;

	return S_OK;
}

CVIBuffer_Knife * CVIBuffer_Knife::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CVIBuffer_Knife*	pInstance = new CVIBuffer_Knife(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Knife"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CVIBuffer_Knife::Clone(void * pArg)
{
	CVIBuffer_Knife*	pInstance = new CVIBuffer_Knife(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CVIBuffer_Knife"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CVIBuffer_Knife::Free()
{
	__super::Free();
}
