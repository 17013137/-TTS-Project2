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
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;

	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;

	/* 저 모델위에 어떤 텍스쳐 올릴건지?! */
	CTexture*			m_pTextureCom = nullptr;

	/* 그린다!!! */
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