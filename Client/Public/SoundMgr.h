#pragma once
#include "fmod.h"
#include "Engine_Defines.h"
#include "Client_Defines.h"

#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_DEFAULT 0.5f
#define SOUND_WEIGHT 0.1f

class CSoundMgr
{
public:
	static CSoundMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CSoundMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
public:
	enum CHANNELID {
		BGM1, BGM2, WEAPON_CHANGE, RELOAD, PLAYER_SHOT, PLAYER_BEATEN, PLAYER_DIE, PLAYER_WALK, DRINK, ROLLING, GRANADE,
		STORE_ONOFF, STORE_BUY, STORE_ERROR, MAP,
		MONSTER1_SHOT, MONSTER2_SHOT, MONSTER3_SHOT, MONSTER1_BEATEN, MONSTER2_BEATEN, MONSTER3_BEATEN,
		BOSS_WHISPER, BOSS_SHOT1,
		MAXCHANNEL
	};
private:
	CSoundMgr();
	~CSoundMgr();

public:
	void Initialize();

	void Release();
public:
	int  VolumeUp(CHANNELID eID, _float _vol);
	int  VolumeDown(CHANNELID eID, _float _vol);
	int  BGMVolumeUp(_float _vol);
	int  BGMVolumeDown(_float _vol);
	int  Pause(CHANNELID eID);
	void PlaySound(TCHAR* pSoundKey, CHANNELID eID, _float _vol);
	void PlayBGM(TCHAR* pSoundKey);
	void StopSound(CHANNELID eID);
	void StopAll();

private:
	float m_volume = SOUND_DEFAULT;
	float m_BGMvolume = SOUND_DEFAULT;
	FMOD_BOOL m_bool;

private:
	void LoadSoundFile();

private:
	static CSoundMgr* m_pInstance;
	// ���� ���ҽ� ������ ���� ��ü 
	map<TCHAR*, FMOD_SOUND*> m_mapSound;
	// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL];
	// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
	FMOD_SYSTEM* m_pSystem;
	_bool		m_bPause = false;
};

