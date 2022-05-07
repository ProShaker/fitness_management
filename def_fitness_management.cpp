#include "def_fitness_management.h"

//프로그램 종료 전까지 메뉴 화면을 계속 출력한다.
void action_fitness_management()
{
	while (1)
	{
		menu_fitness_management();
	}
}

void menu_fitness_management()
{
	//메뉴 번호를 저장할 변수, 메모리 관리를 위해 char 자료형을 사용한다.
	char menu_numb;

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

		//1 ~ 5 이외의 숫자를 고를 경우 메뉴 함수를 재호출한다.
	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요.";
		menu_fitness_management();
	}
}

//회원 구분을 위한 열거형
enum
{
	NORMAL = 1,
	SPINNING,
	PT,
	PILATES
};

//메뉴 번호를 저장할 변수, 메모리 관리를 위해 char 자료형을 사용한다.
//전역으로 선언해서 다른 함수에도 이용할 수 있게 한다.
char separate_numb;

//회원 구분 선택 함수
void separate_member()
{
	cout << "회원 구분을 선택해주세요." << endl;
	cout << "1. 일반 회원" << endl;
	cout << "2. 스피닝 회원" << endl;
	cout << "3. PT 회원" << endl;
	cout << "4. 필라테스 회원" << endl << endl;

	cout << "-----<원하시는 회원 구분 번호를 선택해주세요.>-----" << endl;
	//전역으로 사용한 변수를 가져온다는 것을 명시하기 위해 영역지정 연산자를 사용한다.
	cin >> ::separate_numb;

	switch(::separate_numb)
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

	default:
		cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요.";
		separate_member();
	}
}

//회원 추가 함수 정의문
void normal_management::add_member()
{
	separate_member();
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