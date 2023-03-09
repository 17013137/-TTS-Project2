#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Cube;
class CStatus;
class CSubTransform;
class CGameInstance;
END

BEGIN(Client)

class CMeteor final : public CGameObject
{
private:
	explicit CMeteor(LPDIRECT3DDEVICE9 pGraphic_Device);
	CMeteor(const CMeteor& rhs);
	virtual ~CMeteor() = default;

public:
	typedef struct Effect_Type2
	{
		_float3     EffectPos;
		_int        EffectType;
	}EFFECT2;
	
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;

	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;

	/* 저 모델위에 어떤 텍스쳐 올릴건지?! */
	CTexture*			m_pTextureCom = nullptr;

	/* 그린다!!! */
	CRenderer*			m_pRendererCom = nullptr;

	CStatus*			m_pStatusCom = nullptr;

	CSubTransform*		Sub_pTransformCom = nullptr;
	CGameInstance*		pGameInstance = nullptr;
	_float				m_delay = 0.f;
	_float				m_Range = 10.f;
	_float3				m_Pos;
	_int				m_Texture = 0;
	_bool				On = true;

private:
	HRESULT SetUp_Components(void * pArg);



public:
	static CMeteor* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END