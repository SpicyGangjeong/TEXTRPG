#pragma once
#include "CUnit.h"
class CPlayer final :
    public CUnit
{
public:
    CPlayer();
    virtual ~CPlayer() override;

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Release() override;
    void SelectJob();
    int Fight(CUnit* other);
};

