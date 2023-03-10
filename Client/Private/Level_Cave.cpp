#include "stdafx.h"
#include "Level_Cave.h"

#include "GameInstance.h"
#include "Camera_Default.h"
#include "SoundMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "Level_Loading.h"
CLevel_Cave::CLevel_Cave(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CLevel(pGraphic_Device)
{

}

HRESULT CLevel_Cave::NativeConstruct()
{
	if (FAILED(__super::NativeConstruct()))
		return E_FAIL;

	CSoundMgr::Get_Instance()->StopSound(CSoundMgr::BGM1);
	CSoundMgr::Get_Instance()->StopSound(CSoundMgr::BGM2);

	CSoundMgr::Get_Instance()->PlayBGM(L"bgm_3Low.wav");

	if (FAILED(Ready_Layer_Camera(TEXT("Layer_Camera"))))
		return E_FAIL;

	if (FAILED(Ready_Layer_Player(TEXT("Layer_Player"))))
		return E_FAIL;



	if (FAILED(Ready_Layer_BackGround(TEXT("Layer_BackGround"))))
		return E_FAIL;

	if (FAILED(Ready_Layer_Effect(TEXT("Layer_Effect"))))
		return E_FAIL;

	if (FAILED(Ready_Layer_HitBox(TEXT("Layer_HitBox"))))
		return E_FAIL;

	if (FAILED(Ready_Layer_UI(TEXT("Layer_UI"))))
		return E_FAIL;
	m_pGraphic_Device->LightEnable(0, TRUE);
	m_pGraphic_Device->LightEnable(2, TRUE);
	m_pGraphic_Device->LightEnable(3, FALSE);
	m_pGraphic_Device->LightEnable(4, FALSE);


	Load_Data(L"../../Data/Cave/Object.dat", LEVEL_CAVE);
	//Load_Tile_Data(L"../../Data/Forest/Tile.dat", m_LevelIndex);
	Load_Cube_Data(L"../../Data/Cave/Cube.dat", LEVEL_CAVE);
	CEventMgr::Get_Instance()->Set_OnAir();
	return S_OK;
}

void CLevel_Cave::Tick(_float fTimeDelta)
{
	__super::Tick(fTimeDelta);

	CSoundMgr::Get_Instance()->PlaySound(L"Cave.mp3", CSoundMgr::BGM1, 0.3f);

	CGameInstance* _gameins = CGameInstance::GetInstance();

	//if(SpawDelay<0)
	//	RandomSpawn();

	Safe_AddRef(_gameins);
	//충돌검사할것들
	_gameins->Collison_Sheare(LEVEL_CAVE, L"Layer_Player", L"Monster");
	_gameins->Collison_Sheare(LEVEL_CAVE, L"Monster", L"Monster");
	_gameins->Collison_Sheare(LEVEL_CAVE, L"Monster", L"Layer_Player");
	
	_gameins->Collison_Knockback(LEVEL_CAVE, L"Layer_HitBox", L"Monster");
	_gameins->Collison_Knockback(LEVEL_CAVE, L"Layer_PlayerHitBox", L"Layer_Player");
	_gameins->SuperCollison_Rect(LEVEL_CAVE, L"Layer_Player", BoxsPos);
	_gameins->SuperCollison_Rect(LEVEL_CAVE, L"Monster", BoxsPos);



	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		if (CEventMgr::Get_Instance()->Get_EventCnt() == 1) {
			CEventMgr::Get_Instance()->Add_MaxLevel();
			if (FAILED(_gameins->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, LEVEL_STORE))))
				return;
		}
		else {
			CEventMgr::Get_Instance()->Add_MaxLevel();
			if (FAILED(_gameins->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, LEVEL_SHELTER))))
				return;
		}

		return;
	}

	if (true) {
		CStatus*_GateStatus = (CStatus*)_gameins->Get_Component(m_LevelIndex, L"Gate", L"Com_Status");
		_GateStatus->Set_Damage(CStatus::ATTACK_DEFAULT, 101.f);
		CTransform* _GateTrans = (CTransform*)_gameins->Get_Component(m_LevelIndex, L"Gate", L"Com_Transform");
		_float3 _GatePos = _GateTrans->Get_State(CTransform::STATE_POSITION);
		CTransform* _PlayerTrans = (CTransform*)_gameins->Get_Component(m_LevelIndex, L"Layer_Player", L"Com_Transform");
		_float3 _PlayerPos = _PlayerTrans->Get_State(CTransform::STATE_POSITION);
	
		if (_PlayerPos == nullptr || _GatePos == nullptr)
			return;
	
		_float dist = D3DXVec3Length(&(_GatePos - _PlayerPos));
		if (dist < 3.f)
			if (CKeyMgr::Get_Instance()->Key_Down('T')) {
				if (CEventMgr::Get_Instance()->Get_EventCnt() == 1) {
					CEventMgr::Get_Instance()->Add_MaxLevel();
					if (FAILED(_gameins->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, LEVEL_STORE))))
						return;
				}
				else {
					CEventMgr::Get_Instance()->Add_MaxLevel();
					if (FAILED(_gameins->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, LEVEL_SHELTER))))
						return;
				}
			}
	}

	//SpawDelay -= fTimeDelta;

	CStatus* PlayerState = (CStatus*)_gameins->Get_Component(m_LevelIndex, L"Layer_Player", L"Com_Status");


	if (PlayerState == nullptr) {
		Safe_Release(_gameins);
		return;
	}

	if (PlayerState->Get_State() == 2) {
		if (CKeyMgr::Get_Instance()->Key_Down('T')) {
			if (FAILED(_gameins->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, LEVEL_SHELTER))))
				return;
		}
	}
	
	Safe_Release(_gameins);
}

