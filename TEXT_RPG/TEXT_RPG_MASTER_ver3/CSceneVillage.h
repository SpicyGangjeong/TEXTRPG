#pragma once
#include "CScene.h"
class CSceneVillage final:
    public CScene
{
public:
    CSceneVillage();
    ~CSceneVillage();
    void Initialize() override;
    void Initialize(CUnit* _pPlayer);
    void Update() override;
    void Release() override;

    void Render(int& _iResult) override;
};

