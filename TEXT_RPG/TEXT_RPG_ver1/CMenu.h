#pragma once
#include "CUnit.h"

// 메뉴 플로우를 직관적으로 하기 위해 열거체 사용
// tagInfo처럼 Define.h로 옮길 수도 있지만
// 이 열거체는 CMenu에서만 사용함이 자명하기 때문에
// Define.h의 의존성을 낮추고 관리용이를 위함
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
