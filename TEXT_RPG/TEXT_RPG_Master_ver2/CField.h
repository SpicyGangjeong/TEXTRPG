#pragma once
#include "pch.h"
#include "Define.h"
#include "CPlayer.h"
#include "CTile.h"
#include "CMonster.h"

#define STEPBACK -(m_icRow - m_ibRow), -(m_icCol - m_ibCol)

class CField
{
private:
	int m_iTileMap[MAXROW][MAXCOL] = {
		{1, 3, 0, 0, 0, 3, 0, 0, 3, 3},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 3, 0, 0},
		{0, 0, 0, 0, 0, 0, 3, 1, 0, 3},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
		{1, 5, 1, 1, 0, 3, 0, 0, 1, 0},
		{4, 4, 4, 4, 1, 0, 0, 1, 0, 3},
		{4, 4, 4, 4, 1, 0, 0, 1, 0, 0},
		{4, 4, 4, 4, 1, 0, 0, 1, 0, 0}
	};
	CTile** m_tileMap;
	CPlayer* m_pPlayer;
	int m_icRow;
	int m_icCol;
	int m_ibRow;
	int m_ibCol;
public:
	CField();
	~CField();


public:
	void Initialize(CPlayer* _pPlayer);
	int Update();
	void Release();
	void Render() const;
	int Move(int _dRow, int _dCol);
};