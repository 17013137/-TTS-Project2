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

class CRifleAmmo_Buy final : public CGameObject
{
private:
	explicit CRifleAmmo_Buy(LPDIRECT3DDEVICE9 pGraphic_Device);
	CRifleAmmo_Buy(const CRifleAmmo_Buy& rhs);
	virtual ~CRifleAmmo_Buy() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* �����δ�.(���¸� ǥ���Ѵ�.) */
	CTransform*			m_pTransformCom = nullptr;
	
	/* �������� �׸�����?! (��) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* �� ������ � �ؽ��� �ø�����?! */
	CTexture*			m_pTextureCom = nullptr;

	/* �׸���!!! */
	CRenderer*			m_pRendererCom = nullptr;

private:
	_float4x4			m_ProjMatrix;
	_float				m_fX, m_fY, m_fSizeX, m_fSizeY;

	RECT				m_rRifleStock;
	LPD3DXFONT			m_pd3dxFont;

	_uint				m_iRifleStock;
	_uint				m_iMaxRifleStock;

	RECT				m_BuyRect;

	_bool				m_bButton;

private:
	HRESULT SetUp_Components();



public:
	static CRifleAmmo_Buy* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END