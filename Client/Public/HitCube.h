#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Cube;
class CStatus;
class CGameInstance;
END

BEGIN(Client)

class CHitCube final : public CGameObject
{
private:
	typedef struct Effect4
	{
		_float3		Pos		= _float3{ 0.f, 0.f, 0.f };
		_float3		Target	= _float3{ 0.f, 0.f, 0.f };;
		_float		Speed	= 3.f;
		_int		BulltType = 0;

	}EFFECT4;
	explicit CHitCube(LPDIRECT3DDEVICE9 pGraphic_Device);
	CHitCube(const CHitCube& rhs);
	virtual ~CHitCube() = default;

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
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;

	/* �� ������ � �ؽ��� �ø�����?! */
	CTexture*			m_pTextureCom = nullptr;

	/* �׸���!!! */
	CRenderer*			m_pRendererCom = nullptr;

	CStatus*			m_pStatusCom = nullptr;

	CGameInstance*		pGameInstance = nullptr;
private:
	HRESULT SetUp_Components(void * pArg);



public:
	static CHitCube* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END