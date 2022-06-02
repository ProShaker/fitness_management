#pragma once
#include <string>
#include <iostream>

using namespace std;

// main���Ͽ��� ����� �������� ����
enum { NORMAL = 1, SPINNING, PT, PILATES };
static int member_Classification = 0;



// ȸ�� ���� ������ ��� �ִ� ��� Ŭ����
class member
{
	friend class member_list;	//�ش� Ŭ������ ����� �����ϱ� ���� friend Ŭ���� ����
	friend class special_member_list;

public:
	int member_number;	//ȸ����ȣ
	member();
	~member();

//private���� ȸ�� ������ ��ȣ
private:
	string name;		//�̸�
	string hpnumber;	//�ڵ��� ��ȣ
	string gender;		//����
	string date_class;	//���� ����
	string trainer;		//��� Ʈ���̳�
	string date_start;	//������
	string date_end;	//������
	string time_class;	//�����ð�
	string clothes;		//��� �뿩����

	member* next; //���� ����� �ּҸ� ����ų ������ ����
};

//ȸ�� ������ �ٷ�� �Լ��� ���� Ŭ����
class member_list
{
	friend class special_member_list;

private:
	member* head; //ù ��° ����� �ּҸ� ����
	member* tail; //next�� ������ ���� ��ü�� �ּҸ� �Ѱ���

	// Ư�� ȸ�� ��ü�� �ּҸ� ��ȯ�ϴ� ����Լ�
	member* member_location(const int& member_number);

	//ȸ������ ��� �Լ�
	void member_profile(member* member) const; 

public:
	member_list();
	~member_list();
	//���Ǵ�, PT, �ʶ��׽� Ŭ�������� �������̵�
	virtual void add_member();				//ȸ�� �߰� �Լ�
	virtual void rewrite_member();			//ȸ�� ���� ����
	void search_member() const;		//ȸ�� �˻� �Լ� 
	void print_member() const;		//ȸ�� ��� ��� �Լ�
	void delete_member();			//ȸ�� ���� ���� �Լ�

};

void menu_fitness_management(member_list* member); //�޴� �Լ�

string days_calculate(const string& _start_date, const int& membership); //����� ��¥ ��� �Լ�

class special_member_list : public member_list
{
public:
	special_member_list();
	~special_member_list();
	void add_member();				//ȸ�� �߰� �Լ�
	void rewrite_member();			//ȸ�� ���� ����
};

// ���Ǵ� Ŭ���� 
class spinning_member : public special_member_list
{
public:
	spinning_member()
	{
		member* start_node = new member;
		member* head = start_node;
	}
	~spinning_member();
};

// PT Ŭ���� 
class pt_member : public special_member_list
{
public:
	pt_member()
	{
		member* start_node = new member;
		member* head = start_node;
	}
	~pt_member();
};

// �ʶ��׽� Ŭ����
class pilates_member : public special_member_list
{
public:
	pilates_member()
	{
		member* start_node = new member;
		member* head = start_node;
	}
	~pilates_member();
};

