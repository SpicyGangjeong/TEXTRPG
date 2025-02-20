#pragma once
#include "Define.h"
#include "CPlayer.h"
#include "CField.h"
#include "CVillage.h"

class CMainGame
{
private:
	CPlayer* m_pPlayer;
	CVillage* m_pVillage;
	CField* m_pField;

public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();
public:

};

