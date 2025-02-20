#pragma once
#include "Define.h"

class CPlayer
{
	enum TYPE_JOB {
		WARRIOR = 1,
		MAGE,
		THIEF,
		LOAD,
	};
private:
	static CPlayer* Instance;
	INFO* m_pInfo;
private:
	CPlayer();
	void Initialize(const char* _szName, int _iMaxHp, int _iPower, int _iLevel, int _iExp);
	void Update();
	void Release();
	void Load();
	INFO* GetINFO();
public:
	~CPlayer();
	static CPlayer* GetPlayer();
public:

	CPlayer* SelectJob();
};

