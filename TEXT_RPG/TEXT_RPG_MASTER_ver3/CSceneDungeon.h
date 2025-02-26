#pragma once
#include "CScene.h"
#include "CPlayer.h"
#include "CMonster.h"
class CSceneDungeon  final :
    public CScene
{
public:
    CSceneDungeon();
    ~CSceneDungeon();
    void Initialize() override;
    void Initialize(CUnit* _pPlayer, CUnit* _pMonster);
    void Update() override;
    void Release() override;
    void Render(int& _iResult) override;

};

