#pragma once
#include "Define.h"
#include "CPlayer.h"
#include "CMonster.h"
class CTile
{
private:
	int m_Row;
	int m_Col;
	TYPE_TILE m_status;
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;


public:
	CTile();
	~CTile();

	void Initialize(int& _Row, int& _Col, TYPE_TILE _status);
	void Update();
	void Release();


public:
	int Render() const;
	void setPlayer(CPlayer* _target);
	void SetStatus(TYPE_TILE _status);
	TYPE_TILE GetStatus() const;
	CMonster* GetMonster() const;
	void SetMonster(CMonster* _Monster);
};

