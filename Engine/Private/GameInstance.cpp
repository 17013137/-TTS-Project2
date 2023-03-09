#include "..\Public\GameInstance.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
	: m_pGraphic_Device(CGraphic_Device::GetInstance())
	, m_pInput_Device(CInput_Device::GetInstance())
	, m_pLevel_Manager(CLevel_Manager::GetInstance())
	, m_pObject_Manager(CObject_Manager::GetInstance())
	, m_pComponent_Manager(CComponent_Manager::GetInstance())
	, m_pTimer_Manager(CTimer_Manager::GetInstance())
	, m_pPicking(CPicking::GetInstance())
	, m_pFrustum(CFrustum::GetInstance())
{
	Safe_AddRef(m_pFrustum);
	Safe_AddRef(m_pPicking);
	Safe_AddRef(m_pTimer_Manager);
	Safe_AddRef(m_pComponent_Manager);
	Safe_AddRef(m_pObject_Manager);
	Safe_AddRef(m_pLevel_Manager);
	Safe_AddRef(m_pInput_Device);
	Safe_AddRef(m_pGraphic_Device);
}

HRESULT CGameInstance::Initialize_Engine(HINSTANCE hInst, _uint iNumLevels, CGraphic_Device::GRAPHICDESC GraphicDesc, LPDIRECT3DDEVICE9* ppGraphic_Device)
{
	if (nullptr == m_pGraphic_Device ||
		nullptr == m_pInput_Device ||
		nullptr == m_pObject_Manager ||
		nullptr == m_pComponent_Manager)
		return E_FAIL;

	if (FAILED(m_pGraphic_Device->InitDevice(GraphicDesc.hWnd, GraphicDesc.iWinCX, GraphicDesc.iWinCY, ppGraphic_Device)))
		return E_FAIL;

	if (FAILED(m_pInput_Device->InitDevice(hInst, GraphicDesc.hWnd)))
		return E_FAIL;

	if (FAILED(m_pObject_Manager->Reserve_Manager(iNumLevels)))
		return E_FAIL;

	if (FAILED(m_pComponent_Manager->Reserve_Manager(iNumLevels)))
		return E_FAIL;

	if (FAILED(m_pPicking->NativeConstruct(GraphicDesc.hWnd, *ppGraphic_Device)))
		return E_FAIL;
	if (FAILED(m_pFrustum->NativeConstruct(*ppGraphic_Device)))
		return E_FAIL;


	return S_OK;
}

void CGameInstance::Tick_Engine(_float fTimeDelta)
{
	if (nullptr == m_pLevel_Manager ||
		nullptr == m_pInput_Device)
		return;

	m_pInput_Device->SetUp_InputDeviceState();

	m_pObject_Manager->Tick(fTimeDelta);

	m_pPicking->Update_ToTransform();

	m_pFrustum->Update_Plane();

	m_pObject_Manager->LateTick(fTimeDelta);


	m_pLevel_Manager->Tick(fTimeDelta);
}

HRESULT CGameInstance::Render_Engine()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	m_pLevel_Manager->Render();

	return S_OK;
}

HRESULT CGameInstance::Clear_LevelResource(_uint iLevelIndex)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	if (FAILED(m_pObject_Manager->Clear(iLevelIndex)))
		return E_FAIL;

	return S_OK;
}

void CGameInstance::Render_Begin(void)
{
	if (nullptr == m_pGraphic_Device)
		return;

	return m_pGraphic_Device->Render_Begin();
}

void CGameInstance::Render_End()
{
	if (nullptr == m_pGraphic_Device)
		return;

	return m_pGraphic_Device->Render_End();
}

_char CGameInstance::Get_DIKeyState(_uchar byKeyID)
{
	if (nullptr == m_pInput_Device)
		return 0;

	return m_pInput_Device->Get_DIKeyState(byKeyID);
}

_char CGameInstance::Get_DIMButtonState(CInput_Device::MOUSEBUTTONSTATE eDIMBState)
{
	if (nullptr == m_pInput_Device)
		return 0;

	return m_pInput_Device->Get_DIMButtonState(eDIMBState);
}

_long CGameInstance::Get_DIMMoveState(CInput_Device::MOUSEMOVESTATE eDIMMState)
{
	if (nullptr == m_pInput_Device)
		return 0;

	return m_pInput_Device->Get_DIMMoveState(eDIMMState);
}

HRESULT CGameInstance::Add_Timers(const _tchar * pTimerTag)
{
	if (nullptr == m_pTimer_Manager)
		return E_FAIL;

	return m_pTimer_Manager->Add_Timers(pTimerTag);
}

