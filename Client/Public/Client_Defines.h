#pragma once

namespace Client
{
	const unsigned int	g_iWinCX = 1280;
	const unsigned int	g_iWinCY = 720;

	enum LEVEL { LEVEL_STATIC, LEVEL_LOADING, LEVEL_LOGO, LEVEL_SHELTER, LEVEL_STORE, LEVEL_GAMEPLAY, LEVEL_FOREST, LEVEL_CAVE, LEVEL_CITY, LEVEL_EVENT, LEVEL_HELL, LEVEL_BOSS, LEVEL_END };
}

#include <process.h>
#define		VK_MAX		0xff
extern HINSTANCE g_hInst;
extern HWND g_hWnd;

using namespace Client;

/*

class CMainApp
{
private:
������
�Ҹ���

public:
Getter();
Setter();

public:
�Լ�

protected:
����
protected:
�Լ�

private:
����
private:
�Լ�

public:
�������õ��Լ� (Create)
�������õ��Լ� (Free)
};


*/

