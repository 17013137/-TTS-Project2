#include "stdafx.h"
#include "PlayerData.h"

CPlayerData* CPlayerData::m_pInstance = nullptr;
CPlayerData::CPlayerData()
{
	ZeroMemory(&Inven, sizeof(Inven));
}


CPlayerData::~CPlayerData()
{
}

void CPlayerData::Initialize()
{
	Inven.RifleAmmo = 1000;
	Inven.ShotgunAmmo = 500;
	Inven.PistolAmmo = 300;
	Inven.Medickit = 20;
	Inven.Grenade = 10;
	Inven.Coin = 480000;
	Inven.Riflebullet = 30;
	Inven.Shotgunbullet = 7;
	Inven.Pistolbullet = 10;

}

void CPlayerData::Release()
{
}
