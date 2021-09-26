#pragma once
#include <string>
#include <iostream>
using namespace std;

struct student {

	student();
	student(string*, string*, string*, string*, string*, string*, string*, int);
	student(student const& s);
	~student();
	void set_adress(string adress_);
	void set_telephone(string telephone_);
	void set_faculty(string faculty);
	void set_course(int course_);
	string get_bd() const;
	string get_faculty() const;
	int get_course() const;
	void show() const;
private:
	string* second_name;
	string* first_name;
	string* patronymic;
	string* birth_day;
	string* adress;
	string* telephone;
	string* faculty;
	int course;

};