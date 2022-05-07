#pragma once
#include <iostream>
using namespace std;

const int name_len = 11;

void action_fitness_management();

void menu_fitness_management();

//�Ϲ� ȸ�� Ŭ����
class normal_management {

//���������� private���� ��ȣ�Ѵ�.
private:
	//�̸�, �ڵ��� ��ȣ, ����
	char normal_name[name_len];
	int normal_hpnumber;
	char normal_gender;

public:
//� ������, ��� ���� ������ �������� ���� �ٷ�� ���ϰ� �Ѵ�.
	const int normal_start;
	int normal_end;
	bool normal_cloths;
	const int normal_locker;

	void add_member();
	void rewrite_member();
	void search_member();
	void print_member();
	void delete_member();
	int reTurn();
};

// Ư�� Ŭ���� - �븻 Ŭ������ ���
class special_management : normal_management
{
public:
	//���� �ð�ǥ, ���� ����, Ʈ���̳� �̸�, �� PT Ƚ��
	char class_time;
	char class_day[2];
	char trainer[name_len];
	const int PT_number;
};

// ���Ǵ� Ŭ���� - Ư�� Ŭ������ ���
class spinning_management : special_management
{
};

// PT Ŭ���� - Ư�� Ŭ������ ���
class pt_management : special_management
{
};

// �ʶ��׽� Ŭ���� - Ư�� Ŭ������ ���
class pilates_management : special_management
{
};


