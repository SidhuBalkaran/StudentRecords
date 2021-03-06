#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include<string>
#include<iomanip>
#include "CStudent.h"
#include "CCourse.h"

using namespace std;
void print_menu();
int main()
{
	int edit_student;
	int size = 0;
	string n,f;
	CCourse course1;

		char option;
	do {
		int point = 0;
		print_menu();
		cin >> option;
		if ((option == 'A') || (option == 'a'))
		{
			cout << "Adding Student" << endl;
			course1.student_info();
			course1.add();
			size++;
		}
		else if ((option == 'P') || (option == 'p'))
			course1.print_grades();
		else if ((option == 'E') || (option == 'e'))
		{ 
			cout << "Student to edit:";
			cin >> edit_student;
			if ((edit_student< 1) || (edit_student >size))
				cout << "Student Entry does not exist" << endl;
			else
			{
				cout << "Editiing Student" << endl;
				course1.student_info();
				course1.edit(edit_student);
			}
		}
		else if ((option == 'D') || (option == 'd'))
		course1.delete_student();
		else if ((option == 'L') || (option == 'l'))
		{
			cout << "enter the name of the file you wanna load:";
			cin >> f;
			course1.load(f);
		}
		else if ((option == 'S') || (option == 's'))
		{
			cout << "Name the file you wanna save:";
			cin >> n;
			course1.save(n);
		}
	} while ((option != 'Q') && (option != 'q'));
	return 0;
	}
void print_menu()
{
	cout << "\n*****************************************" << endl;
	cout << "ELEX4618 Grade System,by STUDENT NAME" << endl;
	cout << "*****************************************" << endl;
	cout << "(A)dd student" << endl;
	cout << "(E)dit student" << endl;
	cout << "(P)rint grades" << endl;
	cout << "(L)OAD" << endl;
	cout << "(S)AVE" << endl;
	cout << "(Q)uit" << endl;
}