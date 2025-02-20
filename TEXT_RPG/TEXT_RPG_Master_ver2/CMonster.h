#pragma once
#include "Define.h"

class CMonster
{
	enum TYPE_LELVEL {
		EASY = 1,
		NORMAL,
		HARD,
	};
private:
	INFO* m_pInfo;
	TYPE_LELVEL m_Level;
public:
	CMonster();
	~CMonster();
	void Initialize();
	void Update();
	void Release();

public:
	INFO* GetInfo();
	void Render();
};