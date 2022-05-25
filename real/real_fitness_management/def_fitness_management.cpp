#include "def_fitness_management.h"

member::member()
{
	//string 변수 
	name = "";			//이름
	hpnumber = "";		//핸드폰 번호
	gender = "";		//성별
	date_class = "";	//수업요일
	date_start = "";	//시작일
	date_end = "";		//종료일
	trainer = "";		//담당 트레이너
	clothes = "";		//운동복 대여여부
	time_class = "";	//수업시간
	member_number = 0;	//회원번호
	member* next = nullptr;
}

member* member_list::member_location(const int& member_number)
{
	//first_node 부터 시작해서 빈 공간이 나올 때까지 다음 회원 객체 주소로 넘어감
	for (member* current_location = head; current_location != NULL; current_location->next)
	{
		//입력받은 회원번호와 주소가 가리키는 회원번호가 같다면 현재 주소 반환
		if (member_number == current_location->member_number)
		{
			return current_location;
		}
	}
	return NULL;
}

void member_list::member_profile(member* ptr_member) const
{
	cout << "회원 번호 | 이름 | 핸드폰 번호 | 성별 | 회원권 시작일 | 회원권 종료일 | 운동복 대여 여부" << endl << endl;
	cout << ptr_member->member_number + 1 << " " << ptr_member->name << " " << " "<< ptr_member->hpnumber << " " << ptr_member->gender 
		<< " " << ptr_member->date_start << " " << ptr_member->date_end << " " << ptr_member->clothes << endl << endl;
}

//member_list의 생성함수
//새로운 member(회원 클래스)객체의 주소 : 시작 노드로 지정
member_list::member_list()
{
	member* start_node = new member;
	head = start_node;
	tail = start_node;
}

void member_list::add_member()
{
	member* new_member = new member; //member 객체 동적할당

	string _name, _hpnumber, _gender, _date_start, _date_end, _clothes;
	int _membership;
	static int _member_number = 0;

	cout << "추가할 회원님의 정보를 입력해주세요." << endl;

	cout << "이름 : ";
	cin >> _name;

	cout << "핸드폰 번호 (010-0000-0000): ";
	cin >> _hpnumber;

	cout << "성별 (남/여) : ";
	cin >> _gender;

	cout << "시작일(YYMMDD) : ";
	cin >> _date_start;

	cout << "회원권 종류(개월 수 입력) : ";
	cin >> _membership;
	_date_end = days_calculate(_date_start, _membership);

	cout << "운동복 대여 여부 (y/n) : ";
	cin >> _clothes;

	new_member->member_number = _member_number;
	new_member->name = _name;
	new_member->hpnumber = _hpnumber;
	new_member->gender = _gender;
	new_member->date_start = _date_start;
	new_member->date_end = _date_end;
	new_member->clothes = (_clothes == "y") ? true : false; //삼항연산자, y(아스키 코드 121) 입력시 true

	_member_number++;

	tail->next = new_member; //next, tail변수가 추가된 회원 객체를 가리키도록 한다.
	tail = new_member;

	member_profile(new_member);
}

void member_list::rewrite_member()
{
	int _membership = 0, _member_number = 0;
	string _date_end, _clothes;
	member* current_location = member_location(_member_number); //회원 번호로 회원 정보에 접근하는 포인터변수

	cout << "변경할 회원님의 회원번호를 입력해주세요. : ";
	cin >> _member_number;

	if (current_location == NULL)
	{
		cout << "해당 회원번호에 해당하는 회원님의 정보가 존재하지 않습니다. " << endl;
	}
	else
	{
		cout << endl << endl;

		member_profile(current_location);

		cout << endl << "수정할 정보를 입력해주세요." << endl;

		cout << "이름 : ";
		cin >> current_location->name;

		cout << "핸드폰 번호 (010-0000-0000): ";
		cin >> current_location->hpnumber;

		cout << "성별 (남/여) : ";
		cin >> current_location->gender;

		cout << "시작일(YYMMDD) : ";
		cin >> current_location->date_start;

		cout << "회원권 종류(개월 수 입력) : ";
		cin >> _membership;
		_date_end = days_calculate(current_location->date_start, _membership);

		cout << "운동복 대여 여부 (y/n) : ";
		cin >> _clothes;
		current_location->clothes = (_clothes == "y") ? true : false;
	}
}

