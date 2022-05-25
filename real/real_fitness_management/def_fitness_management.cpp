#include "def_fitness_management.h"

member::member()
{
	//string ���� 
	name = "";			//�̸�
	hpnumber = "";		//�ڵ��� ��ȣ
	gender = "";		//����
	date_class = "";	//��������
	date_start = "";	//������
	date_end = "";		//������
	trainer = "";		//��� Ʈ���̳�
	clothes = "";		//��� �뿩����
	time_class = "";	//�����ð�
	member_number = 0;	//ȸ����ȣ
	member* next = nullptr;
}

member* member_list::member_location(const int& member_number)
{
	//first_node ���� �����ؼ� �� ������ ���� ������ ���� ȸ�� ��ü �ּҷ� �Ѿ
	for (member* current_location = head; current_location != NULL; current_location->next)
	{
		//�Է¹��� ȸ����ȣ�� �ּҰ� ����Ű�� ȸ����ȣ�� ���ٸ� ���� �ּ� ��ȯ
		if (member_number == current_location->member_number)
		{
			return current_location;
		}
	}
	return NULL;
}

void member_list::member_profile(member* ptr_member) const
{
	cout << "ȸ�� ��ȣ | �̸� | �ڵ��� ��ȣ | ���� | ȸ���� ������ | ȸ���� ������ | ��� �뿩 ����" << endl << endl;
	cout << ptr_member->member_number + 1 << " " << ptr_member->name << " " << " "<< ptr_member->hpnumber << " " << ptr_member->gender 
		<< " " << ptr_member->date_start << " " << ptr_member->date_end << " " << ptr_member->clothes << endl << endl;
}

//member_list�� �����Լ�
//���ο� member(ȸ�� Ŭ����)��ü�� �ּ� : ���� ���� ����
member_list::member_list()
{
	member* start_node = new member;
	head = start_node;
	tail = start_node;
}

void member_list::add_member()
{
	member* new_member = new member; //member ��ü �����Ҵ�

	string _name, _hpnumber, _gender, _date_start, _date_end, _clothes;
	int _membership;
	static int _member_number = 0;

	cout << "�߰��� ȸ������ ������ �Է����ּ���." << endl;

	cout << "�̸� : ";
	cin >> _name;

	cout << "�ڵ��� ��ȣ (010-0000-0000): ";
	cin >> _hpnumber;

	cout << "���� (��/��) : ";
	cin >> _gender;

	cout << "������(YYMMDD) : ";
	cin >> _date_start;

	cout << "ȸ���� ����(���� �� �Է�) : ";
	cin >> _membership;
	_date_end = days_calculate(_date_start, _membership);

	cout << "��� �뿩 ���� (y/n) : ";
	cin >> _clothes;

	new_member->member_number = _member_number;
	new_member->name = _name;
	new_member->hpnumber = _hpnumber;
	new_member->gender = _gender;
	new_member->date_start = _date_start;
	new_member->date_end = _date_end;
	new_member->clothes = (_clothes == "y") ? true : false; //���׿�����, y(�ƽ�Ű �ڵ� 121) �Է½� true

	_member_number++;

	tail->next = new_member; //next, tail������ �߰��� ȸ�� ��ü�� ����Ű���� �Ѵ�.
	tail = new_member;

	member_profile(new_member);
}

void member_list::rewrite_member()
{
	int _membership = 0, _member_number = 0;
	string _date_end, _clothes;
	member* current_location = member_location(_member_number); //ȸ�� ��ȣ�� ȸ�� ������ �����ϴ� �����ͺ���

	cout << "������ ȸ������ ȸ����ȣ�� �Է����ּ���. : ";
	cin >> _member_number;

	if (current_location == NULL)
	{
		cout << "�ش� ȸ����ȣ�� �ش��ϴ� ȸ������ ������ �������� �ʽ��ϴ�. " << endl;
	}
	else
	{
		cout << endl << endl;

		member_profile(current_location);

		cout << endl << "������ ������ �Է����ּ���." << endl;

		cout << "�̸� : ";
		cin >> current_location->name;

		cout << "�ڵ��� ��ȣ (010-0000-0000): ";
		cin >> current_location->hpnumber;

		cout << "���� (��/��) : ";
		cin >> current_location->gender;

		cout << "������(YYMMDD) : ";
		cin >> current_location->date_start;

		cout << "ȸ���� ����(���� �� �Է�) : ";
		cin >> _membership;
		_date_end = days_calculate(current_location->date_start, _membership);

		cout << "��� �뿩 ���� (y/n) : ";
		cin >> _clothes;
		current_location->clothes = (_clothes == "y") ? true : false;
	}
}

