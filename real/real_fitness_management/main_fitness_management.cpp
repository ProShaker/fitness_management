#include "def_fitness_management.h"
//�ذ��ؾ� �� ���� : ��¥ ���
//add_member �ȵǴ� ��
//
int main()
{
	member_list* ptr_member = nullptr;

	while (1) {
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
			cout << "-----<�Ϲ� ȸ������ �޴�>-----" << endl << endl;
			member_list normal;
			ptr_member = &normal;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			cout << "-----<���Ǵ� ȸ������ �޴�>-----" << endl << endl;
			spinning_member spinning;
			ptr_member = &spinning;
		}

		else if (member_Classification == PT)
		{
			cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			cout << "-----<PT ȸ������ �޴�>-----" << endl << endl;
			pt_member pt;
			ptr_member = &pt;
		}

		else if (member_Classification == PILATES)
		{
			cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			cout << "-----<�ʶ��׽� ȸ������ �޴�>-----" << endl << endl;
			pilates_member pilates;
			ptr_member = &pilates;
		}

		else
		{
			cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		}

		menu_fitness_management(ptr_member);
	}
	return 0;
}