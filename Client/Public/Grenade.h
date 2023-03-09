#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CSubTransform;
class CVIBuffer_Cube;

END

BEGIN(Client)

class CGrenade final : public CGameObject
{
private:
	explicit CGrenade(LPDIRECT3DDEVICE9 pGraphic_Device);
	CGrenade(const CGrenade& rhs);
	virtual ~CGrenade() = default;

	typedef struct TargetPos
	{
		_float3		Pos;
		_float3		target;
	}TARGETPOS;
	typedef struct Effect_Type
	{
		_int		Type;
		_float3		Target;
		_float3		Pos;
	}EFFECTTYPE;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;

	CSubTransform*		Sub_pTransformCom = nullptr;
	CVIBuffer_Cube*		Sub_pVIBufferCom = nullptr;
	CTexture*			Sub_pTextureCom = nullptr;
	CRenderer*			Sub_pRendererCom = nullptr;
	TARGETPOS TargetPos;

private:
	HRESULT SetUp_Components();
	HRESULT On_OnTerrain();
	_bool Count = true;

public:
	static CGrenade* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END