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

class CRespawn final : public CBlendObject
{
private:
	explicit CRespawn(LPDIRECT3DDEVICE9 pGraphic_Device);
	CRespawn(const CRespawn& rhs);
	virtual ~CRespawn() = default;

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
	_float				m_fFrame = 0.f;

private:
	HRESULT SetUp_Components();



public:
	static CRespawn* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END