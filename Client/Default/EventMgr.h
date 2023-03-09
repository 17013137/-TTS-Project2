#pragma once

#include "Client_Defines.h"
#include "GameInstance.h"

typedef struct ActorInfo {
	_tchar ActorTag[MAX_PATH] = L"";
	_float3 ActorPos;
	_bool Acting = false;
}ACTORINFO;


class CEventMgr
{


public:
	CEventMgr();
	~CEventMgr();

public:
	static CEventMgr*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CEventMgr;

		return m_pInstance;
	}
	static void			Destroy_Instance(void)
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void Initialize(int _LevelName, CTransform* _CameraTrnas);
	void Release();
	void Tick(_float fTimeDelta);

public:
	bool Get_OnAir() { return m_OnAir; }
	void Set_OnAir() { m_OnAir = true; }
	void Set_OffAir() { m_OnAir = false; }
	ACTORINFO* Get_ActorInfo(_int _cnt) { return &m_Actor[_cnt]; }
	_bool Get_isInitSet(_int _cnt) { return isInitSet[_cnt]; }
	void Set_isInitSet(_int _cnt, _bool _b);
	_bool Get_Next(_int _cnt) { return m_Next[_cnt]; }
	void Set_NextSet(_int _cnt, _bool _b) { m_Next[_cnt] = _b; }
	void Add_EventCnt() { m_EventCnt++; }
	_int Get_EventCnt() { return m_EventCnt; }
	void Add_SceanCnt() { m_SceneCnt++; }
	_int Get_SceanCnt() { return m_SceneCnt; }
	void Add_TotalSceanCnt() { m_TotalScene++; }
	_int Get_TotalScean() { return m_TotalScene; }
	_bool Get_OnCredit() { return m_OnCredit; }
	void Set_OnCredit() {  m_OnCredit = true; }
	_int Get_LoadingNum() { return m_iLoadingNum; }
	void Set_LoadingNum() { m_iLoadingNum++; }

	_float Get_Time() { return m_Time; }
	void Add_Time(_float fTimeDelta) { m_Time += fTimeDelta; }
public:
	HRESULT Ready_Scean(const _tchar* LayerTag);
	void Off_Air();

public:
	void Add_MaxLevel();
	const int& Get_MaxLevel() { return maxStage; }

private:
	CTransform* m_pCameraTrans = nullptr;

	_float4x4 m_SaveCamera;
	ACTORINFO m_Actor[10];
	_int m_ActorCnt = 0;
	int m_EventCnt = -1;
	int m_SceneCnt = 0;
	int m_TotalScene = 0;
	_bool m_OnAir = false;
	_bool m_OnCredit = false;
	_bool isInitSet[10] = { false };
	_bool m_Next[10] = { false };
	int m_iLevelNum = 0;
	_int m_iLoadingNum = 0;
	_float m_Time = 0.f;
private:
	int maxStage = 1;

private:
	static		CEventMgr*	m_pInstance;
};

