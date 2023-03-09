#pragma once

#include "Component.h"

/* 객체의 월드상태를 표현하는 월드행렬을 가지고 있는다. */
/* 객체에게 필요한 월드 변환의 기능을 가진다. (직진, 후진, 회전 ) */

BEGIN(Engine)
class CTransform;

class ENGINE_DLL CStatus final : public CComponent
{
public:
	enum STATUS_STATE { STATUS_STATE_DEFAULT, STATUS_STATE_DOWN, STATUS_STATE_DEAD,STATUS_STATE_HIT, STATUS_STATE_END };
	enum ATTACK_TYPE { ATTACK_DEFAULT, ATTACK_PUSH, ATTACK_KNOCKBACK, ATTACK_TYPE_FIRE, ATTACK_TYPE_END };
	enum HIT_STATE { HIT_STATE_DEFAULT, HIT_STATE_PUSH, HIT_STATE_KNOCKBACK, HIT_STATE_FIRE, HIT_STATE_TYPE_END };
public:
	typedef struct tagStatusDesc
	{
		_float			fMaxHp = 0.f;;
		_float			fMaxStamina = 0.f;;
		_float			fMaxStungauge = 0.f;
		_float			fDamage = 0.f;
		_float			fPower = 0.f;
		_float			frange = 0.f;
		_float3			fSpawnPos = _float3{ 0.f, 0.f, 0.f };
		_float3			fLook = _float3{ 0.f, 0.f, 0.f };
		ATTACK_TYPE		Attacktype = ATTACK_DEFAULT;
		CTransform*		Transform_Com = nullptr;
	}STATUSDESC;

private:
	_float			Hp;
	_float			fStamina;
	_float			fStungauge;
	STATUS_STATE	m_State = STATUS_STATE_DEFAULT;

	HIT_STATE		m_HitState = HIT_STATE_DEFAULT;
	_bool			ActionOn = true;
	_bool			ActionStamina = true;
	_bool			m_bStamina_Timer = false;
	_bool			Knockback		 = true;
	_bool			LookOn = true;
	_float			m_HitPower = 0.f;
	_float3			m_PushPos;
private:
	explicit CStatus(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CStatus(const CStatus& rhs);
	virtual ~CStatus() = default;

public:
	STATUSDESC		m_Status;
	STATUS_STATE	Get_State() {
		return m_State;
	}
public:
	void			Set_Damage(ATTACK_TYPE AttackType, _float Damage, _float HitPower = 0.f, _float3 PushPos = _float3(0.f,0.f,0.f));
	_bool			PlayAction(_float Action_Stamina);
	void			Set_Stungauge(_float Damage);
	_int			Status_Tick(_float fTimeDelta);
	void			fStamina_Timer(_float fTimeDelta);
	void			Heal(_float Heal) {
		Hp += Heal;
		if (Hp > m_Status.fMaxHp)
			Hp = m_Status.fMaxHp;
	}
	void			Heal_Stamina(_float Stamina) {
		fStamina += Stamina;
		if (fStamina > m_Status.fMaxStamina)
			fStamina = m_Status.fMaxStamina;
	}
	HIT_STATE			Get_HitState() {
		return m_HitState;
	}

	_float*			Get_pHp() {
		return &Hp;
	}

	_float*			Get_pStamina() {
		return &fStamina;
	}

	_float*			Get_pStungauge() {
		return &fStungauge;
	}
	void			Set_Dead()
	{
		if (fStamina > 1000)
		{
			Hp = -100.f;
			m_State = STATUS_STATE_DEAD;
	}

	}
	void	Knockback_off() {
		Knockback = false;
	}
	void	Knockback_on() {
		m_HitPower = 0;

		Knockback = true;
	}
	void	Look_Off() {
		LookOn = false;
	}
	void	Look_On() {
		m_HitPower = 0;

		LookOn = true;
	}

	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);

public:
	static CStatus* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END