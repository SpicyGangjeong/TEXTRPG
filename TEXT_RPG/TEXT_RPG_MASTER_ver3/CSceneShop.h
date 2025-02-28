#pragma once
#include "CScene.h"
class CSceneShop  final :
    public CScene
{
public:
    CSceneShop();
    ~CSceneShop();

    void Initialize() override;
    void Initialize(CUnit* _pPlayer);
    void Update() override;
    void Release() override;
    void Render(int& _iResult) override;
};

