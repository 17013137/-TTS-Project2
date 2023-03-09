#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CSubTransform;
class CVIBuffer_Cube;
class CVIBuffer_Rect;
END

class CGateCube final : public CGameObject
{
private:
	explicit CGateCube(LPDIRECT3DDEVICE9 pGraphic_Device);
	CGateCube(const CGateCube& rhs);
	virtual ~CGateCube() = default;

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

	//¸»Ç³¼±
private:
	CTransform*			m_vTFTalkBox = nullptr;
	CVIBuffer_Rect*		m_vVITalkBox = nullptr;
	CTexture*			m_vTTTalkBox = nullptr;
	CRenderer*			m_vRDTalkBox = nullptr;


private:
	_float3			m_Player_Pos;

private:
	_bool m_MapOn = false;
private:
	HRESULT SetUp_Components();


public:
	static CGateCube* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};
