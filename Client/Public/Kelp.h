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

class CKelp final : public CBlendObject
{
private:
	explicit CKelp(LPDIRECT3DDEVICE9 pGraphic_Device);
	CKelp(const CKelp& rhs);
	virtual ~CKelp() = default;
public:
	typedef struct Effect_Type2
	{
		_float3     EffectPos;
		_int        EffectType;
	}EFFECT2;
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
	_float				m_fFrame = 0.f;
	_int				MaxfFrame = 10;
	EFFECT2				MyType;
	_int				m_Texture = 0;
private:
	HRESULT SetUp_Components();



public:
	static CKelp* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END