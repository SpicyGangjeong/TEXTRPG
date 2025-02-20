#include "pch.h"
#include "CMonster.h"

CMonster::CMonster() : m_Level(EASY)
{
	m_pInfo = nullptr;
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	srand(unsigned(time(NULL)));
	const char _szName[3][64] = { "�ʱ�", "�߱�", "���" };
	m_Level = TYPE_LELVEL((rand() % 3) + 1);
	int _iMaxHp = 30 * m_Level;
	int _iPower = 3 * m_Level;
	if (nullptr == m_pInfo) {
		m_pInfo = new INFO();
		strcpy_s(m_pInfo->szName, _szName[m_Level-1]);
		m_pInfo->iMaxHp = _iMaxHp;
		m_pInfo->iCurrentHp = _iMaxHp;
		m_pInfo->iPower = _iPower;
		m_pInfo->iLevel = m_Level;
		m_pInfo->iExp = (rand() % (5 * m_Level) + m_Level);
	}
}

void CMonster::Update()
{
}

void CMonster::Release()
{
	SAFE_DELETE(m_pInfo);
}

INFO* CMonster::GetInfo()
{
	return m_pInfo;
}

void CMonster::Render()
{
	cout << "======================================================\n";
	cout << "���� >> " << GetInfo()->szName << "\t����(�������ġ/�ʿ����ġ) >> " << GetInfo()->iLevel << " (" << GetInfo()->iExp << '/' << GetInfo()->iLevel * 5 << ")\n";
	cout << "ü�� >> " << GetInfo()->iCurrentHp << "/" << GetInfo()->iMaxHp << "\t���ݷ� >> " << GetInfo()->iPower << endl;
}
