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

class CInventory_UI final : public CGameObject
{
private:
	explicit CInventory_UI(LPDIRECT3DDEVICE9 pGraphic_Device);
	CInventory_UI(const CInventory_UI& rhs);
	virtual ~CInventory_UI() = default;

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
	_bool				m_bInventory;
	_bool				m_btemporarily;

	RECT				m_rPainKiller;
	RECT				m_rShotGunAmmo;
	RECT				m_rRifleAmmo;
	RECT				m_rPistolAmmo;
	RECT				m_rGranade;
	RECT				m_rCoin;

	LPD3DXFONT  m_pd3dxFont;

	_int* m_iPistolAmmo;
	_int* m_iMaxPistolAmmo;

	_int* m_iRifleAmmo;
	_int* m_iMaxRifleAmmo;

	_int* m_iShotGunAmmo;
	_int* m_iMaxShotGunAmmo;

	_int*				m_iPainKiller;
	_int*				m_iGranade;
	_int*				m_iCoin;
	
private:
	HRESULT SetUp_Components();
	void Set_Inventory();
	

public:
	static CInventory_UI* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END