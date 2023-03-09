#include "..\Public\Object_Manager.h"
#include "GameObject.h"
#include "Layer.h"
#include "Transform.h"
#include "Status.h"

IMPLEMENT_SINGLETON(CObject_Manager)

CObject_Manager::CObject_Manager()
{
}

CComponent * CObject_Manager::Get_Component(_uint iLevelIndex, const _tchar * pLayerTag, const _tchar * pComponentTag, _uint iIndex)
{
	if (iLevelIndex >= m_iNumLevels)
		return nullptr;

	CLayer*		pLayer = Find_Layer(iLevelIndex, pLayerTag);
	if (nullptr == pLayer)
		return nullptr;

	return pLayer->Get_Component(pComponentTag, iIndex);
}

HRESULT CObject_Manager::Reserve_Manager(_uint iNumLevels)
{
	if (0 != m_iNumLevels)
		return E_FAIL;

	m_pLayers = new LAYERS[iNumLevels];

	m_iNumLevels = iNumLevels;

	return S_OK;
}

HRESULT CObject_Manager::Add_Prototype(const _tchar * pPrototypeTag, CGameObject * pPrototype)
{
	if (nullptr == pPrototype)
		return E_FAIL;

	if (nullptr != Find_Prototype(pPrototypeTag))
		return S_OK;

	m_Prototypes.insert(PROTOTYPES::value_type(pPrototypeTag, pPrototype));

	return S_OK;
}

HRESULT CObject_Manager::Add_GameObjectToLayer(_uint iLevelIndex, const _tchar * pLayerTag, const _tchar * pPrototypeTag, void* pArg)
{
	CGameObject*	pPrototype = Find_Prototype(pPrototypeTag);
	if (nullptr == pPrototype)
		return E_FAIL;

	CGameObject*	pGameObject = pPrototype->Clone(pArg);
	if (nullptr == pGameObject)
		return E_FAIL;

	CLayer*	pLayer = Find_Layer(iLevelIndex, pLayerTag);

	if (nullptr == pLayer)
	{
		pLayer = CLayer::Create();
		if (nullptr == pLayer)
			return E_FAIL;

		if (FAILED(pLayer->Add_GameObject(pGameObject)))
			return E_FAIL;

		m_pLayers[iLevelIndex].insert(LAYERS::value_type(pLayerTag, pLayer));
	}
	else
		pLayer->Add_GameObject(pGameObject);

	return S_OK;
}

void CObject_Manager::Tick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pLayers[i])
		{
			Pair.second->Tick(fTimeDelta);
		}
	}
}

void CObject_Manager::LateTick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pLayers[i])
		{
			Pair.second->LateTick(fTimeDelta);
		}
	}
}

HRESULT CObject_Manager::Clear(_uint iLevelIndex)
{
	if (iLevelIndex >= m_iNumLevels)
		return E_FAIL;

	for (auto& Pair : m_pLayers[iLevelIndex])
		Safe_Release(Pair.second);

	m_pLayers[iLevelIndex].clear();

	return S_OK;
}

_bool CObject_Manager::Collison_Sheare(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag)
{
	CLayer* _DistLayer = Find_Layer(iLevelIndex, pDistLayerTag);
	CLayer* _TargetLayer = Find_Layer(iLevelIndex, pTargetLayerTag);

	if (_DistLayer == nullptr || _TargetLayer == nullptr)
		return false;

	list<CGameObject*>* _DistObjList = _DistLayer->Get_ObjList();
	list<CGameObject*>* _TargeObjList = _TargetLayer->Get_ObjList();

	for (auto& dist : *_DistObjList) {
		if (dist->Get_CullingState() == true)
			continue;
		CTransform* _distTransform = (CTransform*)dist->Get_Component(L"Com_Transform");
		_float3 _distPos = _distTransform->Get_State(CTransform::STATE_POSITION);

		for (auto& target : *_TargeObjList) {
			if (target->Get_CullingState() == true)
				continue;
			if (dist == target)
				continue;
			CTransform* _targetTransform = (CTransform*)target->Get_Component(L"Com_Transform");
			_float3 _targetPos = _targetTransform->Get_State(CTransform::STATE_POSITION);

			_float _gap = fabs(D3DXVec3Length(&(_targetPos - _distPos)));

			if (_gap < dist->Get_Col_Range() + target->Get_Col_Range()) {
				KnuckBack(_distTransform, _targetTransform, (dist->Get_Col_Range() + target->Get_Col_Range()) / _gap);
				return true;
			}
		}
	}

	return false;
}

