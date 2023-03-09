#pragma once

#include "Client_Defines.h"
#include "Base.h"

/* 레벨별로 로딩해야할 리소스 생성한다.(스레드로)  */

BEGIN(Client)

class CLoader final : public CBase
{
private:
	explicit CLoader(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLoader() = default;

public:
	CRITICAL_SECTION Get_CriticalSection() {
		return m_CriticalSection;
	}

	LEVEL Get_LevelIndex() {
		return m_eLevel;
	}

	_bool Get_Finished() const {
		return m_isFinished;
	}

	const _tchar* Get_LoadingText() const {
		return m_szLoading;
	}

public:
	HRESULT NativeConstruct(LEVEL eLevel);
	HRESULT Loading_ForGamePlayLevel();
	HRESULT Loading_ForBossLevel();
	HRESULT Loading_ForShelterLevel();
	HRESULT Loading_ForForestLevel();
	HRESULT Loading_ForHell();
	HRESULT Loading_ForEventLevel();
	HRESULT Loading_ForStoreLevel();
	HRESULT Loading_ForCave();
	HRESULT Loading_ForCity();

	HRESULT Basic_DataLoad(); //캐릭터 장비, 유아이, 불렛 이펙트 등 모든 레벨에서 보통 쓰는 업로드들

private:
	LEVEL			m_eLevel = LEVEL_END;
	_bool			m_isFinished = false;
	_tchar			m_szLoading[MAX_PATH] = TEXT("");

private:
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;
	HANDLE				m_hThread = 0;
	CRITICAL_SECTION	m_CriticalSection;

public:
	static CLoader* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eLevel);
	virtual void Free() override;
};

END