void member_list::search_member() const
{
	member* this_member = head->next;
	string str;

	cout << "1. 회원 번호 검색" << endl << "2. 회원 이름" << endl << endl << "번호를 입력해주세요. : ";
	cin >> member_Classification;
	cout << endl;

	switch (member_Classification)
	{
	case 1:
		cout << "회원번호를 입력해주세요. : ";
		cin >> str;
		while (this_member != NULL) //빈 공간이 나올때까지 반복
		{
			if (this_member->member_number == stoi(str)) member_profile(this_member); //회원 번호가 같으면 프로필(회원 정보)출력
			this_member = this_member->next;
		}
		cout << "검색을 완료했습니다." << endl << endl;
		break;

	case 2:
		cout << "이름 입력해주세요. : ";
		cin >> str;
		while (this_member != NULL) //빈 공간이 나올때까지 반복
		{
			if (this_member->name == str) member_profile(this_member); //이름이 같으면 프로필(회원 정보)출력
			this_member = this_member->next;
		}
		cout << "검색을 완료했습니다." << endl << endl;
		break;

	default:
		cout << "번호가 없습니다." << endl;
		return;
	}
}

void member_list::print_member() const
{
	member* current_location = head->next; //next : 다음 회원 객체의 주소

	//빈 공간이 나올 때까지 회원 정보를 출력한다.
	for (;current_location != NULL; current_location = current_location->next)
		member_profile(current_location);

	cout << "모든 회원 정보를 출력했습니다." << endl << endl;
}

//회원 객체 삭제 함수
void member_list::delete_member()
{
	int _member_number;
	cout << "삭제할 회원님의 회원 번호를 입력해주세요. : ";
	cin >> _member_number;

	member* pre_member = head;			//탐색하는 포인터 변수
	member* current_member = nullptr;	//회원 객체의 주소를 저장할 체크포인트


	while (pre_member->next != NULL)	//다음 객체가 빈 공간이 아닐때까지 반복
	{

		if (pre_member->next->member_number == _member_number)
		{
			current_member = pre_member->next;	//회원 번호가 동일할 경우 체크포인트에 객체의 주소를 저장한다.
			break;
		}
		pre_member = pre_member->next;			//회원 번호가 같지 않을 경우 다음 객체로 이동한다.
	}

	//지우려는 객체가 빈 공간일 경우 함수 종료
	if (pre_member->next == NULL)
	{
		cout << "해당 회원번호에는 회원님이 없습니다." << endl;
		return;
	}

	//지우려는 객체가 빈 공간이 아닐 경우
	pre_member->next = current_member->next; //체크포인트의 다음 객체 주소를 pre_member가 가리키도록 한다.
	delete current_member;					 //메모리 관리를 위해 동적할당된 객체 delete
	cout << "회원 정보를 삭제했습니다." << endl;
}

void menu_fitness_management(member_list* member)
{
	int menu_numb = 0;

	//각 클래스의 회원관리 메뉴
	cout << "1. 회원 추가" << endl;
	cout << "2. 회원 정보 수정" << endl;
	cout << "3. 회원 검색" << endl;
	cout << "4. 회원 명부 출력" << endl;
	cout << "5. 회원 삭제" << endl;
	cout << "6. 나가기" << endl << endl;

	cout << "원하시는 메뉴 번호를 선택해주세요. : ";
	cin >> menu_numb;
	cout << endl;

	switch (menu_numb)
	{
	case 1:
		cout << "회원 추가 화면입니다." << endl << endl;
		member->add_member();
		break;

	case 2:
		cout << "회원 정보 수정 화면입니다." << endl << endl;
		member->rewrite_member();
		break;

	case 3:
		cout << "회원 검색 화면입니다." << endl;
		member->search_member();
		break;

	case 4:
		cout << "회원 명부 출력 화면입니다." << endl << endl;
		member->print_member();
		break;

	case 5:
		cout << "회원 삭제 화면입니다." << endl << endl;
		member->delete_member();
		break;

	case 6:
		return;

	default:
		cout << "해당 번호는 존재하지 않습니다. 회원 구분 화면으로 돌아갑니다." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
	}
}

string days_calculate(const string& _start_date, const int& membership) //멤버십의 날짜 계산 함수
{
	int _year = stoi(_start_date.substr(0, 2));		//년도
	int _month = stoi(_start_date.substr(2, 2));	//월
	int _day = stoi(_start_date.substr(4, 2));		//날짜를 정수화

	if ((_month + membership) > 12)			// 매 달이 12보다 커질경우 날짜 계산
	{
		_year += (_month + membership) / 12;
		_month = (_month + membership) % 12;
	}

	return to_string(_year * 10000 + _month * 100 + _day); //정수를 문자열로 변환 후 반환
}

