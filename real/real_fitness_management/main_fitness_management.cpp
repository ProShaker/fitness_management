#include "def_fitness_management.h"

int main()
{
	member_list* ptr_member = nullptr;

	while (1) 
	{
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
			ptr_member = new member_list;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "스피닝 회원을 선택하셨습니다." << endl << endl;
			ptr_member = new spinning_member;
		}

		else if (member_Classification == PT)
		{
			cout << "PT 회원을 선택하셨습니다." << endl << endl;
			ptr_member = new pt_member;
		}

		else if (member_Classification == PILATES)
		{
			cout << "필라테스 회원을 선택하셨습니다." << endl << endl;
			ptr_member = new pilates_member;
		}

		else
		{
			cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
			cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		}
		menu_fitness_management(ptr_member);
	}
	
	delete ptr_member; //동적할당된 객체의 메모리 해제

	return 0;
}