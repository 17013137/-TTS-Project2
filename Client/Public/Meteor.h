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
	/* �����δ�.(���¸� ǥ���Ѵ�.) */
	CTransform*			m_pTransformCom = nullptr;

	/* �������� �׸�����?! (��) */
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;

	/* �� ������ � �ؽ��� �ø�����?! */
	CTexture*			m_pTextureCom = nullptr;

	/* �׸���!!! */
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