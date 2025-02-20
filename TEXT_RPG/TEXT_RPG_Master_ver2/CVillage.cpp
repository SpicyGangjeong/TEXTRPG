#include "pch.h"
#include "CVillage.h"

CVillage::CVillage()
{
	m_pPlayer = nullptr;
}

CVillage::~CVillage()
{
	Release();
}

void CVillage::Initialize(const CPlayer* _pPlayer)
{
	if (nullptr == m_pPlayer) {
		m_pPlayer = _pPlayer;
	}
}

void CVillage::Update()
{

}

void CVillage::Release()
{
	m_pPlayer = nullptr;
}
