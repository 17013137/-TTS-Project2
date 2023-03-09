#pragma once

#include "Client_Defines.h"
#include "Inventory.h"

class CPlayerData
{
public:
	CPlayerData();
	~CPlayerData();

public:
	static CPlayerData*		Get_Instance(void)
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CPlayerData;

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
	void Initialize();
	void Release();

public:
	CInventory::INVENTORYDESC* Get_Inven() { return &Inven; }
	void Set_Inven(CInventory::INVENTORYDESC _Inven) { Inven = _Inven; }


private:
	static		CPlayerData*	m_pInstance;
	
private:
	CInventory::INVENTORYDESC Inven;
};