HRESULT CLevel_Cave::Render()
{
	if (FAILED(__super::Render()))
		return E_FAIL;


	SetWindowText(g_hWnd, TEXT("Cave."));

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_Camera(const _tchar * pLayerTag)
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	CCamera::CAMERADESC			CameraDesc;
	ZeroMemory(&CameraDesc, sizeof(CCamera::CAMERADESC));

	CameraDesc.vEye = _float3(0.f, 10.f, -15.f);
	CameraDesc.vAt = _float3(0.f, 0.f, 0.f);
	CameraDesc.vAxisY = _float3(0.f, 1.f, 0.f);
	CameraDesc.fNear = 0.1f;
	CameraDesc.fFar = 300.0f;
	CameraDesc.fFovy = D3DXToRadian(60.0f);
	CameraDesc.fAspect = (_float)g_iWinCX / g_iWinCY;

	CameraDesc.TransformDesc.fSpeedPerSec = 10.f;
	CameraDesc.TransformDesc.fRotationPerSec = 10.f;
	CameraDesc.TransformDesc.fScalePerSec = 1.f;


	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Camera_Default"), &CameraDesc)))
		return E_FAIL;

	Safe_Release(pGameInstance);

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_Player(const _tchar * pLayerTag)
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	//if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Player"))))
	//	return E_FAIL;

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_PlayerCube"))))
		return E_FAIL;
	CTransform* trans = (CTransform*)pGameInstance->GetInstance()->Get_Component(m_LevelIndex, TEXT("Layer_Player"), TEXT("Com_Transform"));
	trans->Set_State(CTransform::STATE_POSITION, _float3(8.f, 0.6f, 10.f));
	Safe_Release(pGameInstance);

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_BackGround(const _tchar * pLayerTag)
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);
	_uint num = 1;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Terrain"), &num)))
		return E_FAIL;

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Sky"))))
		return E_FAIL;

	Safe_Release(pGameInstance);

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_Effect(const _tchar * pLayerTag)
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);


	Safe_Release(pGameInstance);

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_HitBox(const _tchar * pLayerTag)
{

	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_Monster(const _tchar * pLayerTag)
{

	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);


	//	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_ZombieSpitter"))))
	//		return E_FAIL;



	Safe_Release(pGameInstance);
	return S_OK;
}

HRESULT CLevel_Cave::Ready_Layer_UI(const _tchar * pLayerTag)
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_State_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_HP_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Stamina_UI"))))
		return E_FAIL;

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Pistol_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Rifle_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_ShotGun_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Timber_UI"))))
		return E_FAIL;

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Inventory_UI"))))
		return E_FAIL;
	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Equip_UI"))))
		return E_FAIL;

	if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, pLayerTag, TEXT("Prototype_GameObject_Mouse_UI"))))
		return E_FAIL;



	Safe_Release(pGameInstance);

	return S_OK;
}


HRESULT CLevel_Cave::RandomSpawn()
{
	CGameInstance*		pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);
	_float3 SpawnPos ;
	//while (true)              
	//{
	//	SpawnPos = _float3{ rand() % 60 + 10.f,3.f,rand() % 60 + 10.f };
	//
	//	CTransform*		pTargetTransform = (CTransform*)pGameInstance->Get_Component(m_LevelIndex, TEXT("Layer_Player"), TEXT("Com_Transform"));
	//	
	//	if (D3DXVec3Length(&(SpawnPos - pTargetTransform->Get_State(CTransform::STATE_POSITION))) > 20)
	//		break;
	//}
	
	//if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, TEXT("Monster"), TEXT("Prototype_GameObject_Wither_skeleton"), &SpawnPos)))
	//	return E_FAIL;
	//if (FAILED(pGameInstance->Add_GameObjectToLayer(m_LevelIndex, TEXT("Monster"), TEXT("Prototype_GameObject_Skeleton"), &SpawnPos)))
	//	return E_FAIL;
	//SpawDelay = 0.3f;
	Safe_Release(pGameInstance);
	return S_OK;
}

CLevel_Cave * CLevel_Cave::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CLevel_Cave*	pInstance = new CLevel_Cave(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct()))
	{
		MSG_BOX(TEXT("Failed to Created CLevel_Cave"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLevel_Cave::Free()
{
	__super::Free();

}
