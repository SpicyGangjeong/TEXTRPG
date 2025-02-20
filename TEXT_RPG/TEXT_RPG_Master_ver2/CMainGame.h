#pragma once
#include "Define.h"
#include "CPlayer.h"
#include "CField.h"

class CMainGame
{
	enum TYPE_MENU {
		MENU_EXIT,
		MENU_MAIN,
		MENU_VILLAGE,
		MENU_FIELD,
	};
private:
	CPlayer* m_pPlayer;
	CField* m_pField;
	TYPE_MENU m_CurrentMenu;
	TYPE_MENU m_PreviousMenu;
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();
public:
	void ChangeMenu(TYPE_MENU _destMenu);
	int Menu_Exit();
	void Menu_Main();
	void Menu_Village();
	void Menu_Field();
	void Load_Data();
	void Save_Data();
};

