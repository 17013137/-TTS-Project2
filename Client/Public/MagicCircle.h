#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
END

BEGIN(Client)


class CMagicCircle final : public CGameObject
{
private:
	explicit CMagicCircle(LPDIRECT3DDEVICE9 pGraphic_Device);
	CMagicCircle(const CMagicCircle& rhs);
	virtual ~CMagicCircle() = default;
	typedef struct Effect3
	{
		CTransform* TargetTransform = nullptr;
		_float		Delay =0.f;
		_int		BulltType = 0;

	}EFFECT3;
public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

public:
	

private:
	HRESULT SetUp_Components();

private:
	CTransform*			pTargetTransform = nullptr;
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
private:
	EFFECT3	MyType;
	_uint ImgNum = 0;
	_float	Delay = 1.5f;
	_int	Page = 0;
	_int	m_Texture = 0;
public:
	static CMagicCircle* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END