#include "student.h"

student::student() :
	second_name(nullptr),
	first_name(nullptr),
	patronymic(nullptr),
	birth_day(nullptr),
	adress(nullptr),
	telephone(nullptr),
	faculty(nullptr),
	course(0) {}

student::student(string* second_name_ = nullptr, string* first_name_ = nullptr, string* patronymic_ = nullptr, string* birth_day_ = nullptr, 
	string* adress_ = nullptr, string* telephone_ = nullptr, string* faculty_ = nullptr, int course_ = 0) : 
	second_name(second_name_), 
	first_name(first_name_), 
	patronymic(patronymic_), 
    birth_day(birth_day_), 
	adress(adress_), 
	telephone(telephone_), 
	faculty(faculty_), 
	course(course_) {}

student::student(student const& s): 
	second_name(new string(*s.second_name)), 
	first_name(new string(*s.first_name)), 
	patronymic(new string(*s.patronymic)),
    birth_day(new string(*s.birth_day)), 
	adress(new string(*s.adress)), 
	telephone(new string(*s.telephone)), 
	faculty(new string(*s.faculty)), 
	course(s.course) {}

student::~student()
{
	if (second_name)
		delete second_name;
	if (first_name)
		delete first_name;
	if (patronymic)
		delete patronymic;
	if (birth_day)
		delete birth_day;
	if (adress)
		delete adress;
	if (telephone)
		delete telephone;
	if (faculty)
		delete faculty;
}

void student::set_adress(string adress_)
{
	if (adress)
		delete adress;
	adress = new string(adress_);
}

void student::set_telephone(string telephone_)
{
	if (telephone)
		delete telephone;
	telephone = new string(telephone_);
}

void student::set_faculty(string faculty_)
{
	if (faculty)
		delete faculty;
	faculty = new string(faculty_);
}

void student::set_course(int course_) { course = course_; }

string student::get_bd() const { return *(birth_day); }

string student::get_faculty() const { return *(faculty);}

int student::get_course() const { return course; }

void student::show() const
{
	cout << "Фамилия: " << *second_name << endl
		<< "Имя: " << *first_name << endl
		<< "Отчество: " << *patronymic << endl
		<< "Дата рождения: " << *birth_day << endl
		<< "Адрес: " << *adress << endl
		<< "Телефон: " << *telephone << endl
		<< "Факультет: " << *faculty << endl
		<< "Курс: " << course << endl;
}
