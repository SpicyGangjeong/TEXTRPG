#pragma once
#include "CPlayer.h"
class CVillage
{
	


public:
	CVillage();
	~CVillage();

public:
	void Initialize(const CPlayer* _pPlayer);
	void Update();
	void Release();



private:
	const CPlayer* m_pPlayer;
};

