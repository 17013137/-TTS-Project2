#include "..\Public\Level.h"
#include "GameInstance.h"
#include "Object_Manager.h"
CLevel::CLevel(LPDIRECT3DDEVICE9 pGraphic_Device)
	: m_pGraphic_Device(pGraphic_Device)
{
	Safe_AddRef(m_pGraphic_Device);
}

HRESULT CLevel::NativeConstruct()
{
	CGameInstance* gameins = CGameInstance::GetInstance();
	Safe_AddRef(gameins);

	m_LevelIndex = gameins->Get_LevelIndex();

	Safe_Release(gameins);
	return S_OK;
}

void CLevel::Tick(_float fTimeDelta)
{
	m_MonsterClear = CObject_Manager::GetInstance()->Check_EmptyLayer(m_LevelIndex, L"Monster");
	m_ObeliskClear = CObject_Manager::GetInstance()->Check_EmptyLayer(m_LevelIndex, L"Obelisk");
}

HRESULT CLevel::Load_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX)
{

	HANDLE		hFile = CreateFile(pTilePath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;

	DWORD	dwByte = 0;
	OBJDATA* pObjData = nullptr;

	CGameInstance* m_Gameinstance = CGameInstance::GetInstance();
	Safe_AddRef(m_Gameinstance);

	while (true)
	{
		pObjData = new OBJDATA;
		ReadFile(hFile, &pObjData->ObjID, sizeof(_uint), &dwByte, nullptr);
		ReadFile(hFile, &pObjData->WorldMTX, sizeof(_float4x4), &dwByte, nullptr);
		if (0 == dwByte)
		{
			Safe_Delete(pObjData);
			break;
		}

		_tchar _proto[MAX_PATH] = TEXT("Prototype_GameObject_");
		lstrcat(_proto, enum_str[pObjData->ObjID]);


		if (pObjData->ObjID == NormalZombie || pObjData->ObjID == ZombieSpitter || pObjData->ObjID == Fanatic || pObjData->ObjID == BlueSkeleton
			|| pObjData->ObjID == GrandfaSkeleton || pObjData->ObjID == Wither_Skeleton) {
			if (FAILED(m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"Monster", _proto, _float4x4(pObjData->WorldMTX))))
				return E_FAIL;
		}
		else if (pObjData->ObjID == GateCube || pObjData->ObjID == PurpleGate)
			m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"Gate", _proto, _float4x4(pObjData->WorldMTX));
		else if (pObjData->ObjID == Cone)
			m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"Obelisk", _proto, _float4x4(pObjData->WorldMTX));
		else {
			m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"Object", _proto, _float4x4(pObjData->WorldMTX));
		}
	}

	Safe_Release(m_Gameinstance);
	CloseHandle(hFile);
	return S_OK;

}

HRESULT CLevel::Load_Tile_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX)
{

	HANDLE		hFile = CreateFile(pTilePath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;

	DWORD	dwByte = 0;
	OBJDATA* pObjData = nullptr;

	CGameInstance* m_Gameinstance = CGameInstance::GetInstance();
	Safe_AddRef(m_Gameinstance);

	while (true)
	{
		pObjData = new OBJDATA;
		ReadFile(hFile, &pObjData->ObjID, sizeof(_uint), &dwByte, nullptr);
		ReadFile(hFile, &pObjData->WorldMTX, sizeof(_float4x4), &dwByte, nullptr);
		if (0 == dwByte)
		{
			Safe_Delete(pObjData);
			break;
		}
		pObjData->WorldMTX.m[0][3] = pObjData->ObjID;
		_tchar _proto[MAX_PATH] = TEXT("Prototype_GameObject_Tile");
		m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"TILE", _proto, _float4x4(pObjData->WorldMTX));
	}

	Safe_Release(m_Gameinstance);
	CloseHandle(hFile);
	return S_OK;

}

HRESULT CLevel::Load_Cube_Data(const TCHAR * pTilePath, _uint LEVEL_INDEX)
{
	HANDLE		hFile = CreateFile(pTilePath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;

	DWORD	dwByte = 0;
	WALLDATA* pObjData = nullptr;

	CGameInstance* m_Gameinstance = CGameInstance::GetInstance();
	Safe_AddRef(m_Gameinstance);

	while (true)
	{
		pObjData = new WALLDATA;
		ReadFile(hFile, &pObjData->isBlock, sizeof(_uint), &dwByte, nullptr);
		ReadFile(hFile, &pObjData->TexID, sizeof(_uint), &dwByte, nullptr);
		ReadFile(hFile, &pObjData->WorldMTX, sizeof(_float4x4), &dwByte, nullptr);

		if (0 == dwByte)
		{
			Safe_Delete(pObjData);
			break;
		}

		_tchar _proto[MAX_PATH] = TEXT("Prototype_GameObject_Cube");
		pObjData->WorldMTX.m[0][3] = (_float)pObjData->isBlock;
		pObjData->WorldMTX.m[1][3] = (_float)pObjData->TexID;
		m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, cube_str[pObjData->isBlock], _proto, _float4x4(pObjData->WorldMTX));

		if (pObjData->isBlock == 0) {
			_float2 Box = { pObjData->WorldMTX.m[3][0], pObjData->WorldMTX.m[3][2] };

			BoxsPos[(_uint)Box.x - 1][(_uint)Box.y].push_back(Box);  //4방향 위치값
			BoxsPos[(_uint)Box.x + 1][(_uint)Box.y].push_back(Box);
			BoxsPos[(_uint)Box.x][(_uint)Box.y + 1].push_back(Box);
			BoxsPos[(_uint)Box.x][(_uint)Box.y - 1].push_back(Box);

		}
	}

	Safe_Release(m_Gameinstance);
	CloseHandle(hFile);
	return S_OK;
}

HRESULT CLevel::Load_Deco_Data(const TCHAR * pTilePath, _uint LEVEL_INDEX)
{
	HANDLE		hFile = CreateFile(pTilePath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return E_FAIL;

	DWORD	dwByte = 0;
	OBJDATA* pObjData = nullptr;

	CGameInstance* m_Gameinstance = CGameInstance::GetInstance();
	Safe_AddRef(m_Gameinstance);

	while (true)
	{
		pObjData = new OBJDATA;
		ReadFile(hFile, &pObjData->ObjID, sizeof(_uint), &dwByte, nullptr);
		ReadFile(hFile, &pObjData->WorldMTX, sizeof(_float4x4), &dwByte, nullptr);
		if (0 == dwByte)
		{
			Safe_Delete(pObjData);
			break;
		}
		pObjData->WorldMTX._14 = (_float)pObjData->ObjID;
		_tchar _proto[MAX_PATH] = TEXT("Prototype_GameObject_Deco");
		m_Gameinstance->Add_GameObjectToLayer(LEVEL_INDEX, L"Deco", _proto, _float4x4(pObjData->WorldMTX));
	}

	Safe_Release(m_Gameinstance);
	CloseHandle(hFile);
	return S_OK;

}

HRESULT CLevel::Render()
{
	return S_OK;
}

void CLevel::Free()
{
	Safe_Release(m_pGraphic_Device);
}
