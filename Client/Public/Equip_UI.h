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

class CEquip_UI final : public CGameObject
{
private:
	explicit CEquip_UI(LPDIRECT3DDEVICE9 pGraphic_Device);
	CEquip_UI(const CEquip_UI& rhs);
	virtual ~CEquip_UI() = default;

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
	_bool				m_bEquip;

	RECT				m_rPainKiller;
	RECT				m_rShotGunAmmo;
	RECT				m_rRifleAmmo;
	RECT				m_rPistolAmmo;
	RECT				m_rGranade;

	LPD3DXFONT  m_pd3dxFont;

	_int* m_iPistolAmmo;
	_int* m_iMaxPistolAmmo;

	_int* m_iRifleAmmo;
	_int* m_iMaxRifleAmmo;

	_int* m_iShotGunAmmo;
	_int* m_iMaxShotGunAmmo;

	_int*				m_iPainKiller;
	_int*				m_iGranade;

private:
	HRESULT	SetUp_Components();
	void			Set_Equipment();

public:
	static CEquip_UI* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END