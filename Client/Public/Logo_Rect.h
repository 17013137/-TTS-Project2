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

class CLogo_Rect final : public CGameObject
{
private:
	explicit CLogo_Rect(LPDIRECT3DDEVICE9 pGraphic_Device);
	CLogo_Rect(const CLogo_Rect& rhs);
	virtual ~CLogo_Rect() = default;

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
	_float4x4			m_ProjMatrix;
	_float				m_fX, m_fY, m_fSizeX, m_fSizeY;

	_float				m_fFrame;
	_float				MaxfFrame;

private:
	HRESULT SetUp_Components();



public:
	static CLogo_Rect* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END