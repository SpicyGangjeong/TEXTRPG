#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }

#define SYSTEM_CLS system("cls");
#define SYSTEM_PAUSE system("pause");

constexpr int MAXROW	= 10;
constexpr int MAXCOL	= 10;

constexpr char m_cTiles[6] = { '.', '#', 'P', '&', '!', 'T' };
constexpr int dRow[4] = { 1, 0, 0, -1 };
constexpr int dCol[4] = { 0, -1, 1, 0 };

typedef struct tagInfo {
	char szName[64];
	int iMaxHp;
	int iCurrentHp;
	int iPower;
	int iLevel;
	int iExp;
}INFO;


enum TYPE_TILE {
	EMPTY = 0,
	WALL,
	PLAYER,
	MONSTER,
	BOX,
	VILLAGE,
};