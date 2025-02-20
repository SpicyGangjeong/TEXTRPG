#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pVillage = nullptr;
	m_pField = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = CPlayer::GetPlayer()->SelectJob();
	}
	if (nullptr == m_pField) {
		m_pField = new CField();
	}
	if (nullptr == m_pVillage) {
		m_pVillage = new CVillage();
		m_pVillage->Initialize();
	}
}

void CMainGame::Update()
{

}

void CMainGame::Release()
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}
