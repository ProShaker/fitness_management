#pragma once
#include <iostream>
using namespace std;

const int name_len = 11;

void action_fitness_management();

void menu_fitness_management();

//메뉴 번호를 저장할 변수, 메모리 관리를 위해 char 자료형을 사용한다.
char menu_numb;

enum {
	NORMAL = 1,
	SPINNING,
	PT,
	PILATES,
	reTurn
};
//일반 회원 클래스
class normal_management {

//개인정보는 private으로 보호한다.
private:
	//이름, 핸드폰 번호, 성별
	char *normal_name;
	int normal_hpnumber;
	char normal_gender;

public:
//운동 시작일, 운동복 관리 변수는 공용으로 값을 다루기 편하게 한다.
//회원권 시작일에 const 키워드를 사용해서 이용권 종류를 더한 값이 회원권 종료일이다.
	const int normal_start;
	int normal_end;
	char memebership;
	bool normal_clothes;
	char normal_locker;

	void add_member();
	void rewrite_member();
	void search_member();
	void print_member();
	void delete_member();
	int reTurn();
};

// 특별 클래스 - 노말 클래스의 상속
class special_management : normal_management
{
public:
	//수업 시간표, 수업 요일, 트레이너 이름, 총 PT 횟수
	char class_time;
	char class_day[2];
	char trainer[name_len];
	const int PT_number;
};

// 스피닝 클래스 - 특별 클래스의 상속
class spinning_management : special_management
{
};

// PT 클래스 - 특별 클래스의 상속
class pt_management : special_management
{
};

// 필라테스 클래스 - 특별 클래스의 상속
class pilates_management : special_management
{
};


