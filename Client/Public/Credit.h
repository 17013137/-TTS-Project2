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

class CCredit final : public CGameObject
{
private:
	explicit CCredit(LPDIRECT3DDEVICE9 pGraphic_Device);
	CCredit(const CCredit& rhs);
	virtual ~CCredit() = default;

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
	_bool				m_bCredit;
	
	_int				m_iCnt = 0;
public:
	_bool				m_bStay = false;
private:
	CTransform*			m_TFicon = nullptr;
	CVIBuffer_Rect*		m_VBicon = nullptr;
	CTexture*			m_Texicon = nullptr;
	CRenderer*			m_Rendericon = nullptr;


private:
	HRESULT SetUp_Components();

public:
	static CCredit* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END