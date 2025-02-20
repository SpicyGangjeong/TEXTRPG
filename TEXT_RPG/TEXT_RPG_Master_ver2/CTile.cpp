#include "pch.h"
#include "CTile.h"

CTile::CTile()
{
	m_status = EMPTY;
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	m_Row = 0;
	m_Col = 0;
}

CTile::~CTile()
{
	Release();
}

void CTile::Initialize(int _Row, int _Col, TYPE_TILE _status)
{
	m_Row = _Row;
	m_Col = _Col;
	m_status = _status;
	switch (m_status)
	{
	case EMPTY:
		break;
	case WALL:
		break;
	case PLAYER:
		break;
	case MONSTER: 
		if (nullptr == m_pMonster) {
			m_pMonster = new CMonster();
			m_pMonster->Initialize();
		}
		break;
	case BOX:
		// TODO : 아이템 넣어줘야함
		break;
	case VILLAGE:
		break;
	default:
		break;
	}
}

void CTile::Update()
{

}

void CTile::Release()
{
	m_pPlayer = nullptr;
	SAFE_DELETE(m_pMonster);
}

int CTile::Render()
{
	if (m_pPlayer) {
		return PLAYER;
	}
	if (m_pMonster) {
		return MONSTER;
	}
	return m_status;
}

void CTile::ChangeStatus()
{

}

void CTile::setPlayer(CPlayer* _target)
{
	m_pPlayer = _target;
}

void CTile::SetStatus(TYPE_TILE _status)
{
	m_status = _status;
}

TYPE_TILE CTile::GetStatus()
{
	return m_status;
}

CMonster* CTile::GetMonster()
{
	return m_pMonster;
}

void CTile::SetMonster(CMonster* _Monster)
{
	m_pMonster = _Monster;
}
