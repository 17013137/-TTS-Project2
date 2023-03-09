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

class CScene_UI2 final : public CGameObject
{
private:
	explicit CScene_UI2(LPDIRECT3DDEVICE9 pGraphic_Device);
	CScene_UI2(const CScene_UI2& rhs);
	virtual ~CScene_UI2() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	void Set_Dialogue();

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

	RECT				m_rScene_MSG;
	LPD3DXFONT  m_pd3dxFont;
	_int		m_MSG_Cnt;

	_bool m_bTab;
	_bool m_bScene;

	_int* m_iRifleAmmo;
	_int* m_iMaxRifleAmmo;
	_bool flag = false;
private:
	HRESULT SetUp_Components();
	void Set_Scene();
	_tchar Scene_MSG[MAX_PATH][100] = { L"" };

public:
	static CScene_UI2* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END