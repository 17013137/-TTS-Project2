#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer; 
class CTransform;
class CVIBuffer_Cone;
class CGameInstance;
class CStatus;
END

BEGIN(Client)

class CCone final : public CGameObject
{
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;
private:
	enum STATE { STATE_STAY, STATE_WALK, STATE_RUN, STATE_FIND, STATE_MOVE, STATE_ATTACK, STATE_FALLING, STATE_DOWN, STATE_UP, STATE_END };
	explicit CCone(LPDIRECT3DDEVICE9 pGraphic_Device);
	CCone(const CCone& rhs);
	virtual ~CCone() = default;
public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;

	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Cone*		m_pVIBufferCom = nullptr;

	/* 그린다!!! */
	CRenderer*			m_pRendererCom = nullptr;

	CTexture*			m_pTextureCom = nullptr;

	CStatus*			m_pStatusCom = nullptr;
	CGameInstance*		 pGameInstance = nullptr;
private:
	void Falling(_float fTimeDelta);
	void Down(_float fTimeDelta);
	HRESULT SetUp_Components();
	_float	AnTime = 0.f;
	_float	AnFrame;
	STATE	State = STATE_STAY;
	_bool	Action = false;
	_float3	MyPos;
	_float Time =0;
public:
	static CCone* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END