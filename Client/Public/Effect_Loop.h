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

class CEffect_Loop final : public CBlendObject
{
private:
	

	enum TYPE { TYPE_RIFLE, TYPE_SHOTGUN1, TYPE_SHOTGUN2, TYPE_PISTOL1, TYPE_PISTOL2, TYPE_WEAPON, TYPE_ZOMBIE, TYPE_TIMBER, TYPE_END };
	explicit CEffect_Loop(LPDIRECT3DDEVICE9 pGraphic_Device);
	CEffect_Loop(const CEffect_Loop& rhs);
	virtual ~CEffect_Loop() = default;

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
	static CEffect_Loop* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END