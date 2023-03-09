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
END

BEGIN(Client)

class CBullet final : public CGameObject
{
private:
	explicit CBullet(LPDIRECT3DDEVICE9 pGraphic_Device);
	CBullet(const CBullet& rhs);
	virtual ~CBullet() = default;
	enum BULLET { BULLET_RIFLE, BULLET_SHOTGUN, BULLET_PISTOL, BULLET_ZOMBIE, BULLET_END };
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

	_float				m_delay = 0.f;
	_float				m_Range = 10.f;
	_float3				m_Pos;
	_int				m_Texture = 0;
	BULLET				m_BulletType = BULLET_RIFLE;

private:
	HRESULT SetUp_Components(void * pArg);



public:
	static CBullet* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END