#include "..\Public\Renderer.h"
#include "GameObject.h"
#include "BlendObject.h"
#include "Component_Manager.h"
#include "Frustum.h"

CRenderer::CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device)
{

}

HRESULT CRenderer::NativeConstruct_Prototype()
{
	return S_OK;
}

HRESULT CRenderer::NativeConstruct(void * pArg)
{
	return S_OK;
}

HRESULT CRenderer::Add_RenderGroup(RENDERGROUP eGroup, CGameObject * pGameObject)
{
	if (nullptr == pGameObject)
		return E_FAIL;

	CTransform* trans = (CTransform*)pGameObject->Get_Component(L"Com_Transform");
	if (!CFrustum::GetInstance()->IsIn(trans->Get_State(CTransform::STATE_POSITION))) {
		return E_FAIL;
	}

	m_RenderList[eGroup].push_back(pGameObject);
	Safe_AddRef(pGameObject);

	return S_OK;
}

HRESULT CRenderer::Add_vCube(_uint _TexNum, CGameObject * pGameObject)
{
	if (nullptr == pGameObject)
		return E_FAIL;

	CTransform* trans = (CTransform*)pGameObject->Get_Component(L"Com_Transform");
	if (!CFrustum::GetInstance()->IsIn(trans->Get_State(CTransform::STATE_POSITION)))
		return E_FAIL;

	v_Cube[_TexNum].push_back(pGameObject);
	Safe_AddRef(pGameObject);
	return S_OK;
}

HRESULT CRenderer::Add_vTIle(_uint _TexNum, CGameObject * pGameObject)
{
	if (nullptr == pGameObject)
		return E_FAIL;

	CTransform* trans = (CTransform*)pGameObject->Get_Component(L"Com_Transform");
	if (!CFrustum::GetInstance()->IsIn(trans->Get_State(CTransform::STATE_POSITION)))
		return E_FAIL;

	v_Tile[_TexNum].push_back(pGameObject);
	Safe_AddRef(pGameObject);
	return S_OK;
}

HRESULT CRenderer::Render_GameObjects()
{
	if (FAILED(Render_Priority()))
		return E_FAIL;

	if (FAILED(Render_NonBlend()))
		return E_FAIL;

	if (FAILED(Render_Cube()))
		return E_FAIL;
	
	if (FAILED(Render_Tile()))
		return E_FAIL;

	if (FAILED(Render_Blend()))
		return E_FAIL;

	if (FAILED(Render_Effect()))
		return E_FAIL;

	if (FAILED(Render_UI()))
		return E_FAIL;


	return S_OK;
}

HRESULT CRenderer::Set_TextureCom(CTexture * _CubeTexCom, CTexture * _TileTexCom)
{
	if (_CubeTexCom == nullptr || _TileTexCom == nullptr)
		return E_FAIL;

	Cube_TexCom = _CubeTexCom;
	Tile_TexCom = _TileTexCom;
	Safe_AddRef(Cube_TexCom);
	Safe_AddRef(Tile_TexCom);

	cubetxlen = _CubeTexCom->Get_NumTexture() + 1;
	tiletxlen = Tile_TexCom->Get_NumTexture() + 1;

	v_Cube = new vector<CGameObject*>[cubetxlen];
	v_Tile = new vector<CGameObject*>[tiletxlen];


	return S_OK;
}

HRESULT CRenderer::Render_Priority()
{
	HRESULT hr = 0;

	if (nullptr == m_pGraphic_Device)
		return E_FAIL;

	/* CCW : Counter Clock Wise : 반시계방향ㄹ으 ㅋ럴링한다. == 시계방향(전면)만 보여준다.  */
	/* CW : Clock Wise : 시계방향ㄹ으 ㅋ럴링한다. == 반시계방향(뒷면)만 보여준다.  */
	m_pGraphic_Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);
	m_pGraphic_Device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	m_pGraphic_Device->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (auto& pGameObject : m_RenderList[GROUP_PRIORITY])
	{
		if (nullptr != pGameObject)
		{
			hr = pGameObject->Render();
			Safe_Release(pGameObject);
		}

		if (FAILED(hr))
			return E_FAIL;
	}

	m_RenderList[GROUP_PRIORITY].clear();

	//m_pGraphic_Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	m_pGraphic_Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pGraphic_Device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	m_pGraphic_Device->SetRenderState(D3DRS_LIGHTING, TRUE);

	return S_OK;
}

