#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
	m_CurrentMenu = MENU_MAIN;
	m_PreviousMenu = MENU_MAIN;
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
		m_pField->Initialize(m_pPlayer);
	}
}

void CMainGame::Update()
{
	while (true) {
		switch (m_CurrentMenu)
		{
		case CMainGame::MENU_EXIT:
			{
				int iResult = Menu_Exit();
				if (1 == iResult) {
					return;
				}
			}
			break;
		case CMainGame::MENU_MAIN:
			Menu_Main();
			break;
		case CMainGame::MENU_VILLAGE:
			Menu_Village();
			break;
		case CMainGame::MENU_FIELD:
			Menu_Field();
			break;
		default:
			break;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
}

void CMainGame::ChangeMenu(TYPE_MENU _destMenu)
{
	m_PreviousMenu = m_CurrentMenu;
	m_CurrentMenu = _destMenu;
}

int CMainGame::Menu_Exit()
{
	while(true){
		SYSTEM_CLS;
		cout << "정말로 종료 하시겠습니까?\n";
		cout << "1. 네  2.아니오  3.메인메뉴로" << endl;
		int iInput = -1;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			return 1;
		case 2:
			ChangeMenu(m_PreviousMenu);
			return 0;
		case 3:
			ChangeMenu(MENU_MAIN);
			return 0;
		default:
			break;
		}
	}
}

void CMainGame::Menu_Main()
{
	int iInput = 0;

	while (true) {
		SYSTEM_CLS;
		cout << "TEXT_RPG\n";
		cout << "1. 게임시작 (처음부터)\n";
		cout << "2. 불러오기\n";
		cout << "3. 환경설정\n";
		cout << "4. 종료하기\n";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Initialize();
			ChangeMenu(MENU_VILLAGE);
			return;
			break;
		case 2:
			Load_Data();
			ChangeMenu(MENU_VILLAGE);
			return;
			break;
		case 3:
			break;
		case 4:
			ChangeMenu(MENU_EXIT);
			return;
		default:
			break;
		}
	}
}

void CMainGame::Menu_Village()
{
	int iInput;
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		cout << "1. 사냥터  2. 체력회복  3. 저장하기  4. 종료 >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			ChangeMenu(MENU_FIELD);
			return;
		case 2:
			m_pPlayer->Rebirth();
			break;
		case 3:
			Save_Data();
			break;
		case 4:
			ChangeMenu(MENU_EXIT);
			return;
		default:
			break;
		}
	}
}

void CMainGame::Menu_Field()
{
	int iInput = 0;
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		m_pField->Render();
		cout << "2. 아래  4. 왼쪽  6 오른쪽  8. 위로 >> ";
		cin >> iInput;
		iInput = (iInput >> 1) - 1;
		int iMoveResult = m_pField->Move(dRow[iInput], dCol[iInput]);
		if (0 == iMoveResult) {
			cout << "이동할 수 없는 타일입니다." << endl;
			SYSTEM_PAUSE;
		}
		else if (1 == iMoveResult) {
			int iUpdateResult = m_pField->Update();
			switch (iUpdateResult)
			{
			case 1:
				ChangeMenu(MENU_VILLAGE);
				return;
			case 2:
				m_pPlayer->Rebirth();
				ChangeMenu(MENU_VILLAGE);
				return;
			default:
				break;
			}
		}

	}
}

void CMainGame::Load_Data()
{

}

void CMainGame::Save_Data()
{

}
