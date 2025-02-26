#include "pch.h"
#include "CSceneVillage.h"

CSceneVillage::CSceneVillage()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CSceneVillage::~CSceneVillage()
{
	Release();
}

void CSceneVillage::Initialize()
{
}

void CSceneVillage::Initialize(CUnit* _pPlayer)
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = _pPlayer;
	}
}

void CSceneVillage::Update()
{
}

void CSceneVillage::Release()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

void CSceneVillage::Render(int& _iResult)
{
	int iInput = 0;
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		cout << "1. 사냥터  2. 상점  3. 종료 : ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_iResult = 1;
			return;
		case 2:
			_iResult = 2;
			return;
		case 3:
			_iResult = 3;
			return;
		default:
			break;
		}
	}
}
