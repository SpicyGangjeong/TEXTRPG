#include "pch.h"
#include "Define.h"
#include "CMenu.h"

CMenu::CMenu()
{
	// ���ѷ��� ������ ���� nullptr
	m_pPlayer		= nullptr;
	m_pMonster		= nullptr;

	// C26495 ������ ���ؼ� �ʱ�ȭ�� ����
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
		cout << "������ �����Ͻðڽ��ϱ�? (1. ��  2. �ƴϿ�) >> ";
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
		cout << "1. ���� �����ϱ�\n2. �ҷ�����\n3. ȯ�漳��\n4. ����\n";
		cout << "�ൿ�� �������ּ��� >> ";
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
				cout << "�ҷ����� ����" << endl;
			}
			else {
				cout << "�ҷ����� ����" << endl;
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
		cout << "1. ����  2. ������  3. ���� >> ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			strcpy_s(szName, "����");
			break;
		case 2:
			strcpy_s(szName, "������");
			break;
		case 3:
			strcpy_s(szName, "����");
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
		cout << "1. �����  2. �����ϱ�  3. ���� >> ";
		int iInput = 0;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			MenuChange(MENU_DUNGEON_SELECT_LEVEL);
			return;
		case 2:
			if (Save()) {
				cout << "�����ϱ� ����" << endl;
			} else {
				cout << "�����ϱ� ����" << endl;
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
		cout << "1. �ʱ�  2. �߱�  3. ���  4. �ڷΰ���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			strcpy_s(szName, "�ʱ�");
			break;
		case 2:
			strcpy_s(szName, "�߱�");
			break;
		case 3:
			strcpy_s(szName, "���");
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
		cout << "1. �ο��  2. ����ġ�� >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			{
			int iResult = m_pPlayer->Fight(*m_pMonster);
			if (1 == iResult) {
				cout << "�й�.." << endl;
				m_pPlayer->Rebirth();
				MenuChange(MENU_DUNGEON_SELECT_LEVEL);
				SYSTEM_PAUSE;
				return;
			}
			else if (2 == iResult) {
				cout << "�¸�.." << endl;
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
