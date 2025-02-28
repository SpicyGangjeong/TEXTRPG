#include "pch.h"
#include "CUnit.h"

CUnit::CUnit() {
	m_pInfo = nullptr;
}

CUnit::~CUnit() {
	m_pInfo = nullptr;
}

void CUnit::Render()
{
	cout << "=========================================\n";
	cout << "직업 : " << m_pInfo->szName << '\n';
	cout << "체력 : " << m_pInfo->iHp << "\t공격력 : " << m_pInfo->iAttack << endl;
}

INFO* CUnit::GetInfo()
{
	return m_pInfo;
}
