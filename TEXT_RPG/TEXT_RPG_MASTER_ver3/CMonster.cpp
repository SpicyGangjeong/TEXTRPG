#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
    m_pInfo = nullptr;
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    if (nullptr == m_pInfo) {
        m_pInfo = new INFO;
    }
}

void CMonster::Initialize(const char* _szName, int _iHp, int _iAttack)
{
    if (nullptr == m_pInfo) {
        Initialize();
        strcpy_s(m_pInfo->szName, _szName);
        m_pInfo->iHp = _iHp;
        m_pInfo->iAttack = _iAttack;
    }
}

void CMonster::Update()
{
}

void CMonster::Release()
{
    SAFE_DELETE(m_pInfo);
}
