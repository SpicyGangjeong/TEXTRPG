#pragma once
#include "CObj.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CScene.h"
#include "CSceneDungeon.h"
#include "CSceneShop.h"
#include "CSceneVillage.h"



class CMainGame final :
    public CObj
{
    enum TYPESCENE {
        VILLAGE = 1,
        DUNGEON,
        SHOP,
    };
private:
    CUnit* m_pPlayer;
    CUnit* m_pMonster;
    CScene* m_pScene;
    CSceneDungeon* m_pSceneDungeon;
    CSceneShop* m_pSceneShop;
    CSceneVillage* m_pSceneVillage;

    TYPESCENE m_currentScene;
    TYPESCENE m_beforeScene;
    

public:
    CMainGame();
    ~CMainGame();

public:
    void Initialize() override;
    void Update() override;
    void Release() override;

public:
    void ChangeScene(TYPESCENE _destScene);
};

