#pragma once

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = nullptr; }

#define SYSTEM_CLS system("cls");
#define SYSTEM_PAUSE system("pause");

typedef struct tagInfo {
	char szName[32];
	int iHp;
	int iAttack;
} INFO;


