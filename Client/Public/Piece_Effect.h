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

class CPiece_Effect final : public CGameObject
{
private:
	explicit CPiece_Effect(LPDIRECT3DDEVICE9 pGraphic_Device);
	CPiece_Effect(const CPiece_Effect& rhs);
	virtual ~CPiece_Effect() = default;
public:
	typedef struct Effect4
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_float		Speed = 3.f;
		_int		BulltType = 0;

	}EFFECT4;
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* 움직인다.(상태를 표현한다.) */
	CTransform*			m_pTransformCom = nullptr;
	
	/* 어떤모양으로 그릴건지?! (모델) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* 저 모델위에 어떤 텍스쳐 올릴건지?! */
	CTexture*			m_pTextureCom = nullptr;

	/* 그린다!!! */
	CRenderer*			m_pRendererCom = nullptr;



private:
	
	EFFECT4				MyType;
	_int				m_Texture = 0;

	_float3  vStartPos;   // 출발지
	_float3  vEndPos;    //목적지
	_float3  vPos;         // 현지 위치.
	
	_float fV_X;   // X축으로 속도
	_float fV_Y;   // Y축으로 속도
	_float fV_Z;   // Z축으로 속도
	_float fg;                         // Y축으로의 중력가속도 (9.8아님 밑에서 구해줌)

	_float fEndTime;              // 도착지점 도달 시간
	_float fMaxHeight;      // 최대 높이
	_float fHeight;                   //  최대높이의 Y - 시작높이의 Y
	_float fEndHeight;              // 도착지점 높이 Y - 시작지점 높이 Y
	_float fTime = 0.f;          // 흐르는 시간.
	_float fMaxTime;      // 최대높이 까지 가는 시간. 정해준다. 
private:
	HRESULT SetUp_Components();



public:
	static CPiece_Effect* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END