#include "pch.h"
#include "CUnit.h"

CUnit::CUnit()
{
	m_pInfo = nullptr;
}

CUnit::~CUnit()
{
	Release();
}

void CUnit::Initialize(const char* const _szName, const int& _iMaxHp, const int& _iPower)
{
	m_pInfo = new INFO;
	strcpy_s(m_pInfo->m_szName, _szName);
	m_pInfo->m_iMaxHp = _iMaxHp;
	m_pInfo->m_iCurrentHp = _iMaxHp;
	m_pInfo->m_iPower = _iPower;
}

void CUnit::Update()
{
}

void CUnit::Release()
{
	SAFE_DELETE(m_pInfo);
}

CUnit* CUnit::Create_Unit()
{
	return nullptr;
}

CUnit* CUnit::Load_Unit()
{
	return nullptr;
}

void CUnit::Render()
{
	cout << "========================================\n";
	cout << "직업 >> " << m_pInfo->m_szName << "\n";
	cout << "체력 >> (" << m_pInfo->m_iCurrentHp << '/' << m_pInfo->m_iMaxHp << ")\t";
	cout << "공격력 >> " << m_pInfo->m_iPower << "\n";
	cout.flush();
}

void CUnit::Rebirth()
{
	m_pInfo->m_iCurrentHp = m_pInfo->m_iMaxHp;
}

int CUnit::Fight(CUnit& Other)
{
	m_pInfo->m_iCurrentHp -= Other.m_pInfo->m_iPower;
	
	if (0 >= m_pInfo->m_iCurrentHp) {
		m_pInfo->m_iCurrentHp = 0;
		return 1; // Lose
	}

	Other.m_pInfo->m_iCurrentHp -= m_pInfo->m_iPower;
	if (0 >= Other.m_pInfo->m_iCurrentHp) {
		Other.m_pInfo->m_iCurrentHp = 0;
		return 2;
	}

	return 0;
}

bool CUnit::SaveInfo()
{
	FILE* pDestStream;

	errno_t err = fopen_s(&pDestStream, PATHSAVE, "wb");

	if (0 == err) {
		fwrite(m_pInfo, sizeof(INFO), 1, pDestStream);
		fclose(pDestStream);
		return true;
	}
	else {
		return false;
	}
}

bool CUnit::LoadInfo()
{
	FILE* pSourceStream;

	errno_t err = fopen_s(&pSourceStream, PATHSAVE, "rb");

	if (0 == err) {
		SAFE_DELETE(m_pInfo);
		m_pInfo = new INFO;
		fread(m_pInfo, sizeof(INFO), 1, pSourceStream);
		fclose(pSourceStream);
		return true;
	}
	else {
		return false;
	}
}

const char* CUnit::GetName() const
{
	return m_pInfo->m_szName;
}

const int& CUnit::GetMaxHp() const
{
	return m_pInfo->m_iMaxHp;
}

const int& CUnit::GetCurrentHp() const
{
	return m_pInfo->m_iCurrentHp;
}

const int& CUnit::GetPower() const
{
	return m_pInfo->m_iPower;
}

void CUnit::SetCurrentHp(const int& _iValue)
{
	m_pInfo->m_iCurrentHp = _iValue;
}

void CUnit::SetName(const char* const _szName)
{
	strcpy_s(m_pInfo->m_szName, _szName);
}

void CUnit::SetMaxHp(const int& _iValue)
{
	m_pInfo->m_iMaxHp = _iValue;
}

void CUnit::SetPower(const int& _iValue)
{
	m_pInfo->m_iPower = _iValue;
}
