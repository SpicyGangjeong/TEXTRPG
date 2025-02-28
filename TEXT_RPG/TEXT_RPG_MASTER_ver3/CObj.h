#pragma once
#include "Define.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;
};

