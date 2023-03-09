#pragma once

#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_City final : public CLevel
{
private:
	explicit CLevel_City(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLevel_City() = default;

public:
	virtual HRESULT NativeConstruct() override;
	virtual void Tick(_float fTimeDelta) override;
	virtual HRESULT Render() override;

private:
	HRESULT Ready_Layer_Camera(const _tchar* pLayerTag);
	HRESULT Ready_Layer_Player(const _tchar* pLayerTag);
	HRESULT Ready_Layer_BackGround(const _tchar* pLayerTag);
	HRESULT Ready_Layer_Effect(const _tchar* pLayerTag);
	HRESULT Ready_Layer_HitBox(const _tchar* pLayerTag);
	HRESULT Ready_Layer_Monster(const _tchar* pLayerTag);
	HRESULT Ready_Layer_UI(const _tchar* pLayerTag);
	HRESULT RandomSpawn();
	_float	SpawDelay = 0;

public:
	static CLevel_City* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual void Free() override;
};

END