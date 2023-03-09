#pragma once

#include "Client_Defines.h"
#include "Camera.h"
#include "EventMgr.h"

BEGIN(Client)

class CCamera_Shelter final : public CCamera
{
private:
	explicit CCamera_Shelter(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CCamera_Shelter(const CCamera_Shelter& rhs);
	virtual ~CCamera_Shelter() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

public:
	static CCamera_Shelter* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
	void Lookat(_float fTimeDelta);

private:
	_bool Get_PlayerPos();
	/*¾À*/

public:
	void Event_Scean0(_float fTimeDelta);
	void Event_Scean1(_float fTimeDelta);
	void Event_Scean2(_float fTimeDelta);
	void Event_Scean3(_float fTimeDelta);
	void Event_Scean4(_float fTimeDelta);


private:
	_float3 m_PlayerPos;
	CEventMgr* m_pEventmgr = nullptr;
};

END