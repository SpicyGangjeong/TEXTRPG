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
	cout << "���� >> " << GetInfo()->szName << "\t����(�������ġ/�ʿ����ġ) >> " << GetInfo()->iLevel << " (" << GetInfo()->iExp << '/' << GetInfo()->iLevel * 5 << ")\n";
	cout << "ü�� >> " << GetInfo()->iCurrentHp << "/" << GetInfo()->iMaxHp << "\t���ݷ� >> " << GetInfo()->iPower << endl;
}

CPlayer* CPlayer::SelectJob()
{
	while (true) {
		SYSTEM_CLS;
		cout << "1. ����  2. ������  3. ����" << endl;
		int job;
		cin >> job;
		switch (job)
		{
		case WARRIOR:
			Initialize("����", 100, 10, 1, 0);
			break;
		case MAGE:
			Initialize("������", 100, 10, 1, 0);
			break;
		case THIEF:
			Initialize("����", 100, 10, 1, 0);
			break;
		default:
			break;
		}
		return Instance;
	}
}

int CPlayer::Battle(CMonster* _target)
{
	// -1 : ����
	// 0 : �й�
	// 1 : �¸�
	int iInput = -1;
	while (true) {
		SYSTEM_CLS;
		Render();
		_target->Render();
		cout << "1. ����  2. ���� >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			GetInfo()->iCurrentHp -= _target->GetInfo()->iPower;
			if (GetInfo()->iCurrentHp <= 0) {
				GetInfo()->iCurrentHp = 0;
				cout << "�й�.." << endl;
				SYSTEM_PAUSE;
				return 0;
			}
			_target->GetInfo()->iCurrentHp -= GetInfo()->iPower;
			if (_target->GetInfo()->iCurrentHp <= 0) {
				_target->GetInfo()->iCurrentHp = 0;
				cout << "�¸�!" << endl;
				GetExp(_target->GetInfo()->iExp);
				SYSTEM_PAUSE;
				return 1;
			}
			break;
		case 2:
			cout << "����.." << endl;
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
		cout << "���� ��!!" << endl;
	}
	cout << GetInfo()->iLevel << "(" << GetInfo()->iExp << "/" << GetInfo()->iLevel * 5 << ")" << endl;
}
