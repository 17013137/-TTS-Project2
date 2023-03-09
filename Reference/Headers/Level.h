#pragma once

#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CLevel abstract : public CBase
{
protected:
	explicit CLevel(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLevel() = default;

public:
	virtual HRESULT NativeConstruct();
	virtual void Tick(_float fTimeDelta);
	virtual HRESULT Render();

public:
	HRESULT Load_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX);
	HRESULT Load_Tile_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX);
	HRESULT Load_Cube_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX);
	HRESULT Load_Deco_Data(const TCHAR* pTilePath, _uint LEVEL_INDEX);

protected:
	LPDIRECT3DDEVICE9			m_pGraphic_Device = nullptr;
	vector<_float2> BoxsPos[80][80];
	_uint m_LevelIndex = -1;
	_bool m_MonsterClear = false;
	_bool m_ObeliskClear = false;
public:
	virtual void Free() override;
};

END