HRESULT CRenderer::Render_NonBlend()
{
	HRESULT hr = 0;

	for (auto& pGameObject : m_RenderList[GROUP_NONBLEND])
	{
		if (nullptr != pGameObject)
		{
			hr = pGameObject->Render();
			Safe_Release(pGameObject);
		}

		if (FAILED(hr))
			return E_FAIL;
	}

	m_RenderList[GROUP_NONBLEND].clear();

	return S_OK;
}

HRESULT CRenderer::Render_Cube()
{
	HRESULT hr = 0;

	for (_uint i = 0; i < cubetxlen; i++) {
		if (v_Cube[i].empty())
			continue;

		if (FAILED(Cube_TexCom->Bind_OnGraphicDevice(i)))
			return E_FAIL;

		for (auto& pGameObject : v_Cube[i])
		{
			if (nullptr != pGameObject)
			{
				hr = pGameObject->Render();
				Safe_Release(pGameObject);
			}
			if (FAILED(hr))
				return E_FAIL;
		}
		v_Cube[i].clear();
	}

	return S_OK;
}

HRESULT CRenderer::Render_Tile()
{
	HRESULT hr = 0;

	for (_uint i = 0; i < tiletxlen; i++) {
		if (v_Tile[i].empty())
			continue;

		if (FAILED(Tile_TexCom->Bind_OnGraphicDevice(i)))
			return E_FAIL;

		for (auto& pGameObject : v_Tile[i])
		{
			if (nullptr != pGameObject)
			{
				hr = pGameObject->Render();
				Safe_Release(pGameObject);
			}
			if (FAILED(hr))
				return E_FAIL;
		}
		v_Tile[i].clear();
	}

	return S_OK;
}


HRESULT CRenderer::Render_Blend()
{
	HRESULT hr = 0;

	//m_pGraphic_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	//m_pGraphic_Device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//m_pGraphic_Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//m_pGraphic_Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_pGraphic_Device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	m_pGraphic_Device->SetRenderState(D3DRS_ALPHAREF, 100);
	m_pGraphic_Device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);


	//m_RenderList[GROUP_ALPHABLEND].sort([](CGameObject* pSour, CGameObject* pDest)
	//{
	//	return ((CBlendObject*)pSour)->Get_CamDistance() > ((CBlendObject*)pDest)->Get_CamDistance();
	//});

	for (auto& pGameObject : m_RenderList[GROUP_ALPHABLEND])
	{
		if (nullptr != pGameObject)
		{
			hr = pGameObject->Render();
			Safe_Release(pGameObject);
		}

		if (FAILED(hr))
			return E_FAIL;
	}

	m_RenderList[GROUP_ALPHABLEND].clear();

	//m_pGraphic_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);


	return S_OK;
}


HRESULT CRenderer::Render_Effect()
{
	HRESULT hr = 0;

	
	m_pGraphic_Device->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (auto& pGameObject : m_RenderList[GROUP_EFFECT])
	{
		if (nullptr != pGameObject)
		{
			hr = pGameObject->Render();
			Safe_Release(pGameObject);
		}

		if (FAILED(hr))
			return E_FAIL;
	}

	m_RenderList[GROUP_EFFECT].clear();

	
	return S_OK;

}


HRESULT CRenderer::Render_UI()
{
	HRESULT hr = 0;
	
	for (auto& pGameObject : m_RenderList[GROUP_UI])
	{
		if (nullptr != pGameObject)
		{
			hr = pGameObject->Render();
			Safe_Release(pGameObject);
		}
		
		if (FAILED(hr))
			return E_FAIL;
	}
	m_RenderList[GROUP_UI].clear();
	m_pGraphic_Device->SetRenderState(D3DRS_LIGHTING, TRUE);

	return S_OK;
}



CRenderer * CRenderer::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CRenderer*	pInstance = new CRenderer(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CRenderer"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CRenderer::Clone(void * pArg)
{
	AddRef();
	return this;
}

void CRenderer::Free()
{
	__super::Free();


	for (_uint i = 0; i < sizeof(v_Cube) / sizeof(vector<CGameObject*>); i++) {
		if (v_Cube[i].empty())
			continue;

		for (auto& iter : v_Cube[i])
			Safe_Release(iter);
		v_Cube[i].clear();
	}

	for (_uint i = 0; i < sizeof(v_Tile) / sizeof(vector<CGameObject*>); i++) {
		if (v_Tile[i].empty())
			continue;

		for (auto& iter : v_Tile[i])
			Safe_Release(iter);
		v_Tile[i].clear();
	}


	for (_uint i = 0; i < GROUP_END; ++i)
	{
		for (auto& pGameObject : m_RenderList[i])
			Safe_Release(pGameObject);
		m_RenderList[i].clear();
	}

	Safe_Release(Cube_TexCom);
	Safe_Release(Tile_TexCom);
}


