#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CGameObject abstract : public CBase
{
protected:
	explicit CGameObject(LPDIRECT3DDEVICE9 pGraphic_Device);
	CGameObject(const CGameObject& rhs);
	virtual ~CGameObject() = default;

public:
	class CComponent* Get_Component(const _tchar* pComponentTag) {
		return Find_Component(pComponentTag);
	}

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();
	const _float& Get_Col_Range() { return m_col_Range; }
	const _float2& Get_Col_Size() { return m_col_Size; }
	const _bool& Get_CullingState() { return m_culling; }
protected:
	_float	m_col_Range = 0.f;
	_float2 m_col_Size = _float2{ 0.f, 0.f };
	_bool	m_bWeapon = 0;
	_bool	m_bDead = 0;
	_bool m_bTab = 0;
	_bool	m_bShop = 1;
	_bool  m_culling = false;
	_int m_Current_Level = 0;

protected:
	LPDIRECT3DDEVICE9		m_pGraphic_Device = nullptr;

protected:
	map<const _tchar*, class CComponent*>			m_Components;
	typedef map<const _tchar*, class CComponent*>	COMPONENTS;

protected:
	HRESULT SetUp_Components(const _tchar* pComponentTag, _uint iLevelIndex, const _tchar* pPrototypeTag, CComponent** ppOut, void* pArg = nullptr);

private:
	CComponent* Find_Component(const _tchar* pComponentTag);


public:	
	virtual CGameObject* Clone(void* pArg) = 0;
	virtual void Free() override;
};

END