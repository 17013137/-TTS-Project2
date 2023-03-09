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

class CBlood_Effect final : public CBlendObject
{
private:


	enum TYPE { TYPE_BLOOD0, TYPE_BLOOD1, TYPE_BLOOD2, TYPE_BLOOD3, TYPE_BLOOD4, TYPE_BLOOD5, TYPE_BLOOD6, TYPE_BLOOD7, TYPE_BLOOD8, TYPE_BLOOD9, TYPE_END };
	explicit CBlood_Effect(LPDIRECT3DDEVICE9 pGraphic_Device);
	CBlood_Effect(const CBlood_Effect& rhs);
	virtual ~CBlood_Effect() = default;

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
	EFFECTTYPE				m_Effect_Type;
	_float				m_fFrame = 0.f;
	_float				MinfFrame;
	_float				MaxfFrame;
	_float				LoopTime;
private:
	HRESULT SetUp_Components();



public:
	static CBlood_Effect* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END