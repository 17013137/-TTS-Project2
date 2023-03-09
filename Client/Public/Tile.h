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


class CTile final : public CGameObject
{
private:
	explicit CTile(LPDIRECT3DDEVICE9 pGraphic_Device);
	CTile(const CTile& rhs);
	virtual ~CTile() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

public:
	_bool Picking(_float3* _pickpos);

private:
	HRESULT SetUp_Components();

private:
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;

private:
	_uint ImgNum = 0;

public:
	static CTile* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END