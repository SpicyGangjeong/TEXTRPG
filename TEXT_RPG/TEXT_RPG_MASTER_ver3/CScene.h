#pragma once
#include "CObj.h"
#include "CUnit.h"

class CScene abstract:
    public CObj
{
protected:
    CUnit* m_pPlayer;
    CUnit* m_pMonster;
public:
    CScene();
    virtual ~CScene();
    virtual void Render(int& _iResult) = 0;
};

