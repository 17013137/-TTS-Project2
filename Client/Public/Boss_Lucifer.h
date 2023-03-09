#pragma once

#include "Client_Defines.h"
#include "BlendObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Cube;
class CSubTransform;
class CStatus;
class CGameInstance;
END

BEGIN(Client)

class CBoss_Lucifer final : public CBlendObject
{
public:
	typedef struct BulletType
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_int		BulltType = 0;

	}BULLETTYPE;
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;

	typedef struct Effect3
	{
		CTransform* TargetTransform = nullptr;
		_float		Delay = 1.f;
		_int		BulltType = 0;

	}EFFECT3;


	enum STATE { STATE_STAY, STATE_LOCKON, STATE_LASER, STATE_WALK, STATE_MISSILE, STATE_PAGE, STATE_HAND, STATE_ATTACK, STATE_FALLING, STATE_DOWN, STATE_UP, STATE_END };
private:

	explicit CBoss_Lucifer(LPDIRECT3DDEVICE9 pGraphic_Device);
	CBoss_Lucifer(const CBoss_Lucifer& rhs);
	virtual ~CBoss_Lucifer() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();
	void Set_Part(int Part, int Local, _float3 Pos);
private:
	CGameInstance*		pGameInstance = nullptr;
	CTransform*			pTargetTransform = nullptr;

	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;
	CStatus*			m_pStatusCom = nullptr;

	CSubTransform*		m_pTransformComLaser = nullptr;
	CVIBuffer_Cube*		m_pVIBufferComLaser = nullptr;
	CTexture*			m_pTextureComLaser = nullptr;
	CRenderer*			m_pRendererComLaser = nullptr;

	vector<CVIBuffer_Cube*>		m_vVI;
	vector<CSubTransform*>		m_vTF;
	vector<CTexture*>			m_vTT;
	vector<CRenderer*>			m_vRD;
	_float		AnTime = 0.f;
	_float		PTime = 0.f;
	_float		StandardAnTime = 0.f;
	_float		AnFrame;
	STATE		State = STATE_END;
	_bool		Action = false;
	_bool		AttackOn = true;
	_int		Stack = 1;

	_int m_iPage2Cnt;
	_int m_iPage3Cnt;


	_float		SkillDelay = 1.f;

	_float		Meteor_Time = 7.f;
	_float		MeteorDelay = 0;
	_bool		MeteorCircle = false;

	_float		Missile_Time = 7.f;
	_float		MissileDelay = 0;

	_float		Laser_Time = 10.f;
	_bool		bLaser = false;
	_int		iLaser = 0;

	_float		Attack_Time = 3.f;
	_float		Attack_frange;

	_float		frange;

	_bool		Page2 = false;
	_int		Face = 0;
	_float3    RHandPos;
	_float3    LHandPos;
	_float3    HeadPos;
	_float3		MyPos;
private:
	HRESULT SetUp_Components();
	/*
	0	¸Ó¸®
	1	¸öÅë
	2	ÇÏÃ¼
	3	¿À¸¥¼Õ
	4	¿Þ¼Õ
	5	¿À¸¥¾î±ú
	6	¿Þ¾î±ú
	7~12 ³¯°³
	*/

	void Set_Stay();

	void Falling(_float fTimeDelta);
	void Down(_float fTimeDelta);
	void Up(_float fTimeDelta);

	void Page(_float fTimeDelta);
	void Meteor(_float fTimeDelta);
	void Missile(_float fTimeDelta);
	void Laser(_float fTimeDelta);
	void Attack(_float fTimeDelta);
	void Move(_float fTimeDelta);
	void Stay(_float fTimeDelta);
	void HandAction(_float fTimeDelta);

	int ActionMoving(_float fTimeDelta);
public:
	static CBoss_Lucifer* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END