#include "stdafx.h"
#include "EventMgr.h"
#include "KeyMgr.h"

CEventMgr* CEventMgr::m_pInstance = nullptr;
CEventMgr::CEventMgr()
{
}


CEventMgr::~CEventMgr()
{
}

void CEventMgr::Initialize(int _LevelName, CTransform* _CameraTrnas)
{
	m_Actor[10];
	ZeroMemory(m_Actor, sizeof(m_Actor));

	m_ActorCnt = 0;
	m_SceneCnt = 0;
	m_OnAir = false;
	m_Time = 0.f;
	isInitSet[10] = { false };
	m_Next[10] = { false };

	m_iLevelNum = _LevelName;
	m_pCameraTrans = _CameraTrnas;
	m_SaveCamera = _CameraTrnas->Get_WorldMatrix();
}

void CEventMgr::Release()
{
}

void CEventMgr::Tick(_float fTimeDelta)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_F8)) {
		if (Get_OnAir() == true)
			Set_OffAir();
		else
			Set_OnAir();
	}

	if (CKeyMgr::Get_Instance()->Key_Down('V')) {
		m_Time = (_float)m_SceneCnt * 5.f;
	}
}

void CEventMgr::Set_isInitSet(_int _cnt, _bool _b)
{
	isInitSet[_cnt] = _b;
	m_SceneCnt++;
	m_TotalScene++;
}


HRESULT CEventMgr::Ready_Scean(const _tchar * LayerTag)
{
	CGameInstance* gameins = CGameInstance::GetInstance();
	Safe_AddRef(gameins);
	CTransform* trans = (CTransform*)gameins->Get_Component(m_iLevelNum, LayerTag, L"Com_Transform");
	Safe_Release(gameins);

	if (trans == nullptr)
		return E_FAIL;
	lstrcpy(m_Actor[m_ActorCnt].ActorTag, LayerTag);
	m_Actor[m_ActorCnt].ActorPos = trans->Get_State(CTransform::STATE_POSITION);
	m_ActorCnt++;


	return S_OK;
}

void CEventMgr::Off_Air()
{
	m_OnAir = false;
	for (int i = 0; i < 10; i++)
		isInitSet[i] = false;
	m_SceneCnt = 0;
	m_Time = 0.f;
	m_ActorCnt = 0;
	m_pCameraTrans->Set_State(CTransform::STATE_RIGHT, _float3(m_SaveCamera._11, m_SaveCamera._12, m_SaveCamera._13));
	m_pCameraTrans->Set_State(CTransform::STATE_UP, _float3(m_SaveCamera._21, m_SaveCamera._22, m_SaveCamera._23));
	m_pCameraTrans->Set_State(CTransform::STATE_LOOK, _float3(m_SaveCamera._31, m_SaveCamera._32, m_SaveCamera._33));
	m_pCameraTrans->Set_State(CTransform::STATE_POSITION, _float3(m_SaveCamera._41, m_SaveCamera._42, m_SaveCamera._43));
}

void CEventMgr::Add_MaxLevel()
{
	if (maxStage < 7)
		maxStage += 2;
	else
		maxStage += 1;
}
