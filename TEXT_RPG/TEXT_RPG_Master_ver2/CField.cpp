#include "pch.h"
#include "CField.h"

CField::CField() : m_icRow(4), m_icCol(4), m_ibRow(4), m_ibCol(4)
{
	m_pPlayer = nullptr;
	m_tileMap = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Initialize(CPlayer* _pPlayer)
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = _pPlayer;
	}
	if (nullptr == m_tileMap) {
		m_tileMap = new CTile*[MAXROW];
		for (int iRow = 0; iRow < MAXROW; ++iRow) {
			m_tileMap[iRow] = new CTile[MAXCOL];
			for (int iCol = 0; iCol < MAXCOL; ++iCol) {
				m_tileMap[iRow][iCol].Initialize(iRow, iCol, TYPE_TILE(m_iTileMap[iRow][iCol]));
			}
		}
	}
	m_tileMap[m_icRow][m_icCol].setPlayer(m_pPlayer);
}

int CField::Update()
{
	// 0 : �ƹ� �� ����
	// 1 : ������ ���ư���
	// 2 : ����
	CTile* currentTile = &m_tileMap[m_icRow][m_icCol];
	TYPE_TILE currentStatus = currentTile->GetStatus();
	switch (currentStatus)
	{
	case EMPTY:
		return 0;
		break;
	case WALL:
		return 0;
		break;
	case PLAYER:
		return 0;
		break;
	case MONSTER:
		{
			CMonster* currentMonster = currentTile->GetMonster();
			int iResult = m_pPlayer->GetPlayer()->Battle(currentMonster);
			switch (iResult)
			{
			case -1:
				Move(STEPBACK);
				break;
			case 0:
				return 2;
			case 1:
				currentTile->SetStatus(EMPTY);
				currentTile->SetMonster(nullptr);
				SAFE_DELETE(currentMonster);
			default:
				break;
			}
		}
	

		break;
	case BOX:
		// TODO : ������ �����ؾ���
		break;
	case VILLAGE:
		Move(STEPBACK);
		return 1;
		break;
	}

	return 0;
}

void CField::Release()
{
	m_pPlayer = nullptr;
	for (int iRow = 0; iRow < MAXROW; ++iRow) {
		SAFE_DELETE_ARRAY(m_tileMap[iRow]);
	}
	SAFE_DELETE_ARRAY(m_tileMap);
}

void CField::Render()
{
	for (int iRow = 0; iRow < MAXROW; ++iRow) {
		for (int iCol = 0; iCol < MAXCOL; ++iCol) {
			cout << m_cTiles[m_tileMap[iRow][iCol].Render()] << '\t';
		}
		cout << '\n';
	}
	cout.flush();
}

int CField::Move(int _dRow, int _dCol)
{
	// 0 : �̵� ����
	// 1 : �̵� ����
	int nRow = m_icRow + _dRow;
	int nCol = m_icCol + _dCol;

	if (nRow < 0 || nRow >= MAXROW || nCol < 0 || nCol >= MAXCOL) {
		cout << "�� ������ �̵��� �� �����ϴ�\n";
		return 0;
	}
	if (m_tileMap[nRow][nCol].GetStatus() == WALL) {
		cout << "������ �̵��� �� �����ϴ�\n";
		return 0;
	}
	m_tileMap[m_icRow][m_icCol].setPlayer(nullptr);
	m_tileMap[nRow][nCol].setPlayer(m_pPlayer);
	m_ibRow = m_icRow;
	m_ibCol = m_icCol;
	m_icRow = nRow;
	m_icCol = nCol;
	return 1;
}
