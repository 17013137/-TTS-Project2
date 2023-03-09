#pragma once

#include "Component.h"

/* 1. ��ü���� �׸��¼����� ���� �׷����� ��Ƴ��´�. */
/* 2. ��Ƴ��� ��ü���� �����Լ��� ȣ�����ش�.  */
/* 3. �׷쿡 �´� �������¸� �����Ѵ�.  */

BEGIN(Engine)
class CTexture;
class ENGINE_DLL CRenderer final : public CComponent
{
public:
	enum RENDERGROUP { GROUP_PRIORITY, GROUP_NONBLEND, GROUP_CUBE, GROUP_TILE, GROUP_ALPHABLEND, GROUP_EFFECT, GROUP_UI, GROUP_END };
private:
	explicit CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CRenderer() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	HRESULT Add_RenderGroup(RENDERGROUP eGroup, class CGameObject* pGameObject);
	HRESULT Add_vCube(_uint key, class CGameObject* pGameObject);
	HRESULT Add_vTIle(_uint key, class CGameObject* pGameObject);
	HRESULT Render_GameObjects();

public:
	HRESULT Set_TextureCom(CTexture* _CubeTexCom, CTexture* _TileTexCom);

private:
	list<class CGameObject*>			m_RenderList[GROUP_END];
	typedef list<class CGameObject*>	RENDERLIST;

private:
	HRESULT Render_Priority();
	HRESULT Render_NonBlend();
	HRESULT Render_Blend();
	HRESULT Render_Effect();
	HRESULT Render_UI();

private:
	HRESULT Render_Cube();
	HRESULT Render_Tile();

private:
	vector<CGameObject*>* v_Cube;
	vector<CGameObject*>* v_Tile;

private:
	CTexture* Cube_TexCom = nullptr;
	CTexture* Tile_TexCom = nullptr;
	_uint cubetxlen = 0;
	_uint tiletxlen = 0;

public:
	static CRenderer* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg) override;
	virtual void Free() override;
};

END

