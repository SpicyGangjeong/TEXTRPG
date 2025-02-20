#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }

#define SYSTEM_CLS system("cls");
#define SYSTEM_PAUSE system("pause");

constexpr int MAXROW	= 10;
constexpr int MAXCOL	= 10;

typedef struct tagInfo {
	char szName[64];
	int iMaxHp;
	int iCurrentHp;
	int iPower;
	int iLevel;
	int iExp;
}INFO;