_bool CObject_Manager::Collison_Knockback(_uint iLevelIndex, const _tchar * pDistLayerTag, const _tchar * pTargetLayerTag)
{
	CLayer* _DistLayer = Find_Layer(iLevelIndex, pDistLayerTag);
	CLayer* _TargetLayer = Find_Layer(iLevelIndex, pTargetLayerTag);
	_float3 Pos = _float3{ 0.f,0.f, 0.f };
	if (_DistLayer == nullptr || _TargetLayer == nullptr)
		return false;

	list<CGameObject*>* _DistObjList = _DistLayer->Get_ObjList();
	list<CGameObject*>* _TargeObjList = _TargetLayer->Get_ObjList();

	for (auto& dist : *_DistObjList) {
		if (dist->Get_CullingState() == true)
			continue;
		CStatus* _distStatus = (CStatus*)dist->Get_Component(L"Com_Status");
		_float3 _distPos = _distStatus->m_Status.Transform_Com->Get_State(CTransform::STATE_POSITION);

		for (auto& target : *_TargeObjList) {
			if (target->Get_CullingState() == true)
				continue;
			if (dist == target)
				continue;
			CStatus* _targetStatus = (CStatus*)target->Get_Component(L"Com_Status");
			_float3 _targetPos = _targetStatus->m_Status.Transform_Com->Get_State(CTransform::STATE_POSITION);

			_float _gap = fabs(D3DXVec3Length(&(_targetPos - _distPos)));

			if (_gap <_distStatus->m_Status.frange && *(_targetStatus->Get_pHp()) > 0.f)
			{
				if (_distStatus->m_Status.Attacktype == CStatus::ATTACK_PUSH)
				{
					_distStatus->Set_Damage(CStatus::ATTACK_DEFAULT, 1.f);

					Pos = _distStatus->m_Status.Transform_Com->Get_State(CTransform::STATE_LOOK);

					_targetStatus->Set_Damage(_distStatus->m_Status.Attacktype, _distStatus->m_Status.fDamage, _distStatus->m_Status.fPower, Pos);
					return true;
				}
				else if (_distStatus->m_Status.Attacktype == CStatus::ATTACK_KNOCKBACK)
				{
					_distStatus->Set_Damage(CStatus::ATTACK_DEFAULT, 1.f);
					Pos = _targetPos - _distPos;
					Pos.y = _distPos.y;
					_targetStatus->Set_Damage(_distStatus->m_Status.Attacktype, _distStatus->m_Status.fDamage, _distStatus->m_Status.fPower, Pos);
					return true;
				}

			}
		}
		_distStatus->Set_Dead();



	}

	return false;
}


void CObject_Manager::KnuckBack(CTransform* _MyTrans, CTransform* _YouTrans, _float _KnuckBackPower)
{
	_float3 _mypos = _MyTrans->Get_State(CTransform::STATE_POSITION);
	_float3 _youpos = _YouTrans->Get_State(CTransform::STATE_POSITION);
	_float3 vDir = _youpos - _mypos;
	D3DXVec3Normalize(&vDir, &vDir);

	vDir *= -_KnuckBackPower / 50.f;
	_mypos += vDir;

	_MyTrans->Set_State(CTransform::STATE_POSITION, _mypos);
}

_bool CObject_Manager::Collison_Rect(_uint iLevelIndex, const _tchar * pDistLayerTag, const _tchar * pTargetLayerTag)
{
	float		fWidth, fHeight;
	_bool flag = false;
	CLayer* _DistLayer = Find_Layer(iLevelIndex, pDistLayerTag);
	CLayer* _TargetLayer = Find_Layer(iLevelIndex, pTargetLayerTag);

	if (_DistLayer == nullptr || _TargetLayer == nullptr)
		return false;

	list<CGameObject*>* _DistObjList = _DistLayer->Get_ObjList();
	list<CGameObject*>* _TargeObjList = _TargetLayer->Get_ObjList();



	for (auto& DestIter : *_DistObjList)
	{
		CTransform* _distTransform = (CTransform*)DestIter->Get_Component(L"Com_Transform");
		_float3 _distPos = _distTransform->Get_State(CTransform::STATE_POSITION);

		_float3 temp = _distPos;

		for (auto& SrcIter : *_TargeObjList)
		{
			CTransform* _targetTransform = (CTransform*)SrcIter->Get_Component(L"Com_Transform");
			_float3 _targetPos = _targetTransform->Get_State(CTransform::STATE_POSITION);
			_float _gap = fabs(D3DXVec3Length(&(_targetPos - _distPos)));
			if (_gap < SrcIter->Get_Col_Size().x)
			{
				if (Check_Rect(DestIter, SrcIter, &fWidth, &fHeight))
				{
					// 상하 충돌
					if (fWidth > fHeight)
					{
						// 하 충돌
						if (_distPos.z > _targetPos.z) {
							temp.z += fHeight;

						}
						// 상 충돌
						else {
							temp.z -= fHeight;
						}
					}
					// 좌우 충돌
					else
					{
						// 우 충돌
						if (_distPos.x > _targetPos.x) {
							temp.x += fWidth;
						}
						// 상 충돌
						else {
							temp.x -= fWidth;
						}
					}
					flag = true;
				}
			}
		}
		_distTransform->Set_State(CTransform::STATE_POSITION, temp);
	}

	return false;
}

