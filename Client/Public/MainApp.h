#pragma once

#include "Client_Defines.h"
#include "Base.h"

BEGIN(Engine)
class CRenderer;
class CGameInstance;
END

BEGIN(Client)

class CMainApp final : public CBase
{
public:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT NativeConstruct();
	void Tick(float fTimeDelta);
	HRESULT Render();

private:
	CGameInstance*		m_pGameInstance = nullptr;
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;
	CRenderer*			m_pRenderer = nullptr;

public:
	HRESULT Open_Level(LEVEL eLevelIndex);
	HRESULT Ready_Prototype_GameObject();
	HRESULT Ready_Prototype_Component();
	HRESULT SetUp_DefaultRenderState();


public:
	static CMainApp* Create();
	virtual void Free() override;
};

END



