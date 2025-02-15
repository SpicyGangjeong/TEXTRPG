#pragma once

#define SAFE_DELETE(p)			if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	if (p) { delete[] p; p = nullptr; }

#define SYSTEM_CLS				system("cls");
#define SYSTEM_PAUSE			system("pause");

constexpr	int			NAMESIZE			= 32;
constexpr	char		PATHSAVE[256]		= "../Data/Save/player.sav";

typedef struct tagInfo {
	char m_szName[NAMESIZE];
	int m_iMaxHp, m_iCurrentHp, m_iPower;
}INFO;