_bool CObject_Manager::Check_Rect(CGameObject * pDest, CGameObject * pSrc, _float * _pX, _float * _pY)
{
	CTransform* DestTrans = (CTransform*)pDest->Get_Component(L"Com_Transform");
	CTransform* SrcTrans = (CTransform*)pSrc->Get_Component(L"Com_Transform");
	_float3 DestPos = DestTrans->Get_State(CTransform::STATE_POSITION);
	_float3 SrcPos = SrcTrans->Get_State(CTransform::STATE_POSITION);

	float		fWidth = abs(DestPos.x - SrcPos.x);
	float		fHeight = abs(DestPos.z - SrcPos.z);

	// float		fCX = pDest->Get_Info().fCX / 2.f + pSrc->Get_Info().fCX / 2.f;
	// 위의 식을 아래 식으로 변경했을 뿐
	float		fCX = (pDest->Get_Col_Size().x + pSrc->Get_Col_Size().x) * 0.5f;
	float		fCY = (pDest->Get_Col_Size().y + pSrc->Get_Col_Size().y) * 0.5f;

	if (fCX > fWidth && fCY > fHeight)
	{
		*_pX = fCX - fWidth;
		*_pY = fCY - fHeight;

		return true;
	}
	return false;
}

_bool CObject_Manager::SuperCheck_Rect(_float3 DestPos, _float2 _boxPos, _float * _pX, _float * _pY)
{

	float		fWidth = abs(DestPos.x - _boxPos.x);
	float		fHeight = abs(DestPos.z - _boxPos.y);

	float		fCX = 1.f;
	float		fCY = 1.f;

	if (fCX > fWidth && fCY > fHeight)
	{
		*_pX = fCX - fWidth;
		*_pY = fCY - fHeight;

		return true;
	}
	return false;
}


_bool CObject_Manager::SuperCollison_Rect(_uint iLevelIndex, const _tchar * pDistLayerTag, vector<_float2> _BoxsPos[80][80])
{
	float		fWidth, fHeight;
	_bool flag = false;
	CLayer* _DistLayer = Find_Layer(iLevelIndex, pDistLayerTag);

	if (_DistLayer == nullptr)
		return false;

	list<CGameObject*>* _DistObjList = _DistLayer->Get_ObjList();

	for (auto& DestIter : *_DistObjList) {
		if (DestIter->Get_CullingState() == true)
			continue;

		CTransform* _distTransform = (CTransform*)DestIter->Get_Component(L"Com_Transform");
		_float3 _distPos = _distTransform->Get_State(CTransform::STATE_POSITION);

		_float3 temp = _distPos;

		for (auto& iter : _BoxsPos[(_uint)_distPos.x][(_uint)_distPos.z]) {
			if (SuperCheck_Rect(_distPos, iter, &fWidth, &fHeight)) {
				// 상하 충돌
				if (fWidth > fHeight)
				{
					// 하 충돌
					if (_distPos.z > iter.y) {
						temp.z += fHeight;

					}
					// 상 충돌
					else {
						temp.z -= fHeight;
					}
				}
				// 좌우 충돌
				else
				{
					// 우 충돌
					if (_distPos.x > iter.x) {
						temp.x += fWidth;
					}
					// 상 충돌
					else {
						temp.x -= fWidth;
					}
				}
				flag = true;
			}
		}

		_distTransform->Set_State(CTransform::STATE_POSITION, temp);
	}

	return flag;
}

_bool CObject_Manager::Check_EmptyLayer(_uint iLevelIndex, const _tchar * pLayerTag)
{
	CLayer* temp = Find_Layer(iLevelIndex, pLayerTag);
	if (temp == nullptr)
		return false;

	list<CGameObject*>* _objlist = temp->Get_ObjList();
	if ((*_objlist).empty()) {
		return true;
	}

	return false;
}

CGameObject * CObject_Manager::Find_Prototype(const _tchar * pPrototypeTag)
{
	auto	iter = find_if(m_Prototypes.begin(), m_Prototypes.end(), CTagFinder(pPrototypeTag));
	if (iter == m_Prototypes.end())
		return nullptr;

	return iter->second;
}

CLayer * CObject_Manager::Find_Layer(_uint iLevelIndex, const _tchar * pLayerTag)
{
	if (iLevelIndex >= m_iNumLevels)
		return nullptr;

	auto	iter = find_if(m_pLayers[iLevelIndex].begin(), m_pLayers[iLevelIndex].end(), CTagFinder(pLayerTag));
	if (iter == m_pLayers[iLevelIndex].end())
		return nullptr;

	return iter->second;
}

void CObject_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pLayers[i])
			Safe_Release(Pair.second);
		m_pLayers[i].clear();
	}
	Safe_Delete_Array(m_pLayers);

	for (auto& Pair : m_Prototypes)
		Safe_Release(Pair.second);

	m_Prototypes.clear();
}
