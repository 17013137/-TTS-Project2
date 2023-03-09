#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
END

BEGIN(Client)

class MapBase final : public CGameObject
{
private:
	explicit MapBase(LPDIRECT3DDEVICE9 pGraphic_Device);
	MapBase(const MapBase& rhs);
	virtual ~MapBase() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

public:
	void Key_Input();

private:
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;

private:
	_float4x4			m_ProjMatrix;
	_float				m_fX = 0.f;
	_float				m_fY = 0.f;
	_float				m_fSizeX = 0.f;
	_float				m_fSizeY = 0.f;

private:
	CTransform*			m_TFicon = nullptr;
	CVIBuffer_Rect*		m_VBicon = nullptr;
	CTexture*			m_Texicon = nullptr;
	CRenderer*			m_Rendericon = nullptr;


private:
	HRESULT SetUp_Components();
	_bool flag = false;
	_float dist = 10.f;
	int imgnum = 0;
	int imgmax = 0;
	int MapMoving[11] = { LEVEL_SHELTER, LEVEL_FOREST, LEVEL_FOREST, LEVEL_CAVE, LEVEL_CAVE, LEVEL_GAMEPLAY, LEVEL_GAMEPLAY, LEVEL_CITY, LEVEL_EVENT, LEVEL_HELL, LEVEL_BOSS };
	//enum LEVEL { LEVEL_STATIC, LEVEL_LOADING, LEVEL_LOGO, LEVEL_SHELTER, LEVEL_STORE, LEVEL_GAMEPLAY, LEVEL_FOREST, LEVEL_CAVE, LEVEL_CITY, LEVEL_EVENT, LEVEL_HELL, LEVEL_BOSS, LEVEL_END };
public:
	static MapBase* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END