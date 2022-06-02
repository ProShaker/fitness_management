#include "def_fitness_management.h"

int main()
{ 
	member_list* ptr_member = nullptr;								// 메뉴함수에서 멤버함수에 접근할 변수
	member_list* normal_member_startnode = new member_list;			// 일반회원의 스타트 노드 주소
	member_list* spinning_member_startnode = new spinning_member;	// 스피닝회원의 스타트 노드 주소
	member_list* pt_member_startnode = new pt_member;				// 피티회원의 스타트 노드 주소
	member_list* pilates_member_startnode = new pilates_member;		// 필라테스회원의 스타트 노드 주소

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
			ptr_member = normal_member_startnode;
		}

		else if (member_Classification == SPINNING)
		{
			cout << "스피닝 회원을 선택하셨습니다." << endl << endl;
			ptr_member = spinning_member_startnode;
		}

		else if (member_Classification == PT)
		{
			cout << "PT 회원을 선택하셨습니다." << endl << endl;
			ptr_member = pt_member_startnode;
		}

		else if (member_Classification == PILATES)
		{
			cout << "필라테스 회원을 선택하셨습니다." << endl << endl;
			ptr_member = pilates_member_startnode;
		}

		else
		{
			cout << "해당 번호는 존재하지 않습니다. 다시 입력해주세요." << endl;
			cout << "만약 프로그램을 종료하고 싶으시다면 'Ctrl + C'를 눌러주세요." << endl << endl;
		}
		menu_fitness_management(ptr_member);
	}
	
	//동적할당된 객체의 메모리 해제
	delete ptr_member; 
	delete normal_member_startnode;
	delete spinning_member_startnode;
	delete pt_member_startnode;
	delete pilates_member_startnode;
	return 0;
}