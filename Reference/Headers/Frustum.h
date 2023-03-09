#pragma once

#include "Base.h"

BEGIN(Engine)

class CFrustum final : public CBase
{
	DECLARE_SINGLETON(CFrustum)
public:
	CFrustum();
	virtual ~CFrustum() = default;

public:
	HRESULT NativeConstruct(LPDIRECT3DDEVICE9 pGraphic_Device);

public:
	void Update_Plane();  //ī�޶� ����� �Է¹޾� 6���� ����� �����.
	BOOL IsIn(_float3 _Pos);  //�� ��v�� �������� �ȿ� ������ true, �ƴϸ� false�� ��ȯ
	

private:
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;

private:
	_float3 m_vtx[8]; //���������� ������ ����8��
	_float3 m_CameraPos; //���� ī�޶��� ������ǥ
	D3DXPLANE m_Plane[6]; //���������� �����ϴ� 6���� ���
	
public:
	virtual void Free() override;

};

END