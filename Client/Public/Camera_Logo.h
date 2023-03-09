#pragma once

#include "Client_Defines.h"
#include "Camera.h"

BEGIN(Client)

class CCamera_Logo final : public CCamera
{
private:
	explicit CCamera_Logo(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CCamera_Logo(const CCamera_Logo& rhs);
	virtual ~CCamera_Logo() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();


public:
	static CCamera_Logo* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END