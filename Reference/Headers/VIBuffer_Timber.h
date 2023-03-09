#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_Timber final : public CVIBuffer
{
protected:
	explicit CVIBuffer_Timber(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_Timber(const CVIBuffer_Timber& rhs);
	virtual ~CVIBuffer_Timber() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	static CVIBuffer_Timber* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END