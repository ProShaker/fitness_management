#pragma once
#include <string>
#include <iostream>

using namespace std;

// main파일에서 사용할 열거형과 변수
enum { NORMAL = 1, SPINNING, PT, PILATES };
static int member_Classification = 0;

// 회원 정보 변수를 담고 있는 기반 클래스
class member
{
	friend class member_list;		//해당 클래스의 멤버에 접근하기 위한 friend 클래스 선언

public:
	int member_number;	//회원번호

//private으로 회원 정보를 보호
private:
	string name;		//이름
	string hpnumber;	//핸드폰 번호
	string gender;		//성별
	string date_class;	//수업요일
	string trainer;		//담당 트레이너
	string date_start;	//시작일
	string date_end;	//종료일
	string time_class;	//수업시간
	string clothes;		//운동복 대여여부

	member* next; //다음 멤버의 주소를 가리킬 포인터 변수

	member();
};

//회원 정보를 다루는 함수를 갖는 클래스
class member_list
{
private:
	member* head; //첫 번째 노드
	member* tail; //마지막 노드

	// 특정 회원 객체의 주소를 반환하는 멤버함수
	member* member_location(const int& member_number);
	//회원정보 출력 함수
	void member_profile(member* member) const; 

public:

	member_list();

	//스피닝, PT, 필라테스 클래스에서 오버라이딩
	virtual void add_member();				//회원 추가 함수
	virtual void rewrite_member();			//회원 정보 수정
	virtual void search_member() const;		//회원 검색 함수 
	virtual void print_member() const;		//회원 명부 출력 함수
	virtual void delete_member();			//회원 정보 삭제 함수

};

void menu_fitness_management(member_list* member); //메뉴 함수

string days_calculate(const string& _start_date, const int& membership); //멤버십 날짜 계산 함수

class special_member_list : public member_list
{
	void add_member();				//회원 추가 함수
	void rewrite_member();			//회원 정보 수정
	void search_member() const;		//회원 검색 함수 
	void print_member() const;		//회원 명부 출력 함수
	void delete_member();			//회원 정보 삭제 함수
};
// 스피닝 클래스 
class spinning_member : public special_member_list
{
};

// PT 클래스 
class pt_member : public special_member_list
{
};

// 필라테스 클래스
class pilates_member : public special_member_list
{
};

