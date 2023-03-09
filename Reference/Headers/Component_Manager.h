#pragma once

#include "Texture.h"
#include "Renderer.h"
#include "Status.h"
#include "Transform.h"
#include "SubTransfrom.h"
#include "Inventory.h"
#include "Light.h"
#include "Engine_VIBuffers.h"


/* ������Ʈ���� ������ ��Ƶд�. */

BEGIN(Engine)

class CComponent_Manager final : public CBase
{
	DECLARE_SINGLETON(CComponent_Manager)
private:
	CComponent_Manager();
	virtual ~CComponent_Manager() = default;

public:
	HRESULT Reserve_Manager(_uint iNumLevels);
	HRESULT Add_Prototype(_uint iLevelIndex, const _tchar* pPrototypeTag, CComponent* pPrototype);
	CComponent* Clone_Component(_uint iLevelIndex, const _tchar* pPrototypeTag, void* pArg);
public:
	HRESULT Set_TextureCom(_uint TexLevelIndex, const _tchar* _RendererTag, const _tchar* CloneCubeTexTag, const _tchar* CloneTileTexTag);

private:
	_uint											m_iNumLevels = 0;
	map<const _tchar*, CComponent*>*				m_pPrototypes = nullptr;
	typedef map<const _tchar*, CComponent*>			PROTOTYPES;

private:
	CComponent* Find_Prototype(_uint iLevelIndex, const _tchar* pPrototypeTag);

public:
	virtual void Free() override;
};

END