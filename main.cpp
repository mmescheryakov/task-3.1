#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;

void read_data(student** stds, ifstream& is, string path) {

	is.open(path);

	if (!is.is_open())
		cout << "Error" << endl;
	else {
		string data[8] = { "", "", "", "", "", "", "", "" };
		int count = 0;
		int count_s = 0;
		while (!is.eof())
		{
			is >> data[count++];
			
			if (count == 8) {
				stds[count_s++] = new student(new string(data[0]), new string(data[1]), new string(data[2]), new string(data[3]), new string(data[4]),
					new string(data[5]), new string(data[6]), int(data[7][0]) - 48);
				count = 0;
			}
		}
	}
}

void print_data(student** stds, size_t size_) {
	for (size_t i = 0; i < size_; i++) {
		stds[i]->show();
		cout << endl;
	}
}

void zapros_a(student** stds, size_t size_, string faculty_) {
	cout << endl << "\ta) Faculty is " << faculty_ << endl;
	for (size_t i = 0; i < size_; i++) {
		if (stds[i]->get_faculty() == faculty_)
		{
			stds[i]->show();
			cout << endl;
		}			
	}
}

void zapros_b(student** stds, size_t size_, int course_) {
	cout << endl << "\tb) Course is " << course_ << endl;
	for (size_t i = 0; i < size_; i++) {
		if (stds[i]->get_course() == course_)
		{
			stds[i]->show();
			cout << endl;
		}			
	}
}

void zapros_v(student** stds, size_t size_, int year) {
	cout << endl << "\tc) Year is " << year << endl;
	for (size_t i = 0; i < size_; i++) {
		string s = stds[i]->get_bd();
		s = s.substr(6, 4);
		if (stoi(s) > year)
		{
			stds[i]->show();
			cout << endl;
		}			
	}
}

int main() {

	setlocale(LC_ALL, "Russian");
	student** stds = new student*[6];
	ifstream is;
	read_data(stds, is, "data.txt");
	print_data(stds, 6);
	zapros_a(stds, 6, "RK-2");
	zapros_b(stds, 6, 4);
	zapros_v(stds, 6, 1999);
	
	for (size_t i = 0; i < 6; i++)
		delete stds[i];
	delete[] stds;

	return 0;
}
