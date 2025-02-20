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

INFO* CPlayer::GetINFO()
{
	if (nullptr == m_pInfo) {
		m_pInfo = new INFO;
	}
	return m_pInfo;
}

void CPlayer::Initialize(const char* _szName, int _iMaxHp ,int _iPower, int _iLevel, int _iExp)
{
	strcpy_s(GetINFO()->szName, _szName);
	GetINFO()->iMaxHp = _iMaxHp;
	GetINFO()->iCurrentHp = _iMaxHp;
	GetINFO()->iPower = _iPower;
	GetINFO()->iLevel = _iLevel;
	GetINFO()->iExp = _iExp;
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

CPlayer* CPlayer::SelectJob()
{
	while (true) {
		cout << "1. ����  2. ������  3. ����  4. �ҷ�����" << endl;
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
		case LOAD:
			Load();
			break;
		default:
			break;
		}
		return Instance;
	}
}
