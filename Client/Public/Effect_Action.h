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

class CEffect_Action final : public CBlendObject
{
private:

	enum TYPE { TYPE_FIRE, TYPE_SMOKE,TYPE_BUBBLE, TYPE_CRACK, TYPE_BOTTOMEXPLOSION, TYPE_END };
	explicit CEffect_Action(LPDIRECT3DDEVICE9 pGraphic_Device);
	CEffect_Action(const CEffect_Action& rhs);
	virtual ~CEffect_Action() = default;



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
	EFFECTTYPE			m_Effect_Type;
	_float				m_fFrame = 0.f;
	_int				LoopTime = 2;
	_float				Loop = 0.f;
	_int				MinfFrame;
	_int				MaxfFrame;
	_int				DelayTime;
					
	_bool				RenderOn = true;
	_float3				Move;
private:
	HRESULT SetUp_Components();



public:
	static CEffect_Action* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END