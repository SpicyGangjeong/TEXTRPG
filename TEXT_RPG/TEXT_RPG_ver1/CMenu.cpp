#include "pch.h"
#include "Define.h"
#include "CMenu.h"

CMenu::CMenu()
{
	// 무한루프 방지를 위한 nullptr
	m_pPlayer		= nullptr;
	m_pMonster		= nullptr;

	// C26495 방지를 위해서 초기화는 해줌
	m_MENU_CURRENT	= MENU_MAIN;
	m_MENU_BEFORE = MENU_MAIN;
}

CMenu::~CMenu()
{
	Release();
}

void CMenu::Initialize()
{

}

void CMenu::Update()
{
	while (true) {
		switch (m_MENU_CURRENT)
		{
		case MENU_EXIT:
			if (MenuExit()) {
				return;
			}
			break;
		case MENU_MAIN:
			MenuMain();
			break;
		case MENU_CREATE_PLAYER:
			MenuCreatePlayer();
			break;
		case MENU_VILLIAGE_SELECT_ACTIVITY:
			MenuVillage();
			break;
		case MENU_DUNGEON_SELECT_LEVEL:
			MenuDungeon();
			break;
		case MENU_ENCOUNTER_SELECT_BEHAVIOR:
			MenuEncounter();
			break;
		default:
			break;
		}
	}


}

void CMenu::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMonster);
}

bool CMenu::MenuExit()
{
	int iInput = -1;
	while (true) {
		SYSTEM_CLS;
		cout << "정말로 종료하시겠습니까? (1. 네  2. 아니오) >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			return true;
			break;
		case 2:
			MenuChange(m_MENU_BEFORE);
			return false;
			break;
		default:
			break;
		}
	}
}

void CMenu::MenuMain()
{
	while (true) {
		SYSTEM_CLS;
		cout << "1. 새로 시작하기\n2. 불러오기\n3. 환경설정\n4. 종료\n";
		cout << "행동을 선택해주세요 >> ";
		int iInput(-1);
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			MenuChange(MENU_CREATE_PLAYER);
			return;
		case 2:
			if (Load()) {
				MenuChange(MENU_VILLIAGE_SELECT_ACTIVITY);
				cout << "불러오기 성공" << endl;
			}
			else {
				cout << "불러오기 실패" << endl;
			}
			SYSTEM_PAUSE;
			return;
		case 3:
			MenuChange(MENU_OPTION);
			return;
		case 4:
			MenuChange(MENU_EXIT);
			return;
		default:
			break;
		}
	}

}

void CMenu::MenuCreatePlayer()
{
	int iInput = -1;
	char szName[NAMESIZE] = "";
	while (true) {
		SYSTEM_CLS;
		cout << "1. 전사  2. 마법사  3. 도적 >> ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			strcpy_s(szName, "전사");
			break;
		case 2:
			strcpy_s(szName, "마법사");
			break;
		case 3:
			strcpy_s(szName, "도적");
			break;
		default:
			continue;
			break;
		}

		SAFE_DELETE(m_pPlayer);
		m_pPlayer = new CUnit();
		m_pPlayer->Initialize(szName, 100, 10);
		MenuChange(MENU_VILLIAGE_SELECT_ACTIVITY);
		return;
	}
}

void CMenu::MenuVillage()
{
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		cout << "1. 사냥터  2. 저장하기  3. 종료 >> ";
		int iInput = 0;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			MenuChange(MENU_DUNGEON_SELECT_LEVEL);
			return;
		case 2:
			if (Save()) {
				cout << "저장하기 성공" << endl;
			} else {
				cout << "저장하기 실패" << endl;
			}
			SYSTEM_PAUSE;
			break;
		case 3:
			MenuChange(MENU_EXIT);
			return;
		default:
			break;
		}
	}

}

void CMenu::MenuDungeon()
{
	int iInput = -1;
	char szName[NAMESIZE] = "";
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		cout << "1. 초급  2. 중급  3. 고급  4. 뒤로가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(szName, "초급");
			break;
		case 2:
			strcpy_s(szName, "중급");
			break;
		case 3:
			strcpy_s(szName, "고급");
			break;
		case 4:
			MenuChange(MENU_VILLIAGE_SELECT_ACTIVITY);
			return;
		default:
			continue;
			break;
		}
		SAFE_DELETE(m_pMonster);
		m_pMonster = new CUnit();
		m_pMonster->Initialize(szName, 30 * iInput, 3 * iInput);
		MenuChange(MENU_ENCOUNTER_SELECT_BEHAVIOR);
		return;

	}
}

void CMenu::MenuEncounter()
{
	int iInput = -1;
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1. 싸우기  2. 도망치기 >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			{
			int iResult = m_pPlayer->Fight(*m_pMonster);
			if (1 == iResult) {
				cout << "패배.." << endl;
				m_pPlayer->Rebirth();
				MenuChange(MENU_DUNGEON_SELECT_LEVEL);
				SYSTEM_PAUSE;
				return;
			}
			else if (2 == iResult) {
				cout << "승리.." << endl;
				MenuChange(MENU_DUNGEON_SELECT_LEVEL);
				SYSTEM_PAUSE;
				return;
			}
			}
			break;
		case 2:
			MenuChange(MENU_DUNGEON_SELECT_LEVEL);
			return;
		default:
			continue;
			break;
		}

	}
}

void CMenu::MenuChange(MENU _destination)
{
	m_MENU_BEFORE = m_MENU_CURRENT;
	m_MENU_CURRENT = _destination;
}

bool CMenu::Save()
{
	return m_pPlayer->SaveInfo();
}

bool CMenu::Load()
{
	SAFE_DELETE(m_pPlayer);
	m_pPlayer = new CUnit();
	if (m_pPlayer->LoadInfo()) {
		return true;
	}
	else {
		SAFE_DELETE(m_pPlayer);
	}
}
