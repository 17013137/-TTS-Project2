#include "..\Public\Component_Manager.h"

IMPLEMENT_SINGLETON(CComponent_Manager)

CComponent_Manager::CComponent_Manager()
{
}



HRESULT CComponent_Manager::Reserve_Manager(_uint iNumLevels)
{
	if (0 != m_iNumLevels)
		return E_FAIL;

	m_pPrototypes = new PROTOTYPES[iNumLevels];

	m_iNumLevels = iNumLevels;

	return S_OK;
}

HRESULT CComponent_Manager::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (nullptr == m_pPrototypes)
		return E_FAIL;
	if (nullptr != Find_Prototype(iLevelIndex, pPrototypeTag))
		return S_OK;

	m_pPrototypes[iLevelIndex].insert(PROTOTYPES::value_type(pPrototypeTag, pPrototype));	

	return S_OK;
}

CComponent * CComponent_Manager::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	if (nullptr == m_pPrototypes)
		return nullptr;

	/*  원형ㅇ르 찾느낟. */
	CComponent*		pPrototype = Find_Prototype(iLevelIndex, pPrototypeTag);
	if (nullptr == pPrototype)
		return nullptr;

	/* 원형을 복제하여 사본을 마느단ㄷ.ㅏ . */
	return pPrototype->Clone(pArg);	
}

HRESULT CComponent_Manager::Set_TextureCom(_uint TexLevelIndex, const _tchar * _RendererTag, const _tchar * CloneCubeTexTag, const _tchar * CloneTileTexTag)
{
	CRenderer* cloneRenderer = (CRenderer*)Clone_Component(0, _RendererTag, 0);
	CTexture* cloneCubeTex = (CTexture*)Clone_Component(TexLevelIndex, CloneCubeTexTag, 0);
	CTexture* cloneTileTex = (CTexture*)Clone_Component(TexLevelIndex, CloneTileTexTag, 0);

	if (cloneRenderer == nullptr || cloneCubeTex == nullptr || cloneTileTex == nullptr)
		return E_FAIL;

	cloneRenderer->Set_TextureCom(cloneCubeTex, cloneTileTex);

	return S_OK;
}

CComponent * CComponent_Manager::Find_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag)
{
	auto	iter = find_if(m_pPrototypes[iLevelIndex].begin(), m_pPrototypes[iLevelIndex].end(), CTagFinder(pPrototypeTag));
	if (iter == m_pPrototypes[iLevelIndex].end())
		return nullptr;

	return iter->second;	
}


void CComponent_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pPrototypes[i])
		{
			Safe_Release(Pair.second);
		}
		m_pPrototypes[i].clear();
	}

	Safe_Delete_Array(m_pPrototypes);
}
