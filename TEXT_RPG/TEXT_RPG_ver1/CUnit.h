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
// l-value�� �� ������ ����
// ��ȯ���� �Լ� ���ο��� �����
// ���������� �ƴϱ� ������ const <T>&�����
// GetNAme�� ���۷����� ����ϸ� ���� �ϳ��� �������� ������
// ������ Ÿ������ �������� ��������
// �Լ� �ڿ� const ���̴°� �� getter�� ��������� �״��
// ��� �´ٴ� ����� ��������� ���̱� ������.
	const char*		GetName() const;
	const int&		GetMaxHp() const;
	const int&		GetCurrentHp() const;
	const int&		GetPower() const;

public:
// ����Ű�� ����� �ٲ� ������ ����
// ����Ű�� ����� ���� �ٲ� ������ ���� ������
// const <T>& �����
	void SetCurrentHp(const int& _iValue);


private:
// ����Ű�� ����� �ٲ� ������ ����
// ����Ű�� ����� ���� �ٲ� ������ ���� ������
// const <T>&  �����
// SetName�� ���۷����� ����ϸ� ���� �ϳ��� �������� ������
// ������ Ÿ������ �������� ��������
	void SetName(const char* const _szName);
	void SetMaxHp(const int&  _iValue);
	void SetPower(const int&  _iValue);

// const <T>* const >> ��� ������ �����
// const <T>& const >> ��� ���۷����� (�� const�� ���õ�)
// �������� ��-��-������ ����µ� ���� ���õǴ� �迡 �Ƚᵵ ��
private:
	INFO* m_pInfo;
};

