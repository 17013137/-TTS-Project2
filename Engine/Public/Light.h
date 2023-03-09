#pragma once

#include "Component.h"

/* 객체의 월드상태를 표현하는 월드행렬을 가지고 있는다. */
/* 객체에게 필요한 월드 변환의 기능을 가진다. (직진, 후진, 회전 ) */

BEGIN(Engine)


class ENGINE_DLL CLight final : public CComponent
{
public:
	enum ITEM{ RIFLEAMMO, SHOTGUNAMMO, PISTOLAMMO, MEDICKIT, GRENADE, COIN, ITEM_END};
public:



public:
	explicit CLight(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CLight(const CLight& rhs);
	virtual ~CLight() = default;

	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);

public:
	void Setup_Light();
	

private:
	_int Channel;

private:
	


public:
	static CLight* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END