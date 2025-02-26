#pragma once
#include "CObj.h"
class CUnit abstract :
    public CObj
{
protected:
    INFO* m_pInfo;

public:
    CUnit();
    virtual ~CUnit();
    void Render();
    INFO* GetInfo();
};

