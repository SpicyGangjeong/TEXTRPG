#include "pch.h"
#include "CPlayer.h"

CPlayer* CPlayer::Instance = nullptr;

CPlayer::CPlayer()
{
	m_pInfo = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
}

CPlayer* CPlayer::GetPlayer()
{
	if (nullptr == Instance) {
		Instance = new CPlayer();
	}
	return Instance;
}

void CPlayer::Rebirth()
{
	GetInfo()->iCurrentHp = GetInfo()->iMaxHp;
}

INFO* CPlayer::GetInfo()
{
	if (nullptr == m_pInfo) {
		m_pInfo = new INFO;
	}
	return m_pInfo;
}

void CPlayer::Initialize(const char* _szName, int _iMaxHp ,int _iPower, int _iLevel, int _iExp)
{
	strcpy_s(GetInfo()->szName, _szName);
	GetInfo()->iMaxHp = _iMaxHp;
	GetInfo()->iCurrentHp = _iMaxHp;
	GetInfo()->iPower = _iPower;
	GetInfo()->iLevel = _iLevel;
	GetInfo()->iExp = _iExp;
}

void CPlayer::Update()
{

}

void CPlayer::Release()
{
	SAFE_DELETE(m_pInfo);
}

void CPlayer::Load()
{

}

void CPlayer::Render()
{
	cout << "======================================================\n";
	cout << "직업 >> " << GetInfo()->szName << "\t레벨(현재경험치/필요경험치) >> " << GetInfo()->iLevel << " (" << GetInfo()->iExp << '/' << GetInfo()->iLevel * 5 << ")\n";
	cout << "체력 >> " << GetInfo()->iCurrentHp << "/" << GetInfo()->iMaxHp << "\t공격력 >> " << GetInfo()->iPower << endl;
}

CPlayer* CPlayer::SelectJob()
{
	while (true) {
		SYSTEM_CLS;
		cout << "1. 전사  2. 마법사  3. 도적" << endl;
		int job;
		cin >> job;
		switch (job)
		{
		case WARRIOR:
			Initialize("전사", 100, 10, 1, 0);
			break;
		case MAGE:
			Initialize("마법사", 100, 10, 1, 0);
			break;
		case THIEF:
			Initialize("도적", 100, 10, 1, 0);
			break;
		default:
			break;
		}
		return Instance;
	}
}

int CPlayer::Battle(CMonster* _target)
{
	// -1 : 도망
	// 0 : 패배
	// 1 : 승리
	int iInput = -1;
	while (true) {
		SYSTEM_CLS;
		Render();
		_target->Render();
		cout << "1. 공격  2. 도망 >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			GetInfo()->iCurrentHp -= _target->GetInfo()->iPower;
			if (GetInfo()->iCurrentHp <= 0) {
				GetInfo()->iCurrentHp = 0;
				cout << "패배.." << endl;
				SYSTEM_PAUSE;
				return 0;
			}
			_target->GetInfo()->iCurrentHp -= GetInfo()->iPower;
			if (_target->GetInfo()->iCurrentHp <= 0) {
				_target->GetInfo()->iCurrentHp = 0;
				cout << "승리!" << endl;
				GetExp(_target->GetInfo()->iExp);
				SYSTEM_PAUSE;
				return 1;
			}
			break;
		case 2:
			cout << "도망.." << endl;
			SYSTEM_PAUSE;
			return -1;
			break;
		default:
			break;
		}
	}
	return 0;
}

void CPlayer::GetExp(int _iValue)
{
	cout << GetInfo()->iExp << " >> " << GetInfo()->iExp + _iValue << endl;
	GetInfo()->iExp += _iValue;
	if (GetInfo()->iExp >= GetInfo()->iLevel * 5) {
		GetInfo()->iExp -= GetInfo()->iLevel * 5;
		GetInfo()->iLevel++;
		cout << "레벨 업!!" << endl;
	}
	cout << GetInfo()->iLevel << "(" << GetInfo()->iExp << "/" << GetInfo()->iLevel * 5 << ")" << endl;
}
