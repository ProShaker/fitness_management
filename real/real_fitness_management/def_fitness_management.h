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
	friend class member_list;		//�ش� Ŭ������ ����� �����ϱ� ���� friend Ŭ���� ����

public:
	int member_number;	//ȸ����ȣ

//private���� ȸ�� ������ ��ȣ
private:
	string name;			//�̸�
	string hpnumber;		//�ڵ��� ��ȣ
	string gender;		//����
	bool clothes;				//��� �뿩����
	int date_start;					//������
	int date_end;						//������
	char time_class;					//�����ð�
	string date_class;				//��������
	string trainer;					//��� Ʈ���̳�

	member* next; //���� ����� �ּҸ� ����ų ������ ����

	member();
};

//ȸ�� ������ �ٷ�� �Լ��� ���� Ŭ����
class member_list
{
private:
	member* head; //ù ��° ��Ʈ
	member* tail; //������ ���

	// Ư�� ȸ�� ��ü�� �ּҸ� ��ȯ�ϴ� ����Լ�
	member* member_location(const int& member_number);

	void member_profile(member* member) const; //ȸ������ ��� �Լ�

public:

	member_list();

	//���Ǵ�, PT, �ʶ��׽� Ŭ�������� �������̵�
	virtual void add_member();				//ȸ�� �߰� �Լ�
	virtual void rewrite_member();			//ȸ�� ���� ����
	virtual void search_member() const;		//ȸ�� �˻� �Լ� 
	virtual void print_member() const;		//ȸ�� ��� ��� �Լ�
	virtual void delete_member();			//ȸ�� ���� ���� �Լ�

};

void menu_fitness_management(member_list* member); //�޴� �Լ�

// ���Ǵ� Ŭ���� 
class spinning_member : public member_list
{

};

// PT Ŭ���� 
class pt_member : public member_list
{
};

// �ʶ��׽� Ŭ����
class pilates_member : public member_list
{
};

