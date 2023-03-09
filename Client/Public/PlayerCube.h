#pragma once

#include "Client_Defines.h"
#include "GameObject.h"
#include "Status.h"
#include "Inventory.h"
//#include "BlendObject.h"
BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CStatus;
class CVIBuffer_Cube;
class CSubTransform;
class CVIBuffer_Rect;
class CVIBuffer_Knife;
class CVIBuffer_Rifle;
class CVIBuffer_Pistol;
class CVIBuffer_Rect;
//class CStatus::STATUSDESC;
END

BEGIN(Client)

class CPlayerCube final : public CGameObject
{
public:
	enum STATE { STATE_STAY, STATE_WALK, STATE_RUN, STATE_ROLL, STATE_RDTHROW, STATE_THROW, STATE_ATTACK, STATE_FALLING, STATE_DOWN, STATE_UP, STATE_END };
	enum ANGLE { ANGLE_STRAIGHE, ANGLE_BACK, ANGLE_RIGHT, ANGLE_LEFT, ANGLE_STRAIGHERIGHT, ANGLE_STRAIGHELEFT, ANGLE_BACKRIGHT, ANGLE_BACKLEFT, ANGLE_END};
	enum WALK { WALK_STRAIGHE, WALK_BACK, WALK_RIGHT, WALK_LEFT, WALK_STRAIGHERIGHT, WALK_STRAIGHELEFT, WALK_BACKRIGHT, WALK_BACKLEFT, WALK_END };
	enum HAND { HAND_EMPTY, HAND_RIFLE, HAND_SHOTGUN, HAND_PISTOL, HAND_WEAPON, HAND_GRENADE, HAND_END };

	typedef struct TargetPos
	{
		_float3		Pos;
		_float3		target;
	}TARGETPOS;
	

private:
	explicit CPlayerCube(LPDIRECT3DDEVICE9 pGraphic_Device);
	CPlayerCube(const CPlayerCube& rhs);
	virtual ~CPlayerCube() = default;

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

	void Rolling(_float fTimeDelta);
	void Falling(_float fTimeDelta);
	void Down(_float fTimeDelta);
	void Up(_float fTimeDelta);
	
	HRESULT Throw(_float fTimeDelta);
	void Attack(_float fTimeDelta);
	void Stay(_float fTimeDelta);

private:
	HRESULT SetUp_Components();
	void SetUp_OnTerrain();

private:
	CInventory::INVENTORYDESC*		InventorymDesc = nullptr;
	_bool isDied = false;
	_float	AnTime = 0.f;
	_float	StandardAnTime = 0.f;
	_float	AnFrame;
	_float3	MyPos;
	STATE	State = STATE_STAY;
	HAND	CurrentHand = HAND_EMPTY;
	HAND	HandState = HAND_EMPTY;
	ANGLE	CurrentAngle = ANGLE_STRAIGHE;
	ANGLE	AngleState = ANGLE_STRAIGHE;
	WALK	CurrentWalk;
	WALK	WalkState;
	_float3	vAngle[8];
	_bool	key = false;
	_bool	AttackOn = true;
	_float  Gundelay = 0.f;
	_float3 GunPos;
	_float3 GunLook;
	//_float3 Down;
	_bool	CheatMod = false;
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
	//그림자

	//부위별
	vector<CVIBuffer_Cube*>		m_vVI;
	vector<CSubTransform*>		m_vTF;
	vector<CTexture*>			m_vTT;
	vector<CRenderer*>			m_vRD;

	//무기(Rifle)
	CSubTransform*			m_vTFRifle = nullptr;
	CVIBuffer_Rifle*		m_vVIRifle = nullptr;
	CTexture*				m_vTTRifle = nullptr;
	CRenderer*				m_vRDRifle = nullptr;

	//무기(ShotGun)
	CSubTransform*			m_vTFShotGun = nullptr;
	CVIBuffer_Cube*			m_vVIShotGun = nullptr;
	CTexture*				m_vTTShotGun = nullptr;
	CRenderer*				m_vRDShotGun = nullptr;

	//무기(Pistol)
	CSubTransform*			m_vTFPistol = nullptr;
	CVIBuffer_Pistol*		m_vVIPistol = nullptr;
	CTexture*				m_vTTPistol = nullptr;
	CRenderer*				m_vRDPistol = nullptr;

	//무기(Timber)
	CSubTransform*			m_vTFTimber = nullptr;
	CVIBuffer_Knife*		m_vVITimber = nullptr;
	CTexture*				m_vTTTimber = nullptr;
	CRenderer*				m_vRDTimber = nullptr;

	//무기(Grenade)
	CSubTransform*			m_vTFGrenade = nullptr;
	CVIBuffer_Cube*			m_vVIGrenade = nullptr;
	CTexture*				m_vTTGrenade = nullptr;
	CRenderer*				m_vRDGrenade = nullptr;

	//_uint ViewCnt = 0;

	

public:
	static CPlayerCube* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;


	
};

END