#pragma once

#include "Client_Defines.h"
#include "Level.h"

/* 로딩씬을 보여준다. */
/* . 로더가 로드할수있도록. 로더객체생성 */
/* 로더일을 끝내면 씬 변경. */
BEGIN(Client)

class CLevel_Loading final : public CLevel
{
private:
	explicit CLevel_Loading(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLevel_Loading() = default;

public:
	virtual HRESULT NativeConstruct(LEVEL eNextLevel);
	virtual void Tick(_float fTimeDelta) override;
	virtual HRESULT Render() override;
	
private:
	LEVEL			m_eNextLevel = LEVEL_END;
	class CLoader*	m_pLoader = nullptr;

private:
	RECT		m_rLoading_MSG;

	LPD3DXFONT			m_pd3dxFont;
	
public:
	HRESULT Ready_Layer_BackGround(const _tchar* pLayerTag);
	HRESULT Ready_Layer_Camera(const _tchar* pLayerTag);

public:
	static CLevel_Loading* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevel);
	virtual void Free() override;
};

END