#include "..\Public\Status.h"
#include "Transform.h"




CStatus::CStatus(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device)
	
{
}

CStatus::CStatus(const CStatus & rhs)
	: CComponent(rhs)

{
}


void CStatus::Set_Damage(ATTACK_TYPE AttackType, _float Damage, _float HitPower, _float3 PushPos)
{
	Hp -= Damage;
	m_HitState = (HIT_STATE)AttackType;
	m_HitPower = m_HitPower+HitPower;
	m_PushPos = PushPos;
	if (m_HitState== ATTACK_KNOCKBACK)
	{
		m_Status.Transform_Com->Look(-m_PushPos);
		m_State = STATUS_STATE_HIT;
		
	}
	else if (m_HitState == ATTACK_PUSH)
	{
		_float3 MyLook;
		_float3 m_Push;
		D3DXVec3Normalize(&m_Push, &-m_PushPos);
		D3DXVec3Normalize(&MyLook, &(m_Status.Transform_Com->Get_State(CTransform::STATE_LOOK)));

		_float TargetAngle = acos(D3DXVec3Dot(&m_Push, &MyLook)) * (180 / 3.14f);
		if(TargetAngle>30.f && LookOn == true )
			m_Status.Transform_Com->Look(m_Push);

		m_State = STATUS_STATE_HIT;
	}
}

_bool CStatus::PlayAction(_float Action_Stamina)
{
	if (fStamina >= Action_Stamina && ActionStamina ==true)
	{
		fStamina -= Action_Stamina;
		return true;
	}
	else
	{
		ActionStamina = false;
		return false;
	}
	return false;
}

void CStatus::Set_Stungauge(_float Stungauge)
{
	fStungauge -= Stungauge;

	if (fStungauge <= 0)
		m_State = STATUS_STATE_DOWN;
}

_int CStatus::Status_Tick(_float fTimeDelta)
{
	if (m_State != STATUS_STATE_DOWN)
	{
		if (m_HitState == HIT_STATE_PUSH && (m_HitPower > 0)&& Knockback==true)
		{
			_float3 Pos = m_Status.Transform_Com->Get_State(CTransform::STATE_POSITION);
			_float3	vPush = *D3DXVec3Normalize(&vPush, &m_PushPos) * m_HitPower;
			m_Status.Transform_Com->Set_State(CTransform::STATE_POSITION, Pos + vPush*fTimeDelta * 60);

			m_HitPower -= 0.1f*fTimeDelta * 60;
		}
		else if (m_HitState == HIT_STATE_KNOCKBACK && m_HitPower > 0 && Knockback == true)
		{
			_float3 Pos = m_Status.Transform_Com->Get_State(CTransform::STATE_POSITION);
			_float3	vPush = *D3DXVec3Normalize(&vPush, &m_PushPos) * m_HitPower;
			m_Status.Transform_Com->Set_State(CTransform::STATE_POSITION, Pos + vPush*fTimeDelta * 60);
			//m_Status.Transform_Com->Look(-m_PushPos);
			m_HitPower -= 0.1f*fTimeDelta * 60;
			ActionOn = false;
		}
	}
	if (Hp <= 0)
	{
		Hp = -1;
		m_State = STATUS_STATE_DEAD;
		return m_State;
	}
	else if (fStungauge <= 0)
	{
		m_State = STATUS_STATE_DOWN;
		ActionOn = false;
	}

	if (m_Status.fMaxStamina> fStamina|| m_bStamina_Timer != false)
		fStamina += 7.f*fTimeDelta ;

	if (m_Status.fMaxStamina<= fStamina )
		ActionStamina = true;
	

	if (fStungauge == m_Status.fMaxStungauge && m_HitPower <= 0&& m_State != STATUS_STATE_HIT)
	{
		m_HitPower = 0;
		ActionOn = true;
		m_State = STATUS_STATE_DEFAULT;
	}

	if (m_State == STATUS_STATE_HIT&&m_State != STATUS_STATE_DOWN)
	{
		m_State = STATUS_STATE_DEFAULT;
		return STATUS_STATE_HIT;
	}





	return m_State;
}

void CStatus::fStamina_Timer(_float fTimeDelta)
{
	fStungauge -= fTimeDelta*60;
	m_bStamina_Timer = false;

	if (fStungauge < 1)
		Hp = -1.f;
}

HRESULT CStatus::NativeConstruct_Prototype()
{



	return S_OK;
}

HRESULT CStatus::NativeConstruct(void * pArg)
{
	
	if (nullptr != pArg)
		memcpy(&m_Status, pArg, sizeof(STATUSDESC));

	Safe_AddRef(m_Status.Transform_Com);
	Hp = m_Status.fMaxHp;
	fStamina = m_Status.fMaxStamina;
	fStungauge = m_Status.fMaxStungauge;


	return S_OK;
}


CStatus * CStatus::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CStatus*	pInstance = new CStatus(pGraphic_Device);

	if (FAILED(pInstance->NativeConstruct_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created CStatus"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent * CStatus::Clone(void * pArg)
{
	CStatus*	pInstance = new CStatus(*this);

	if (FAILED(pInstance->NativeConstruct(pArg)))
	{
		MSG_BOX(TEXT("Failed to Created CStatus"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CStatus::Free()
{
	__super::Free();
	Safe_Release(m_Status.Transform_Com);
}