void member_list::search_member() const
{
	member* this_member = head->next;
	string str;

	cout << "1. ȸ�� ��ȣ �˻�" << endl << "2. ȸ�� �̸�" << endl << endl << "��ȣ�� �Է����ּ���. : ";
	cin >> member_Classification;
	cout << endl;

	switch (member_Classification)
	{
	case 1:
		cout << "ȸ����ȣ�� �Է����ּ���. : ";
		cin >> str;
		while (this_member != NULL) //�� ������ ���ö����� �ݺ�
		{
			if (this_member->member_number == stoi(str)) member_profile(this_member); //ȸ�� ��ȣ�� ������ ������(ȸ�� ����)���
			this_member = this_member->next;
		}
		cout << "�˻��� �Ϸ��߽��ϴ�." << endl << endl;
		break;

	case 2:
		cout << "�̸� �Է����ּ���. : ";
		cin >> str;
		while (this_member != NULL) //�� ������ ���ö����� �ݺ�
		{
			if (this_member->name == str) member_profile(this_member); //�̸��� ������ ������(ȸ�� ����)���
			this_member = this_member->next;
		}
		cout << "�˻��� �Ϸ��߽��ϴ�." << endl << endl;
		break;

	default:
		cout << "��ȣ�� �����ϴ�." << endl;
		return;
	}
}

void member_list::print_member() const
{
	member* current_location = head->next; //next : ���� ȸ�� ��ü�� �ּ�

	//�� ������ ���� ������ ȸ�� ������ ����Ѵ�.
	for (;current_location != NULL; current_location = current_location->next)
		member_profile(current_location);

	cout << "��� ȸ�� ������ ����߽��ϴ�." << endl << endl;
}

//ȸ�� ��ü ���� �Լ�
void member_list::delete_member()
{
	int _member_number;
	cout << "������ ȸ������ ȸ�� ��ȣ�� �Է����ּ���. : ";
	cin >> _member_number;

	member* pre_member = head;			//Ž���ϴ� ������ ����
	member* current_member = nullptr;	//ȸ�� ��ü�� �ּҸ� ������ üũ����Ʈ


	while (pre_member->next != NULL)	//���� ��ü�� �� ������ �ƴҶ����� �ݺ�
	{

		if (pre_member->next->member_number == _member_number)
		{
			current_member = pre_member->next;	//ȸ�� ��ȣ�� ������ ��� üũ����Ʈ�� ��ü�� �ּҸ� �����Ѵ�.
			break;
		}
		pre_member = pre_member->next;			//ȸ�� ��ȣ�� ���� ���� ��� ���� ��ü�� �̵��Ѵ�.
	}

	//������� ��ü�� �� ������ ��� �Լ� ����
	if (pre_member->next == NULL)
	{
		cout << "�ش� ȸ����ȣ���� ȸ������ �����ϴ�." << endl;
		return;
	}

	//������� ��ü�� �� ������ �ƴ� ���
	pre_member->next = current_member->next; //üũ����Ʈ�� ���� ��ü �ּҸ� pre_member�� ����Ű���� �Ѵ�.
	delete current_member;					 //�޸� ������ ���� �����Ҵ�� ��ü delete
	cout << "ȸ�� ������ �����߽��ϴ�." << endl;
}

void menu_fitness_management(member_list* member)
{
	int menu_numb = 0;

	//�� Ŭ������ ȸ������ �޴�
	cout << "1. ȸ�� �߰�" << endl;
	cout << "2. ȸ�� ���� ����" << endl;
	cout << "3. ȸ�� �˻�" << endl;
	cout << "4. ȸ�� ��� ���" << endl;
	cout << "5. ȸ�� ����" << endl;
	cout << "6. ������" << endl << endl;

	cout << "���Ͻô� �޴� ��ȣ�� �������ּ���. : ";
	cin >> menu_numb;
	cout << endl;

	switch (menu_numb)
	{
	case 1:
		cout << "ȸ�� �߰� ȭ���Դϴ�." << endl << endl;
		member->add_member();
		break;

	case 2:
		cout << "ȸ�� ���� ���� ȭ���Դϴ�." << endl << endl;
		member->rewrite_member();
		break;

	case 3:
		cout << "ȸ�� �˻� ȭ���Դϴ�." << endl;
		member->search_member();
		break;

	case 4:
		cout << "ȸ�� ��� ��� ȭ���Դϴ�." << endl << endl;
		member->print_member();
		break;

	case 5:
		cout << "ȸ�� ���� ȭ���Դϴ�." << endl << endl;
		member->delete_member();
		break;

	case 6:
		return;

	default:
		cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�. ȸ�� ���� ȭ������ ���ư��ϴ�." << endl;
		cout << "���� ���α׷��� �����ϰ� �����ôٸ� 'Ctrl + C'�� �����ּ���." << endl << endl;
	}
}

string days_calculate(const string& _start_date, const int& membership) //������� ��¥ ��� �Լ�
{
	int _year = stoi(_start_date.substr(0, 2));		//�⵵
	int _month = stoi(_start_date.substr(2, 2));	//��
	int _day = stoi(_start_date.substr(4, 2));		//��¥�� ����ȭ

	if ((_month + membership) > 12)			// �� ���� 12���� Ŀ����� ��¥ ���
	{
		_year += (_month + membership) / 12;
		_month = (_month + membership) % 12;
	}

	return to_string(_year * 10000 + _month * 100 + _day); //������ ���ڿ��� ��ȯ �� ��ȯ
}

