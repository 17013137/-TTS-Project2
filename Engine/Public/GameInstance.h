#pragma once

#include "Graphic_Device.h"
#include "Input_Device.h"
#include "Level_Manager.h"
#include "Object_Manager.h"
#include "Component_Manager.h"
#include "Timer_Manager.h"
#include "Picking.h"
#include "Frustum.h"

/* 클라이언트에 보여줘야할 인터페이스를 보관하고. 보여준다. */

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)
private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public: /* For.GameInstance */
	HRESULT Initialize_Engine(HINSTANCE hInst, _uint iNumLevels, CGraphic_Device::GRAPHICDESC GraphicDesc, LPDIRECT3DDEVICE9* ppGraphic_Device);
	void Tick_Engine(_float fTimeDelta);
	HRESULT Render_Engine();
	HRESULT Clear_LevelResource(_uint iLevelIndex);


public: /* For.Graphic_Device */
	void Render_Begin(void);
	void Render_End();

public: /* For.Input_Device */
	_char Get_DIKeyState(_uchar byKeyID);
	_char Get_DIMButtonState(CInput_Device::MOUSEBUTTONSTATE eDIMBState);
	_long Get_DIMMoveState(CInput_Device::MOUSEMOVESTATE eDIMMState);

public: /* For.Timer_Manager */
	HRESULT Add_Timers(const _tchar* pTimerTag);
	_double Compute_TimeDelta(const _tchar* pTimerTag);

public: /* For.Level_Manager */
	HRESULT Open_Level(_uint iLevelIndex, class CLevel* pLevel);
	_uint Get_LevelIndex();
	void Set_LevelIndex(_uint _index);

public: /* For.Object_Manager */
	CComponent* Get_Component(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pComponentTag, _uint iIndex = 0);
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype);
	HRESULT Add_GameObjectToLayer(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pPrototypeTag, void* pArg = nullptr);
	_bool Collison_Sheare(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	_bool Collison_Knockback(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	_bool Collison_Rect(_uint iLevelIndex, const _tchar* pDistLayerTag, const _tchar* pTargetLayerTag);
	_bool SuperCollison_Rect(_uint iLevelIndex, const _tchar* pDistLayerTag, vector<_float2> _BoxsPos[80][80]);
	_bool Check_EmptyLayer(_uint iLevelIndex, const _tchar * pLayerTag);


public: /* For.Component_Manager */
	HRESULT Add_Prototype(_uint iLevelIndex, const _tchar* pPrototypeTag, CComponent* pPrototype);
	CComponent* Clone_Component(_uint iLevelIndex, const _tchar* pPrototypeTag, void* pArg = nullptr);
	HRESULT Set_TextureCom(_uint TexLevelIndex, const _tchar* _RendererTag, const _tchar* CloneCubeTexTag, const _tchar* CloneTileTexTag);


public: //LevelChange
	void Set_BasicLoad() { m_Check_BasicLoad = true; }
	_bool Get_BasicLoad() { return m_Check_BasicLoad; }

private:
	CGraphic_Device*			m_pGraphic_Device = nullptr;
	CInput_Device*				m_pInput_Device = nullptr;
	CLevel_Manager*				m_pLevel_Manager = nullptr;
	CObject_Manager*			m_pObject_Manager = nullptr;
	CComponent_Manager*			m_pComponent_Manager = nullptr;
	CTimer_Manager*				m_pTimer_Manager = nullptr;
	CPicking*					m_pPicking = nullptr;
	CFrustum*					m_pFrustum = nullptr;
	_bool						m_Check_BasicLoad = false;
public:
	static void Release_Engine();
	virtual void Free() override;

};

END