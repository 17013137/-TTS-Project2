#include "..\Public\Layer.h"
#include "GameObject.h"


CLayer::CLayer()
{
}

CComponent * CLayer::Get_Component(const _tchar * pComponentTag, _uint iIndex)
{
	if (iIndex >= m_ObjectList.size())
		return nullptr;

	auto	iter = m_ObjectList.begin();

	for (_uint i = 0; i < iIndex; ++i)
		++iter;

	return (*iter)->Get_Component(pComponentTag);
}

HRESULT CLayer::Add_GameObject(CGameObject * pGameObject)
{
	if (nullptr == pGameObject)
		return E_FAIL;

	m_ObjectList.push_back(pGameObject);

	return S_OK;
}

void CLayer::Tick(_float fTimeDelta)
{
	_int Evnet = 0;

	auto& iter = m_ObjectList.begin();

	for (; iter != m_ObjectList.end(); )
	{
		Evnet = (*iter)->Tick(fTimeDelta);

		if (1 == Evnet)
		{
			Safe_Release(*iter);
			iter = m_ObjectList.erase(iter);
		}
		else
			++iter;
	}

}

void CLayer::LateTick(_float fTimeDelta)
{
	for (auto& pGameObject : m_ObjectList)
		pGameObject->LateTick(fTimeDelta);
}

CLayer * CLayer::Create()
{
	return new CLayer();
}

void CLayer::Free()
{
	for (auto& pGameObject : m_ObjectList)
		Safe_Release(pGameObject);

	m_ObjectList.clear();

}
