#pragma once

#include "Client_Defines.h"
#include "BlendObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
END

BEGIN(Client)

class CWeather final : public CBlendObject
{
private:
	explicit CWeather(LPDIRECT3DDEVICE9 pGraphic_Device);
	CWeather(const CWeather& rhs);
	virtual ~CWeather() = default;

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
	_int				m_fFrame = 0;
	_bool				m_bSnow = false;
private:
	HRESULT SetUp_Components();



public:
	static CWeather* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END