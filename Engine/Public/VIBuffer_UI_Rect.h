#pragma once

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer_UI_Rect final : public CVIBuffer
{
protected:
	explicit CVIBuffer_UI_Rect(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CVIBuffer_UI_Rect(const CVIBuffer_UI_Rect& rhs);
	virtual ~CVIBuffer_UI_Rect() = default;
public:
	virtual HRESULT NativeConstruct_Prototype() override;
	virtual HRESULT NativeConstruct(void* pArg) override;

public:

	static CVIBuffer_UI_Rect* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CComponent* Clone(void* pArg);
	virtual void Free() override;
};

END