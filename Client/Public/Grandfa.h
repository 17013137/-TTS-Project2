#pragma once

#include "Client_Defines.h"
#include "GameObject.h"
#include "Status.h"
//#include "BlendObject.h"
BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CStatus;
class CInventory;
class CVIBuffer_Cube;
class CSubTransform;
class CVIBuffer_Rect;
class CVIBuffer_Timber;
class CVIBuffer_Rifle;
class CVIBuffer_Pistol;
class CVIBuffer_Rect;
//class CStatus::STATUSDESC;
END

BEGIN(Client)

class CNPC_Grandfa final : public CGameObject
{
public:
	enum STATE { STATE_STAY, STATE_WALK, STATE_RUN, STATE_ROLL, STATE_RDTHROW, STATE_THROW, STATE_ATTACK, STATE_FALLING, STATE_DOWN, STATE_UP, STATE_END };
	enum HAND { HAND_EMPTY, HAND_RIFLE, HAND_SHOTGUN, HAND_PISTOL, HAND_WEAPON, HAND_GRENADE, HAND_END };

	typedef struct TargetPos
	{
		_float3		Pos;
		_float3		target;
	}TARGETPOS;


private:
	explicit CNPC_Grandfa(LPDIRECT3DDEVICE9 pGraphic_Device);
	CNPC_Grandfa(const CNPC_Grandfa& rhs);
	virtual ~CNPC_Grandfa() = default;

public:
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

	void Set_Part(int Part, int Local, _float3 Pos);
	void Set_Part2(CSubTransform* Part, _float3 Pos);

	void Set_Stay();

	void Run(_float fTimeDelta);
	void Walk(_float fTimeDelta);

	void Falling(_float fTimeDelta);
	void Down(_float fTimeDelta);
	void Up(_float fTimeDelta);


	void Attack(_float fTimeDelta);
	void Stay(_float fTimeDelta);

private:
	HRESULT SetUp_Components();
	HRESULT SetUp_OnTerrain();

private:
	_float	AnTime = 0.f;
	_float	StandardAnTime = 0.f;
	_float	AnFrame;

	STATE	State = STATE_STAY;
	HAND	CurrentHand = HAND_EMPTY;
	HAND	HandState = HAND_EMPTY;
	_bool	key = false;
	_bool	AttackOn = true;
	//_float3 Down;

	TARGETPOS			TargetPos;
	_bool				m_isChase = false;
	//유탄 준비
	_bool				Grenade = false;
	_float3				m_vTargetPos;

	//메인
	CTransform*			m_pTransformCom = nullptr;
	CVIBuffer_Cube*		m_pVIBufferCom = nullptr;
	CTexture*			m_pTextureCom = nullptr;
	CRenderer*			m_pRendererCom = nullptr;
	CStatus*			m_pStatusCom = nullptr;
	CInventory*			m_pInventoryCom = nullptr;


	//부위별
	vector<CVIBuffer_Cube*>		m_vVI;
	vector<CSubTransform*>		m_vTF;
	vector<CTexture*>			m_vTT;
	vector<CRenderer*>			m_vRD;


	//무기(Pistol)
	CSubTransform*			m_vTFPistol = nullptr;
	CVIBuffer_Pistol*		m_vVIPistol = nullptr;
	CTexture*				m_vTTPistol = nullptr;
	CRenderer*				m_vRDPistol = nullptr;
	//_uint ViewCnt = 0;



public:
	static CNPC_Grandfa* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;



};

END