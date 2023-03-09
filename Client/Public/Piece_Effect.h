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
	/* �����δ�.(���¸� ǥ���Ѵ�.) */
	CTransform*			m_pTransformCom = nullptr;
	
	/* �������� �׸�����?! (��) */
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;	

	/* �� ������ � �ؽ��� �ø�����?! */
	CTexture*			m_pTextureCom = nullptr;

	/* �׸���!!! */
	CRenderer*			m_pRendererCom = nullptr;



private:
	
	EFFECT4				MyType;
	_int				m_Texture = 0;

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
	static CPiece_Effect* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;
};

END