#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_Rifle final : public CVIBuffer
{
protected:
	explicit CVIBuffer_Rifle(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_Rifle(const CVIBuffer_Rifle& rhs);
	virtual ~CVIBuffer_Rifle() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	static CVIBuffer_Rifle* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END