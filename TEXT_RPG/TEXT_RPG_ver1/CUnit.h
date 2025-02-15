#pragma once
#include "Define.h"

class CUnit
{
public:
	CUnit();
	~CUnit();

public:
	void Initialize(const char* const _szName, const int &  _iMaxHp, const int &  _iPower);
	void			Update();
	void			Release();

	CUnit*			Create_Unit();
	CUnit*			Load_Unit();
	
	void			Render();
	void			Rebirth();
	int				Fight(CUnit& Other);
	bool			SaveInfo();
	bool			LoadInfo();
public:
// l-value로 쓸 이유도 없고
// 반환값은 함수 내부에서 선언된
// 지역변수가 아니기 때문에 const <T>&사용함
// GetNAme은 레퍼런스를 사용하면 문자 하나만 가져오기 때문에
// 포인터 타입으로 가져오고 보내야함
// 함수 뒤에 const 붙이는건 이 getter가 멤버변수를 그대로
// 들고 온다는 사실을 명시적으로 보이기 위함임.
	const char*		GetName() const;
	const int&		GetMaxHp() const;
	const int&		GetCurrentHp() const;
	const int&		GetPower() const;

public:
// 가리키는 대상을 바꿀 이유도 없고
// 가리키는 대상의 값을 바꿀 이유도 없기 때문에
// const <T>& 사용함
	void SetCurrentHp(const int& _iValue);


private:
// 가리키는 대상을 바꿀 이유도 없고
// 가리키는 대상의 값을 바꿀 이유도 없기 때문에
// const <T>&  사용함
// SetName은 레퍼런스를 사용하면 문자 하나만 가져오기 때문에
// 포인터 타입으로 가져오고 보내야함
	void SetName(const char* const _szName);
	void SetMaxHp(const int&  _iValue);
	void SetPower(const int&  _iValue);

// const <T>* const >> 상수 포인터 상수임
// const <T>& const >> 상수 레퍼런스임 (뒤 const는 무시됨)
// 옛날에는 상-레-상으로 썼었는데 이젠 무시되는 김에 안써도 됨
private:
	INFO* m_pInfo;
};

