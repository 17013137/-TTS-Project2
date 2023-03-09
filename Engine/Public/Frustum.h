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
	void Update_Plane();  //카메라 행렬을 입력받아 6개의 평면을 만든다.
	BOOL IsIn(_float3 _Pos);  //한 점v가 프러스텀 안에 있으면 true, 아니면 false를 반환
	

private:
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;

private:
	_float3 m_vtx[8]; //프러스텀을 구성할 정점8개
	_float3 m_CameraPos; //현재 카메라의 월드좌표
	D3DXPLANE m_Plane[6]; //프러스텀을 구성하는 6개의 평면
	
public:
	virtual void Free() override;

};

END