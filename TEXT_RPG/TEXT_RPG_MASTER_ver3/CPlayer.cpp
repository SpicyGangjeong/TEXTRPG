#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_pInfo = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	if (nullptr == m_pInfo) {
		m_pInfo = new INFO;
	}
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	SAFE_DELETE(m_pInfo);
}


void CPlayer::SelectJob() {
	int iInput;
	while (true) {
		SYSTEM_CLS;
		cout << "1.  전사  2. 마법사  3. 도적" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			strcpy_s(m_pInfo->szName, "전사");
			m_pInfo->iHp = 100;
			m_pInfo->iAttack = 10;

			return;
		case 2:
			strcpy_s(m_pInfo->szName, "마법사");
			m_pInfo->iHp = 100;
			m_pInfo->iAttack = 10;

			return;
		case 3:
			strcpy_s(m_pInfo->szName, "도적");
			m_pInfo->iHp = 100;
			m_pInfo->iAttack = 10;

			return;
		default:
			break;
		}
	}
}


int CPlayer::Fight(CUnit* other) {
	int iInput;
	while (true) {
		SYSTEM_CLS;
		Render();
		other->Render();
		cout << "1. 공격  2. 도망 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pInfo->iHp -= other->GetInfo()->iAttack;
			if (0 >= m_pInfo->iHp) {
				m_pInfo->iHp = 0;
				cout << "패배" << endl;
				SYSTEM_PAUSE;
				return 1;
			}
			other->GetInfo()->iHp -= m_pInfo->iAttack;
			if (0 >= other->GetInfo()->iHp) {
				other->GetInfo()->iHp = 0;
				cout << "승리" << endl;
				SYSTEM_PAUSE;
				return 2;
			}
			break;
		case 2:
			return 3;
		default:
			break;
		}
	}
}