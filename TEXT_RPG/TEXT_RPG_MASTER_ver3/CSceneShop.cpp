#include "pch.h"
#include "CSceneShop.h"

CSceneShop::CSceneShop()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CSceneShop::~CSceneShop()
{
	Release();
}

void CSceneShop::Initialize()
{
}

void CSceneShop::Initialize(CUnit* _pPlayer)
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = _pPlayer;
	}
}

void CSceneShop::Update()
{
}

void CSceneShop::Release()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

void CSceneShop::Render(int& _iResult)
{
	int iInput;
	while (true) {
		SYSTEM_CLS;
		cout << "1. 초급상점  2. 중급상점  3. 고급상점  4. 뒤로가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			cout << "1. 초급 무기  2. 초급 방어구 : ";
			cin >> iInput;
			// TODO
			break;
		case 2:
			cout << "1. 중급 무기  2. 중급 방어구 : ";
			cin >> iInput;
			// TODO
			break;
		case 3:
			cout << "1. 고급 무기  2. 고급 방어구 : ";
			cin >> iInput;
			// TODO
			break;
		case 4:
			_iResult = 4;
			return;
		default:
			break;
		}
	}
}