_double CGameInstance::Compute_TimeDelta(const _tchar * pTimerTag)
{
	if (nullptr == m_pTimer_Manager)
		return 0.0f;

	return m_pTimer_Manager->Compute_TimeDelta(pTimerTag);
}

HRESULT CGameInstance::Open_Level(_uint iLevelIndex, CLevel * pLevel)
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->OpenLevel(iLevelIndex, pLevel);
}

_uint CGameInstance::Get_LevelIndex()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Get_CurrentLevel();
}

void CGameInstance::Set_LevelIndex(_uint _index)
{
	if (nullptr == m_pLevel_Manager)
		return;

	m_pLevel_Manager->Set_CurrentLevel(_index);
}

CComponent * CGameInstance::Get_Component(_uint iLevelIndex, const _tchar * pLayerTag, const _tchar * pComponentTag, _uint iIndex)
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->Get_Component(iLevelIndex, pLayerTag, pComponentTag, iIndex);
}

HRESULT CGameInstance::Add_Prototype(const _tchar * pPrototypeTag, CGameObject * pPrototype)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_Prototype(pPrototypeTag, pPrototype);
}

HRESULT CGameInstance::Add_GameObjectToLayer(_uint iLevelIndex, const _tchar * pLayerTag, const _tchar * pPrototypeTag, void * pArg)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_GameObjectToLayer(iLevelIndex, pLayerTag, pPrototypeTag, pArg);
}

_bool CGameInstance::Collison_Sheare(_uint iLevelIndex, const _tchar * pDistLayerTag, const _tchar * pTargetLayerTag)
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->Collison_Sheare(iLevelIndex, pDistLayerTag, pTargetLayerTag);
}

_bool CGameInstance::Collison_Knockback(_uint iLevelIndex, const _tchar * pDistLayerTag, const _tchar * pTargetLayerTag)
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->Collison_Knockback(iLevelIndex, pDistLayerTag, pTargetLayerTag);
}

_bool CGameInstance::Collison_Rect(_uint iLevelIndex, const _tchar * pDistLayerTag, const _tchar * pTargetLayerTag)
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->Collison_Rect(iLevelIndex, pDistLayerTag, pTargetLayerTag);

}

_bool CGameInstance::SuperCollison_Rect(_uint iLevelIndex, const _tchar * pDistLayerTag, vector<_float2> _BoxsPos[80][80])
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->SuperCollison_Rect(iLevelIndex, pDistLayerTag, _BoxsPos);
}

_bool CGameInstance::Check_EmptyLayer(_uint iLevelIndex, const _tchar * pLayerTag)
{
	if (nullptr == m_pObject_Manager)
		return nullptr;

	return m_pObject_Manager->Check_EmptyLayer(iLevelIndex, pLayerTag);
}

HRESULT CGameInstance::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (nullptr == m_pComponent_Manager)
		return E_FAIL;

	return m_pComponent_Manager->Add_Prototype(iLevelIndex, pPrototypeTag, pPrototype);
}

CComponent * CGameInstance::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	if (nullptr == m_pComponent_Manager)
		return nullptr;

	return m_pComponent_Manager->Clone_Component(iLevelIndex, pPrototypeTag, pArg);
}

HRESULT CGameInstance::Set_TextureCom(_uint TexLevelIndex, const _tchar * _RendererTag, const _tchar * CloneCubeTexTag, const _tchar * CloneTileTexTag)
{
	if (nullptr == m_pComponent_Manager)
		return E_FAIL;

	return m_pComponent_Manager->Set_TextureCom(TexLevelIndex, _RendererTag, CloneCubeTexTag, CloneTileTexTag);
}

void CGameInstance::Release_Engine()
{

	CGameInstance::GetInstance()->DestroyInstance();

	CLevel_Manager::GetInstance()->DestroyInstance();

	CObject_Manager::GetInstance()->DestroyInstance();

	CComponent_Manager::GetInstance()->DestroyInstance();

	CTimer_Manager::GetInstance()->DestroyInstance();

	CInput_Device::GetInstance()->DestroyInstance();

	CPicking::GetInstance()->DestroyInstance();

	CFrustum::GetInstance()->DestroyInstance();

	CGraphic_Device::GetInstance()->DestroyInstance();
}

void CGameInstance::Free()
{
	Safe_Release(m_pFrustum);
	Safe_Release(m_pPicking);
	Safe_Release(m_pTimer_Manager);
	Safe_Release(m_pComponent_Manager);
	Safe_Release(m_pObject_Manager);
	Safe_Release(m_pLevel_Manager);
	Safe_Release(m_pInput_Device);
	Safe_Release(m_pGraphic_Device);
}
