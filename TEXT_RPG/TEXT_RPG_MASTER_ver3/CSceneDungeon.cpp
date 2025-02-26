#include "pch.h"
#include "CSceneDungeon.h"

CSceneDungeon::CSceneDungeon()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CSceneDungeon::~CSceneDungeon()
{
	Release();
}

void CSceneDungeon::Initialize()
{
}

void CSceneDungeon::Initialize(CUnit* _pPlayer, CUnit* _pMonster)
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = _pPlayer;
	}
	if (nullptr == m_pMonster) {
		m_pMonster = _pMonster;
	}
}

void CSceneDungeon::Update()
{
}

void CSceneDungeon::Release()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

void CSceneDungeon::Render(int& _iResult)
{
	int iInput;
	while (true) {
		SYSTEM_CLS;
		m_pPlayer->Render();
		cout << "1. 초급 던전  2. 중급 던전  3. 고급 던전  4. 뒤로가기 : ";
		cin >> iInput;

#ifdef _DEBUG
		CMonster* pMonster;
		switch (iInput)
		{
		case 1:
			pMonster = dynamic_cast<CMonster*>(m_pMonster);
			if (nullptr == pMonster) {
				cout << "비 논리적 형 변환 발생" << endl;
				SYSTEM_PAUSE;
			}
			else {
				pMonster->Initialize("초급", 30, 3);
			}
			break;
		case 2:
			pMonster = dynamic_cast<CMonster*>(m_pMonster);
			if (nullptr == pMonster) {
				cout << "비 논리적 형 변환 발생" << endl;
				SYSTEM_PAUSE;
			}
			else {
				pMonster->Initialize("중급", 60, 6);
			}
			break;
		case 3:
			pMonster = dynamic_cast<CMonster*>(m_pMonster);
			if (nullptr == pMonster) {
				cout << "비 논리적 형 변환 발생" << endl;
				SYSTEM_PAUSE;
			}
			else {
				pMonster->Initialize("고급", 90, 9);
			}
			break;
		case 4:
			_iResult = 4;
			return;
		default:
			continue;
		}
		CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);
		if (nullptr == pPlayer) {
			cout << "비 논리적 형 변환 발생" << endl;
			SYSTEM_PAUSE;
		}
		else {
			_iResult = pPlayer->Fight(m_pMonster);
			m_pMonster->Release();
			return;
		}

		
#endif // _DEBUG

#ifndef _DEBUG
		switch (iInput)
		{
		case 1:
			static_cast<CMonster*>(m_pMonster)->Initialize("초급", 30, 3);
			break;
		case 2:
			static_cast<CMonster*>(m_pMonster)->Initialize("중급", 60, 6);
			break;
		case 3:
			static_cast<CMonster*>(m_pMonster)->Initialize("고급", 90, 9);
			break;
		case 4:
			_iResult = 4;
			return;
		default:
			continue;
		}
		_iResult = static_cast<CPlayer*>(m_pPlayer)->Fight(m_pMonster);
		m_pMonster->Release();
		return;
#endif // !_DEBUG

	}
}