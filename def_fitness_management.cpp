#include "def_fitness_management.h"

//���α׷� ���� ������ �޴� ȭ���� ��� ����Ѵ�.
void action_fitness_management()
{
	while (1)
	{
		menu_fitness_management();
	}
}

void menu_fitness_management()
{
	//�޴� ��ȣ�� ������ ����, �޸� ������ ���� char �ڷ����� ����Ѵ�.
	char menu_numb;

	cout << "-----<�ｺ�� ȸ������ ���α׷� ����ȭ��>-----" << endl << endl;
	cout << "1. ȸ�� �߰�" << endl;
	cout << "2. ȸ�� ���� ����(��Ŀ, ���, ���� ����)" << endl;
	cout << "3. ȸ�� �˻�" << endl;
	cout << "4. ȸ�� ��� ���" << endl;
	cout << "5. ȸ�� ����" << endl << endl;

	cout << "-----<���Ͻô� �޴� ��ȣ�� �������ּ���.>-----" << endl;
	cin >> menu_numb;
	cout << endl;
	cout << "-----<" << menu_numb << "�� �޴� ȭ���Դϴ�.>-----" << endl;

	//switch���� ���� �޴��� �����Ѵ�.
	switch (menu_numb)
	{
	case 1:
		normal_management::add_member();
		break;

	case 2:
		normal_management::rewrite_member();
		break;

	case 3:
		normal_management::search_member();
		break;

	case 4:
		normal_management::print_member();
		break;

	case 5:
		normal_management::delete_member();
		break;

		//1 ~ 5 �̿��� ���ڸ� �� ��� �޴� �Լ��� ��ȣ���Ѵ�.
	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���.";
		menu_fitness_management();
	}
}

//ȸ�� ������ ���� ������
enum
{
	NORMAL = 1,
	SPINNING,
	PT,
	PILATES
};

//�޴� ��ȣ�� ������ ����, �޸� ������ ���� char �ڷ����� ����Ѵ�.
//�������� �����ؼ� �ٸ� �Լ����� �̿��� �� �ְ� �Ѵ�.
char separate_numb;

//ȸ�� ���� ���� �Լ�
void separate_member()
{
	cout << "ȸ�� ������ �������ּ���." << endl;
	cout << "1. �Ϲ� ȸ��" << endl;
	cout << "2. ���Ǵ� ȸ��" << endl;
	cout << "3. PT ȸ��" << endl;
	cout << "4. �ʶ��׽� ȸ��" << endl << endl;

	cout << "-----<���Ͻô� ȸ�� ���� ��ȣ�� �������ּ���.>-----" << endl;
	//�������� ����� ������ �����´ٴ� ���� ����ϱ� ���� �������� �����ڸ� ����Ѵ�.
	cin >> ::separate_numb;

	switch(::separate_numb)
	{
	case NORMAL:
		cout << "�Ϲ� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case SPINNING:
		cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case PT:
		cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	case PILATES:
		cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl;
		break;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���.";
		separate_member();
	}
}

//ȸ�� �߰� �Լ� ���ǹ�
void normal_management::add_member()
{
	separate_member();
}

//ȸ�� ���� ���� �Լ� ���ǹ�
void normal_management::rewrite_member()
{
	separate_member();
}

//ȸ�� �˻� �Լ� ���ǹ�
void normal_management::search_member()
{
	separate_member();

}

//ȸ�� ��� ��� �Լ� ���ǹ�
void normal_management::print_member()
{
	separate_member();

}

//ȸ�� ���� �Լ� ���ǹ�
void normal_management::delete_member()
{
	separate_member();

}
// �ڷ� ���� �Լ�
int normal_management::reTurn()
{
	return 0;
}