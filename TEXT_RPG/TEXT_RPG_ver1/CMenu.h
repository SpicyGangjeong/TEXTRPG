#pragma once
#include "CUnit.h"

// �޴� �÷ο츦 ���������� �ϱ� ���� ����ü ���
// tagInfoó�� Define.h�� �ű� ���� ������
// �� ����ü�� CMenu������ ������� �ڸ��ϱ� ������
// Define.h�� �������� ���߰� �������̸� ����
enum MENU {
	MENU_EXIT = 000,
	MENU_MAIN = 001,
	MENU_OPTION = 101,
	MENU_CREATE_PLAYER = 201,
	MENU_VILLIAGE_SELECT_ACTIVITY = 301,
	MENU_DUNGEON_SELECT_LEVEL = 401,
	MENU_ENCOUNTER_SELECT_BEHAVIOR = 501,
};

class CMenu
{
public:
	CMenu();
	~CMenu();

public:
	void			Initialize();
	void			Update();
	void			Release();

	bool			MenuExit();
	void			MenuMain();
	void			MenuCreatePlayer();
	void			MenuVillage();
	void			MenuDungeon();
	void			MenuEncounter();

	void			MenuChange(MENU _destination);

	bool			Save();
	bool			Load();
	
private:
	CUnit*			m_pPlayer;
	CUnit*			m_pMonster;
	MENU			m_MENU_CURRENT;
	MENU			m_MENU_BEFORE;
};
