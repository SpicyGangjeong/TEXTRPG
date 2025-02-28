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
	cout << "���� : " << m_pInfo->szName << '\n';
	cout << "ü�� : " << m_pInfo->iHp << "\t���ݷ� : " << m_pInfo->iAttack << endl;
}

INFO* CUnit::GetInfo()
{
	return m_pInfo;
}
