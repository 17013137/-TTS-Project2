#pragma once

#include "Client_Defines.h"
#include "Camera.h"

class CEventMgr;
BEGIN(Client)

class CCamera_Default final : public CCamera
{
private:
	explicit CCamera_Default(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CCamera_Default(const CCamera_Default& rhs);
	virtual ~CCamera_Default() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	HRESULT SetUp_CameraMoveTopView();
	HRESULT SetUp_CameraMoveToMouse();//3인칭에서 마우스에 따라 플레이어가 움직임

private:
	void Boss_Event_Scean(_float fTimeDelta);
	void Stage_Event_Scean(_float fTimeDelta);

private:
	_float3 ThirdPos = { 0.f, 16.f, -15.f };
	_bool ReturnView = false;
	_float3 m_vMousePos;
	_float fRadius; // 플레이어와 마우스 사이의 거리
	CEventMgr* m_pEventmgr = nullptr;
	_float m_Time = 0.f;

public:
	static CCamera_Default* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END