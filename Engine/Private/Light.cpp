#include "..\Public\Light.h"





CLight::CLight(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device)
	,Channel(3)
{
}

CLight::CLight(const CLight & rhs)
	: CComponent(rhs)
	,Channel(rhs.Channel)
{
}

HRESULT CLight::NativeConstruct_Prototype()
{



	return S_OK;
}

HRESULT CLight::NativeConstruct(void * pArg)
{
	
//	if (nullptr != pArg)
//		memcpy(&m_Inventory, pArg, sizeof(INVENTORYDESC));
	Setup_Light();
	return S_OK;
}

void CLight::Setup_Light()
{

	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(light));
	light.Type = D3DLIGHT_POINT;
	light.Diffuse.r = 1.f;
	light.Diffuse.g = 1.f;
	light.Diffuse.b = 1.f;
	light.Diffuse.a = 0.f;
	light.Attenuation0 = 0.1f;
	light.Range = 5.f;

	light.Position = _float3(rand() % 80, 3.f, rand() % 80);
	m_pGraphic_Device->SetLight(Channel, &light);
	m_pGraphic_Device->LightEnable(Channel, TRUE);

}

CLight * CLight::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CLight*	pInstance = new CLight(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CLight"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CLight::Clone(void * pArg)
{
	++Channel;

	CLight*	pInstance = new CLight(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CLight"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLight::Free()
{
	__super::Free();
	
}
