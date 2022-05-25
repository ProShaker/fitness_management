#include "def_fitness_management.h"

int main()
{
	member_list* ptr_member = nullptr;

	while (1) 
	{
		cout << "-----<�ｺ�� ȸ������ ���α׷� ����ȭ��>-----" << endl << endl;
		cout << "1. �Ϲ� ȸ��" << endl;
		cout << "2. ���Ǵ� ȸ��" << endl;
		cout << "3. PT ȸ��" << endl;
		cout << "4. �ʶ��׽� ȸ��" << endl << endl;
		cout << "���Ͻô� ȸ�� ���� ��ȣ�� �������ּ���. : ";
		cin >> member_Classification;
		cout << endl;

		if (member_Classification == NORMAL)
		{
			cout << "�Ϲ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = new member_list;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = new spinning_member;
		}

		else if (member_Classification == PT)
		{
			cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = new pt_member;
		}

		else if (member_Classification == PILATES)
		{
			cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = new pilates_member;
		}

		else
		{
			cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		}
		menu_fitness_management(ptr_member);
	}
	
	delete ptr_member; //�����Ҵ�� ��ü�� �޸� ����

	return 0;
}