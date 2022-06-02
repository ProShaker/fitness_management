#include "def_fitness_management.h"

int main()
{ 
	member_list* ptr_member = nullptr;								// �޴��Լ����� ����Լ��� ������ ����
	member_list* normal_member_startnode = new member_list;			// �Ϲ�ȸ���� ��ŸƮ ��� �ּ�
	member_list* spinning_member_startnode = new spinning_member;	// ���Ǵ�ȸ���� ��ŸƮ ��� �ּ�
	member_list* pt_member_startnode = new pt_member;				// ��Ƽȸ���� ��ŸƮ ��� �ּ�
	member_list* pilates_member_startnode = new pilates_member;		// �ʶ��׽�ȸ���� ��ŸƮ ��� �ּ�

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
			ptr_member = normal_member_startnode;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "���Ǵ� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = spinning_member_startnode;
		}

		else if (member_Classification == PT)
		{
			cout << "PT ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = pt_member_startnode;
		}

		else if (member_Classification == PILATES)
		{
			cout << "�ʶ��׽� ȸ���� �����ϼ̽��ϴ�." << endl << endl;
			ptr_member = pilates_member_startnode;
		}

		else
		{
			cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
		}
		menu_fitness_management(ptr_member);
	}
	
	//�����Ҵ�� ��ü�� �޸� ����
	delete ptr_member; 
	delete normal_member_startnode;
	delete spinning_member_startnode;
	delete pt_member_startnode;
	delete pilates_member_startnode;
	return 0;
}