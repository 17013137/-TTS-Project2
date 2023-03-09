#pragma once

#include "Base.h"

/*1. 내 게임에 사용될 객체(사본)들을 보관하고 관리한다. */
/*2. 원형객체들을 보관한다. */
/*3. 사본객체들의 갱신을 담당한다.(Tick함수호출) */

BEGIN(Engine)
class CTransform;
class CObject_Manager final : public CBase
{
	DECLARE_SINGLETON(CObject_Manager)
private:
	CObject_Manager();
	virtual ~CObject_Manager() = default;

public:
	class CComponent* Get_Component(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pComponentTag, _uint iIndex = 0);

public:
	HRESULT Reserve_Manager(_uint iNumLevels);
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype);
	HRESULT Add_GameObjectToLayer(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pPrototypeTag, void* pArg);
	void Tick(_float fTimeDelta);
	void LateTick(_float fTimeDelta);
	HRESULT Clear(_uint iLevelIndex);

public:
	_bool Collison_Sheare(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	_bool Collison_Knockback(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	void KnuckBack(CTransform* _MyTrans, CTransform* _YouTrans, _float _KnuckBackPower);
	_bool Collison_Rect(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	_bool Check_Rect(CGameObject* pDest, CGameObject* pSrc, _float* _pX, _float* _pY);

	_bool SuperCollison_Rect(_uint iLevelIndex, const _tchar* pDistLayerTag, vector<_float2> _BoxsPos[80][80]);
	_bool SuperCheck_Rect(_float3 pDest, _float2 _boxPos, _float* _pX, _float* _pY);

public:
	_bool Check_EmptyLayer(_uint iLevelIndex, const _tchar* pLayerTag);

private:
	/* 원형객체들을 보관한다. */
	map<const _tchar*, class CGameObject*>			m_Prototypes;
	typedef map<const _tchar*, class CGameObject*>	PROTOTYPES;


private:
	/* 사본객체들을 레이어로구분(니 맘대로)하여 보관한다.  */
	map<const _tchar*, class CLayer*>*				m_pLayers = nullptr;
	typedef map<const _tchar*, class CLayer*>		LAYERS;

private:
	_uint			m_iNumLevels = 0;

private:

	class CGameObject* Find_Prototype(const _tchar* pPrototypeTag);
	class CLayer* Find_Layer(_uint iLevelIndex, const _tchar* pLayerTag);

public:
	virtual void Free() override;
};

END