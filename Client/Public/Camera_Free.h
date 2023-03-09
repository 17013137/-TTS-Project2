#pragma once

#include "Client_Defines.h"
#include "Camera.h"
#include "EventMgr.h"

BEGIN(Client)

class CCamera_Free final : public CCamera
{
private:
	explicit CCamera_Free(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CCamera_Free(const CCamera_Free& rhs);
	virtual ~CCamera_Free() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

	void Event_Scean0(_float fTimeDelta);
	void Event_Scean1(_float fTimeDelta);


private:
	CEventMgr* m_pEventmgr = nullptr;

public:
	static CCamera_Free* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END