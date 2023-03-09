#include "..\Public\Inventory.h"





CInventory::CInventory(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device)
	
{
}

CInventory::CInventory(const CInventory & rhs)
	: CComponent(rhs)

{
}

HRESULT CInventory::NativeConstruct_Prototype()
{



	return S_OK;
}

HRESULT CInventory::NativeConstruct(void * pArg)
{
	
	if (nullptr != pArg)
		memcpy(&m_Inventory, pArg, sizeof(INVENTORYDESC));

	return S_OK;
}


void CInventory::SetMaxAmmo(ITEM i, _int Max)
{
	switch (i)
	{
	case Engine::CInventory::RIFLEAMMO:
		MaxRiflebullet = Max;
		break;
	case Engine::CInventory::SHOTGUNAMMO:
		MaxtShotgunbullet = Max;
		break;
	case Engine::CInventory::PISTOLAMMO:
		MaxPistolbullet = Max;
		break;
	case Engine::CInventory::MEDICKIT:
		break;
	case Engine::CInventory::GRENADE:
		break;
	case Engine::CInventory::COIN:
		break;
	case Engine::CInventory::ITEM_END:
		break;
	default:
		break;
	}


}

void CInventory::Reload(ITEM i)
{
	if (i == RIFLEAMMO)
	{
		_int ReloadAmmo = MaxRiflebullet - m_Inventory.Riflebullet;
		if (ReloadAmmo <= m_Inventory.RifleAmmo)
		{
			m_Inventory.RifleAmmo -= ReloadAmmo;
			m_Inventory.Riflebullet = MaxRiflebullet;
		}
		else
		{
			m_Inventory.Riflebullet += m_Inventory.RifleAmmo;
			m_Inventory.RifleAmmo = 0;
		}

	}
	else if (i == SHOTGUNAMMO)
	{
		_int ReloadAmmo = MaxtShotgunbullet - m_Inventory.Shotgunbullet;
		if (ReloadAmmo <= m_Inventory.ShotgunAmmo)
		{
			m_Inventory.ShotgunAmmo -= ReloadAmmo;
			m_Inventory.Shotgunbullet = MaxtShotgunbullet;
		}
		else
		{
			m_Inventory.Shotgunbullet += m_Inventory.ShotgunAmmo;
			m_Inventory.ShotgunAmmo = 0;
		}
	}
	else if (i == PISTOLAMMO)
	{
		_int ReloadAmmo = MaxPistolbullet - m_Inventory.Pistolbullet;
		if (ReloadAmmo <= m_Inventory.PistolAmmo)
		{
			m_Inventory.PistolAmmo -= ReloadAmmo;
			m_Inventory.Pistolbullet = MaxPistolbullet;
		}
		else
		{
			m_Inventory.Pistolbullet += m_Inventory.PistolAmmo;
			m_Inventory.PistolAmmo = 0;
		}
	}

}

_bool CInventory::Buy(ITEM i, _int Count, _int NeedCoin)
{
	if (NeedCoin < m_Inventory.Coin)
	{
		m_Inventory.Coin -= NeedCoin;
		if (i == RIFLEAMMO)
		{
			m_Inventory.RifleAmmo += Count;
			return true;
		}
		else if (i == SHOTGUNAMMO)
		{
			m_Inventory.ShotgunAmmo += Count;
			return true;
		}
		else if (i == PISTOLAMMO)
		{
			m_Inventory.PistolAmmo += Count;
			return true;
		}
		else if (i == MEDICKIT)
		{
			m_Inventory.Medickit += Count;
			return true;
		}
		else if (i == GRENADE)
		{
			m_Inventory.Grenade += Count;
			return true;
		}
	}

	return false;
}

_bool CInventory::UseItem(ITEM i)
{

	if (i == RIFLEAMMO)
	{
		if (m_Inventory.Riflebullet > 0)
		{
			--m_Inventory.Riflebullet;
			return true;
		}
		else
			return false;
	}
	else if (i == SHOTGUNAMMO)
	{
		if (m_Inventory.Shotgunbullet > 0)
		{
			--m_Inventory.Shotgunbullet;
			return true;
		}
		else
			return false;
	}
	else if (i == PISTOLAMMO)
	{
		if (m_Inventory.Pistolbullet > 0)
		{
			--m_Inventory.Pistolbullet;
			return true;
		}
		else
			return false;
	}
	else if (i == MEDICKIT)
	{
		if (m_Inventory.Medickit > 0)
		{
			--m_Inventory.Medickit;
			return true;
		}
		else
			return false;
	}
	else if (i == GRENADE)
	{
		if (m_Inventory.Grenade > 0)
		{
			--m_Inventory.Grenade;
			return true;
		}
		else
			return false;
	}

	return false;
}

void CInventory::GetItem(ITEM i, _int Count)
{
	switch (i)
	{
	case Engine::CInventory::RIFLEAMMO:
		m_Inventory.RifleAmmo += Count;
		break;
	case Engine::CInventory::SHOTGUNAMMO:
		m_Inventory.ShotgunAmmo += Count;
		break;
	case Engine::CInventory::PISTOLAMMO:
		m_Inventory.PistolAmmo += Count;
		break;
	case Engine::CInventory::MEDICKIT:
		m_Inventory.Medickit += Count;
		break;
	case Engine::CInventory::GRENADE:
		m_Inventory.Grenade += Count;
		break;
	case Engine::CInventory::COIN:
		m_Inventory.Coin += Count;
		break;
	case Engine::CInventory::ITEM_END:
		break;
	default:
		break;
	}
}

_int * CInventory::Get_bulletCount(ITEM i)
{
	if (i == RIFLEAMMO)
	{
		return	&m_Inventory.Riflebullet;
	}
	else if (i == SHOTGUNAMMO)
	{
		return	&m_Inventory.Shotgunbullet;
	}
	else if (i == PISTOLAMMO)
	{
		return	&m_Inventory.Pistolbullet;
	}


	return false;
}

_int * CInventory::Get_MaxbulletCount(ITEM i)
{
	if (i == RIFLEAMMO)
	{
		return	&MaxRiflebullet;
	}
	else if (i == SHOTGUNAMMO)
	{
		return	&MaxtShotgunbullet;
	}
	else if (i == PISTOLAMMO)
	{
		return	&MaxPistolbullet;
	}

	return false;
}

_int * CInventory::Get_ItemCount(ITEM i)
{
	if (i == RIFLEAMMO)
	{
		return	&m_Inventory.RifleAmmo;
	}
	else if (i == SHOTGUNAMMO)
	{
		return	&m_Inventory.ShotgunAmmo;
	}
	else if (i == PISTOLAMMO)
	{
		return	&m_Inventory.PistolAmmo;
	}
	else if (i == MEDICKIT)
	{
		return	&m_Inventory.Medickit;
	}
	else if (i == GRENADE)
	{
		return	&m_Inventory.Grenade;
	}
	else if (i == COIN)
	{
		return	&m_Inventory.Coin;
	}

	return false;
}

CInventory * CInventory::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CInventory*	pInstance = new CInventory(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CInventory"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CInventory::Clone(void * pArg)
{
	CInventory*	pInstance = new CInventory(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CInventory"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CInventory::Free()
{
	__super::Free();
	
}
