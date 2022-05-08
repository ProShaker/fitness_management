#include "def_fitness_management.h"
#define y true
#define n true

//프로그램 종료 전까지 메뉴 화면을 계속 출력한다.
void action_fitness_management()
{
	while (1)
	{
		menu_fitness_management();
	}
}

//메뉴 화면을 출력하는 함수 정의문
void menu_fitness_management()
{

	cout << "-----<헬스장 회원관리 프로그램 메인화면>-----" << endl << endl;
	cout << "1. 회원 추가" << endl;
	cout << "2. 회원 정보 수정(락커, 운동복, 개인 정보)" << endl;
	cout << "3. 회원 검색" << endl;
	cout << "4. 회원 명부 출력" << endl;
	cout << "5. 회원 삭제" << endl << endl;

	cout << "-----<원하시는 메뉴 번호를 선택해주세요.>-----" << endl;
	cin >> menu_numb;
	cout << endl;
	cout << "-----<" << menu_numb << "번 메뉴 화면입니다.>-----" << endl;

	//switch문을 통해 메뉴에 진입한다.
	switch (menu_numb)
	{
	case 1:
		cout << "회원 추가 화면입니다." << endl;
		normal_management.add_member()
		add_member();
		break;

	case 2:
		cout << "회원 정보 수정 화면입니다." << endl;
		normal_management.rewrite_member();
		break;

	case 3:
		cout << "회원 검색 화면입니다." << endl;
		normal_management.search_member();
		break;

	case 4:
		cout << "회원 명부 출력 화면입니다." << endl;
		normal_management.print_member();
		break;

	case 5:
		cout << "회원 삭제 화면입니다." << endl;
		normal_managemen.delete_member();
		break;

	//1 ~ 5 이외의 숫자를 고를 경우 메뉴 함수를 재호출한다.
	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
		cout << "만약 프로그램을 종료하고 싶으시다면 Ctrl + K를 눌러주세요." << endl;
		menu_fitness_management();
	}
}

//회원 구분 선택 함수
void separate_member()
{
	cout << "회원 구분을 선택해주세요." << endl;
	cout << "1. 일반 회원" << endl;
	cout << "2. 스피닝 회원" << endl;
	cout << "3. PT 회원" << endl;
	cout << "4. 필라테스 회원" << endl << endl;
	cout << "5. 뒤로 가기" << endl << endl;

	cout << "-----<원하시는 회원 구분 번호를 선택해주세요.>-----" << endl;
	cin >> menu_numb;

	switch(menu_numb)
	{
	case NORMAL:
		cout << "일반 회원을 선택하셨습니다." << endl;
		break;

	case SPINNING:
		cout << "스피닝 회원을 선택하셨습니다." << endl;
		break;

	case PT:
		cout << "PT 회원을 선택하셨습니다." << endl;
		break;

	case PILATES:
		cout << "필라테스 회원을 선택하셨습니다." << endl;
		break;

	case reTurn:
		cout << "뒤로 가기를 선택하셨습니다." << endl;
		normal_management.reTurn();
		break;
		
	//1 ~ 5 이외의 숫자를 고를 경우 회원 구분 함수를 재호출한다.
	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
		separate_member();
	}
}


//회원 추가 함수 정의문
void normal_management::add_member()
{
	separate_member();

	cout << endl;

	cout << "추가할 회원님의 정보를 입력해주세요." << endl;
	cout << "이름 : ";
	cin >> normal_name;
	cout << "핸드폰 번호 (뒤 8자리): ";
	cin >> normal_hpnumber;
	cout << "성별 (남/여) : ";
	cin >> normal_gender;
	cout << "시작일(YYYYMMDD) : ";
	cin >> normal_start;
	cout << "회원권 종류(1, 3, 6, 12개월) : ";
	cin >> memebership;
	cout << "운동복 대여 여부 (y/n) : ";
	cin >> normal_clothes;
	cout << "락커 사용여부 (y/n) : ";
	cin >> normal_locker;
	//추후에 락커 번호 대입하는 부분도 고려해보기

	//스피닝 선택 시 추가 입력
	if (menu_numb == SPINNING)
	{
		//스피닝의 특별 부분
	}

	//PT 선택 시 추가 입력
	else if (menu_numb == PT)
	{
		//PT의 특별 부분
	}

	//필라테스 선택 시 추가 입력
	else
	{
		//필라테스의 특별 부분
	}

}

//회원 정보 수정 함수 정의문
void normal_management::rewrite_member()
{
	separate_member();
}

//회원 검색 함수 정의문
void normal_management::search_member()
{
	separate_member();

}

//회원 명부 출력 함수 정의문
void normal_management::print_member()
{
	separate_member();

}

//회원 삭제 함수 정의문
void normal_management::delete_member()
{
	separate_member();

}
// 뒤로 가기 함수
int normal_management::reTurn()
{
	return 0;
}