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
		cout << "1. �ʱ޻���  2. �߱޻���  3. ��޻���  4. �ڷΰ��� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			cout << "1. �ʱ� ����  2. �ʱ� �� : ";
			cin >> iInput;
			// TODO
			break;
		case 2:
			cout << "1. �߱� ����  2. �߱� �� : ";
			cin >> iInput;
			// TODO
			break;
		case 3:
			cout << "1. ��� ����  2. ��� �� : ";
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
