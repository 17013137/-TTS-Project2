#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_Pistol final : public CVIBuffer
{
protected:
	explicit CVIBuffer_Pistol(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_Pistol(const CVIBuffer_Pistol& rhs);
	virtual ~CVIBuffer_Pistol() = default;

public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:
	static CVIBuffer_Pistol* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END