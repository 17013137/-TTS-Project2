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
	HRESULT SetUp_CameraMoveToMouse();//3��Ī���� ���콺�� ���� �÷��̾ ������

private:
	void Boss_Event_Scean(_float fTimeDelta);
	void Stage_Event_Scean(_float fTimeDelta);

private:
	_float3 ThirdPos = { 0.f, 16.f, -15.f };
	_bool ReturnView = false;
	_float3 m_vMousePos;
	_float fRadius; // �÷��̾�� ���콺 ������ �Ÿ�
	CEventMgr* m_pEventmgr = nullptr;
	_float m_Time = 0.f;

public:
	static CCamera_Default* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END