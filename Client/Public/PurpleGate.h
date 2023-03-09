#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
class CStatus;

END

BEGIN(Client)

class CPurpleGate final : public CGameObject
{
	enum GATESTATE { Green, Red, Purple };
private:

	explicit CPurpleGate(LPDIRECT3DDEVICE9 pGraphic_Device);
	CPurpleGate(const CPurpleGate& rhs);
	virtual ~CPurpleGate() = default;


public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();
	void SetGreen() {
		state = Green;
	}
private:
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;
	CStatus*			m_pStatusCom = nullptr;

private:
	_float				m_fFrame = 0.f;
	_int				m_i = 1;

	_int				gap = 32;
private:
	_float3 m_Player_Pos;
private:
	HRESULT SetUp_Components();
	GATESTATE state = Red;
public:
	static CPurpleGate* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END