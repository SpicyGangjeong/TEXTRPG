#pragma once
#include "CUnit.h"
class CMonster final :
    public CUnit
{
public:
    CMonster();
    ~CMonster();

public:
    // CUnit을(를) 통해 상속됨
    void Initialize() override;
    void Initialize(const char* _szName, int _iHp, int _iAttack);
    void Update() override;
    void Release() override;
};

