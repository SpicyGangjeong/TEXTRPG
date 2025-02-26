#include "pch.h"
#include "CMainGame.h"


CMainGame::CMainGame() : m_currentScene(VILLAGE), m_beforeScene(VILLAGE)
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	m_pScene = nullptr;
	m_pSceneDungeon = nullptr;
	m_pSceneShop = nullptr;
	m_pSceneVillage = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
#ifdef _DEBUG
	if (nullptr == m_pPlayer) {
		m_pPlayer = new CPlayer();
		m_pPlayer->Initialize();
		CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);
		if (nullptr == pPlayer) {
			cout << "비 논리적인 형 변환 발생" << endl;
			SYSTEM_PAUSE;
		}
		else {
			pPlayer->SelectJob();
		}
	}
	if (nullptr == m_pMonster) {
		m_pMonster = new CMonster();

		CMonster* pMonster = dynamic_cast<CMonster*>(m_pMonster);
		if (nullptr == pMonster) {
			cout << "비 논리적인 형 변환 발생" << endl;
			SYSTEM_PAUSE;
		}
		else {
			
		}
	}
	if (nullptr == m_pSceneDungeon) {
		m_pSceneDungeon = new CSceneDungeon;
		m_pSceneDungeon->Initialize(m_pPlayer, m_pMonster);
	}
	if (nullptr == m_pSceneShop) {
		m_pSceneShop = new CSceneShop;
		m_pSceneShop->Initialize(m_pPlayer);
	}
	if (nullptr == m_pSceneVillage) {
		m_pSceneVillage = new CSceneVillage;
		m_pSceneVillage->Initialize(m_pPlayer);
	}
	if (nullptr == m_pScene) {
		m_pScene = m_pSceneVillage;
	}
#endif  // _DEBUG
#ifndef _DEBUG
	if (nullptr == m_pPlayer) {
		m_pPlayer = new CPlayer();
		m_pPlayer->Initialize();
		static_cast<CPlayer*>(m_pPlayer)->SelectJob();
	}
	if (nullptr == m_pMonster) {
		m_pMonster = new CMonster();
		// static_cast<CMonster*>(m_pMonster)->;
	}
	if (nullptr == m_pSceneDungeon) {
		m_pSceneDungeon = new CSceneDungeon;
		m_pSceneDungeon->Initialize(m_pPlayer, m_pMonster);
	}
	if (nullptr == m_pSceneShop) {
		m_pSceneShop = new CSceneShop;
		m_pSceneShop->Initialize(m_pPlayer);
	}
	if (nullptr == m_pSceneVillage) {
		m_pSceneVillage = new CSceneVillage;
		m_pSceneVillage->Initialize(m_pPlayer);
	}
	if (nullptr == m_pScene) {
		m_pScene = m_pSceneVillage;
	}
#endif // _NDEBUG
}

void CMainGame::Update()
{
	int iInput = -1;
	int iResult;
	while (true) {
		iResult = -1;
		switch (m_currentScene)
		{
		case CMainGame::VILLAGE:
			m_pScene = m_pSceneVillage;
			m_pScene->Render(iResult);
			switch (iResult)
			{
			case 1:
				ChangeScene(DUNGEON);
				break;
			case 2:
				ChangeScene(SHOP);
				break;
			case 3:
				return;
			default:
				break;
			}
			break;
		case CMainGame::DUNGEON:
			m_pScene = m_pSceneDungeon;
			m_pScene->Render(iResult);
			switch (iResult)
			{
			case 1: // 패배
				m_pPlayer->GetInfo()->iHp = 100;
				break;
			case 2: // 승리
				break;
			case 3: // 도망
				break;
			case 4: // 뒤로가기
				ChangeScene(VILLAGE);
			default:
				break;
			}
			break;
		case CMainGame::SHOP:
			m_pScene = m_pSceneShop;
			m_pScene->Render(iResult);
			if (4 == iResult) {
				ChangeScene(m_beforeScene);
			}
			break;
		default:
			break;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pSceneDungeon);
	SAFE_DELETE(m_pSceneShop);
	SAFE_DELETE(m_pSceneVillage);
	m_pScene = nullptr;
}

void CMainGame::ChangeScene(TYPESCENE _destScene)
{
	m_beforeScene = m_currentScene;
	m_currentScene = _destScene;
}
