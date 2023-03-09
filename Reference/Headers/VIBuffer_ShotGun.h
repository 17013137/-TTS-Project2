#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_ShotGun final : public CVIBuffer
{
protected:
	explicit CVIBuffer_ShotGun(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_ShotGun(const CVIBuffer_ShotGun& rhs);
	virtual ~CVIBuffer_ShotGun() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	static CVIBuffer_ShotGun* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END