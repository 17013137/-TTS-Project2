#pragma once

#include "Component.h"

/* ��ü�� ������¸� ǥ���ϴ� ��������� ������ �ִ´�. */
/* ��ü���� �ʿ��� ���� ��ȯ�� ����� ������. (����, ����, ȸ�� ) */

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