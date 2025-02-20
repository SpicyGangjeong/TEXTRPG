#pragma once
#include "Define.h"
#include "CMonster.h"

class CPlayer
{
	enum TYPE_JOB {
		WARRIOR = 1,
		MAGE,
		THIEF,
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
public:
	~CPlayer();
	static CPlayer* GetPlayer();
	void Rebirth();
	void Render();
	INFO* GetInfo();
	CPlayer* SelectJob();
	int Battle(CMonster* _target);
	void GetExp(int _iValue);
};

