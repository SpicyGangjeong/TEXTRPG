#include "pch.h"
#include "Define.h"

#include "CMenu.h"


int main() {
	CMenu* menu = new CMenu();

	menu->Initialize();
	menu->Update();


	SAFE_DELETE(menu);
	return 0;
}