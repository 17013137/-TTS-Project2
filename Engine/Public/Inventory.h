#pragma once

#include "Component.h"

/* 객체의 월드상태를 표현하는 월드행렬을 가지고 있는다. */
/* 객체에게 필요한 월드 변환의 기능을 가진다. (직진, 후진, 회전 ) */

BEGIN(Engine)


class ENGINE_DLL CInventory final : public CComponent
{
public:
	enum ITEM{ RIFLEAMMO, SHOTGUNAMMO, PISTOLAMMO, MEDICKIT, GRENADE, COIN, ITEM_END};
public:
	typedef struct InventoryDESC
	{
		_int RifleAmmo = 0;
		_int ShotgunAmmo = 0;
		_int PistolAmmo = 0;
		_int Medickit = 0;
		_int Grenade = 0;
		_int Coin = 0;
		_int Riflebullet = 0;
		_int Shotgunbullet = 0;
		_int Pistolbullet = 0;

	}INVENTORYDESC;


public:
	explicit CInventory(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CInventory(const CInventory& rhs);
	virtual ~CInventory() = default;

	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);

public:
	void	SetMaxAmmo(ITEM i, _int Max);
	void	Reload(ITEM i);
	_bool	Buy(ITEM i,_int Count, _int NeedCoin);
	_bool	UseItem(ITEM i);
	void	GetItem(ITEM i, _int Count);
	_int*	Get_bulletCount(ITEM i);
	_int*	Get_MaxbulletCount(ITEM i);
	_int*	Get_ItemCount(ITEM i);
	INVENTORYDESC* Get_Inventory() { return &m_Inventory; }

private:
	_int MaxRiflebullet = 50;
	_int MaxtShotgunbullet = 10;
	_int MaxPistolbullet = 15;

private:
	INVENTORYDESC m_Inventory;


public:
	static CInventory* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END