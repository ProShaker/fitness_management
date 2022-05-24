#include "def_fitness_management.h"
//해결해야 할 문제 : 날짜 계산
//add_member 안되는 것
//
int main()
{
	member_list* ptr_member = nullptr;

	while (1) {
		cout << "-----<헬스장 회원관리 프로그램 메인화면>-----" << endl << endl;
		cout << "1. 일반 회원" << endl;
		cout << "2. 스피닝 회원" << endl;
		cout << "3. PT 회원" << endl;
		cout << "4. 필라테스 회원" << endl << endl;
		cout << "원하시는 회원 구분 번호를 선택해주세요. : ";
		cin >> member_Classification;
		cout << endl;

		if (member_Classification == NORMAL)
		{
			cout << "일반 회원을 선택하셨습니다." << endl << endl;
			cout << "-----<일반 회원관리 메뉴>-----" << endl << endl;
			member_list normal;
			ptr_member = &normal;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "스피닝 회원을 선택하셨습니다." << endl << endl;
			cout << "-----<스피닝 회원관리 메뉴>-----" << endl << endl;
			spinning_member spinning;
			ptr_member = &spinning;
		}

		else if (member_Classification == PT)
		{
			cout << "PT 회원을 선택하셨습니다." << endl << endl;
			cout << "-----<PT 회원관리 메뉴>-----" << endl << endl;
			pt_member pt;
			ptr_member = &pt;
		}

		else if (member_Classification == PILATES)
		{
			cout << "필라테스 회원을 선택하셨습니다." << endl << endl;
			cout << "-----<필라테스 회원관리 메뉴>-----" << endl << endl;
			pilates_member pilates;
			ptr_member = &pilates;
		}

		else
		{
			cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
			cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		}

		menu_fitness_management(ptr_member);
	}
	return 0;
}