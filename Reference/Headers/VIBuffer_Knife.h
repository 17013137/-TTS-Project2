#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_Knife final : public CVIBuffer
{
protected:
	explicit CVIBuffer_Knife(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_Knife(const CVIBuffer_Knife& rhs);
	virtual ~CVIBuffer_Knife() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	static CVIBuffer_Knife* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END