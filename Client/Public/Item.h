#pragma once

#include "Client_Defines.h"
#include "BlendObject.h"


BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
class CVIBuffer_Rect;
class CStatus;
class CInventory;
END

BEGIN(Client)

class CItem final : public CBlendObject
{
private:
	enum ITEM_TYPE { RIFLEAMMO, SHOTGUNAMMO, PISTOLAMMO, MEDICKIT, COIN1, COIN2, FOOD1, FOOD2, FOOD3, FOOD4, FOOD5, DRINK, POISON, ITEM_END };
	explicit CItem(LPDIRECT3DDEVICE9 pGraphic_Device);
	CItem(const CItem& rhs);
	virtual ~CItem() = default;
public:
	typedef struct BulletType
	{
		_float3		Pos = _float3{ 0.f, 0.f, 0.f };
		_float3		Target = _float3{ 0.f, 0.f, 0.f };;
		_int		BulltType = 0;

	}BULLETTYPE;
	virtual HRESULT NativeConstruct_Prototype();
	virtual HRESULT NativeConstruct(void* pArg);
	virtual _int Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

private:
	/* �����δ�.(���¸� ǥ���Ѵ�.) */
	CTransform*			m_pTransformCom = nullptr;
	
	/* �������� �׸�����?! (��) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* �� ������ � �ؽ��� �ø�����?! */
	CTexture*			m_pTextureCom = nullptr;

	/* �׸���!!! */
	CRenderer*			m_pRendererCom = nullptr;

	CTransform*			m_TargetTransformCom = nullptr;
	CStatus*			m_TargetStatusCom = nullptr;
	CInventory*			m_TargetInventoryCom = nullptr;

private:
	ITEM_TYPE				Item;
	BULLETTYPE				MyType;
	_int				m_Texture = 0;
	_float				LifeTime = 20.f;
	_bool				Falling = true;

	_float3  vStartPos;   // �����
	_float3  vEndPos;    //������
	_float3  vPos;         // ���� ��ġ.
	
	_float fV_X;   // X������ �ӵ�
	_float fV_Y;   // Y������ �ӵ�
	_float fV_Z;   // Z������ �ӵ�
	_float fg;                         // Y�������� �߷°��ӵ� (9.8�ƴ� �ؿ��� ������)

	_float fEndTime;              // �������� ���� �ð�
	_float fMaxHeight;      // �ִ� ����
	_float fHeight;                   //  �ִ������ Y - ���۳����� Y
	_float fEndHeight;              // �������� ���� Y - �������� ���� Y
	_float fTime = 0.f;          // �帣�� �ð�.
	_float fMaxTime;      // �ִ���� ���� ���� �ð�. �����ش�. 
private:
	HRESULT SetUp_Components();



public:
	static CItem* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END