#pragma once


namespace Engine
{


	typedef unsigned char					_uchar;
	typedef signed char						_char;

	typedef unsigned short					_ushort;
	typedef signed short					_short;

	typedef unsigned int					_uint;
	typedef signed int						_int;

	typedef unsigned long					_ulong;
	typedef signed long						_long;

	typedef float							_float;
	typedef double							_double;

	typedef wchar_t							_tchar;

	typedef bool							_bool;

	typedef D3DXVECTOR2						_float2;

	typedef D3DXVECTOR3						_float3;

	typedef D3DXVECTOR4						_float4;

	typedef D3DXMATRIX						_float4x4;

	enum ENUMOBJ { NormalZombie, Barricade2, Cone, Door, Drawer, Tree, Wood, Window, GateCube, ZombieSpitter, PurpleGate, SoulFire, BlueSkeleton, GrandfaSkeleton, Fanatic, Wither_Skeleton, OBJ_END };
	static const _tchar* enum_str[] = { L"NormalZombie", L"Barricade2", L"Cone", L"Door",L"Drawer",  L"Tree" , L"Wood",L"Window", L"GateCube", L"ZombieSpitter", L"PurpleGate", L"SoulFire", L"Blue_Skeleton", L"Granpa_Skeleton", L"Fanatic", L"Wither_skeleton2", L"End" };
	static const _tchar* cube_str[] = { L"CollisonCube", L"Cube", L"invisibleCube", L"End" };
	static const _tchar* blend_str[] = { L"XRECT", L"YRECT" };

	typedef struct OJBDATA {
		_uint ObjID;
		_float4x4 WorldMTX;
	}OBJDATA;

	typedef struct Effect_Type
	{
		int		Type;
		D3DXVECTOR3		Target;
		D3DXVECTOR3		Pos;
		float		Power;
	}EFFECTTYPE;

	typedef struct WALLDATA {
		_uint isBlock;
		_uint TexID;
		_float4x4 WorldMTX;
	}WALLDATA;
}