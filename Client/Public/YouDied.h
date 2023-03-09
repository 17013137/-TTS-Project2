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

class CYouDied final : public CGameObject
{
private:
	explicit CYouDied(LPDIRECT3DDEVICE9 pGraphic_Device);
	CYouDied(const CYouDied& rhs);
	virtual ~CYouDied() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

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
	_bool				m_bDie;

private:
	CTransform*			m_TFicon = nullptr;
	CVIBuffer_Rect*		m_VBicon = nullptr;
	CTexture*			m_Texicon = nullptr;
	CRenderer*			m_Rendericon = nullptr;


private:
	HRESULT SetUp_Components();
	_bool flag = false;
public:
	static CYouDied* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END