#include "stdafx.h"
#include "CStudent.h"
#include "CCourse.h"

void CCourse:: add()
{
	course.push_back(student);
}
void CCourse::print_grades()
{

	int temp;
	float final_grade;
	cout << "#" << setw(8) << "Student" << setw(8) << "Lab" << setw(8) << "Quiz" << setw(14) << "Midterm" << setw(14) << "Final Exam" << setw(14) << "Final Grade" << endl;
		for (size_t i=0;i <  course.size();i++)
		{
			temp = i + 1;	
			cout << temp;
			cout << setprecision(1)<<fixed << setw(10) <<course[i].getstudent_num();
			cout << setprecision(1) <<fixed<< setw(8) << course[i].getlab();
			cout << setprecision(1) <<fixed<< setw(7) << course[i].getquiz();
			cout << setprecision(1) <<fixed<< setw(12) << course[i].getmidterm();
			cout << setprecision(1)<<fixed << setw(14) << course[i].getfinal_exam();
			
			final_grade= (0.40*course[i].getlab()) + (0.10*course[i].getquiz()) + (0.20*course[i].getmidterm()) + (0.30*course[i].getfinal_exam());

			cout <<setprecision(2) <<setw(12) <<final_grade<< endl;
			
		}
}
void CCourse::edit(int &x)
{
	course[x - 1] = student;
}
void CCourse::delete_student()
{
int delete_num;
cout << "Student to Delete:";
cin >> delete_num;
course.erase(course.begin() + (delete_num-1));
}
void CCourse::save(string &name)
{
	int temp;

	ofstream record;
	record.open(name, ios::out);
	//record << "#" << setw(8) << "Student" << setw(8) << "Lab" << setw(8) << "Quiz" << setw(14) << "Midterm" << setw(14) << "Final Exam" << endl;//setw(14) << "Final Grade" << endl;
	for (size_t i = 0; i < course.size(); i++)
	{
		record << setprecision(1) << fixed << setw(10) << course[i].getstudent_num();
		record << setprecision(1) << fixed << setw(8) << course[i].getlab();
		record << setprecision(1) << fixed << setw(7) << course[i].getquiz();
		record << setprecision(1) << fixed << setw(12) << course[i].getmidterm();
		record << setprecision(1) << fixed << setw(14) << course[i].getfinal_exam()<<endl;	
	}
	record.close();
	cout << "\nData has been saved" << endl;
}

void CCourse::load(string &file)
{
	course.clear();

	int temp=0;
	
	string name;
	float lab_mark, quiz_mark, midterm_mark, final_mark;

	ifstream record;
	record.open(file, ios::in);
	if (record.is_open() == true)
	{
		while (!record.eof())//getline(record,store))
		{
			record >> setprecision(1) >> fixed >> setw(10) >> name;
			student.setstudent_num(name);
			record >> setprecision(1) >> fixed >> setw(8) >> lab_mark;
			student.setlab(lab_mark);
			record >> setprecision(1) >> fixed >> setw(7) >> quiz_mark;
			student.setquiz(quiz_mark);
			record >> setprecision(1) >> fixed >> setw(12) >> midterm_mark;
			student.setmidterm(midterm_mark);
			record >> setprecision(1) >> fixed >> setw(14) >> final_mark;
			student.setfinal_exam(final_mark);
			
			/*getline(record, store);

			getline(record, store);
			student.setstudent_num(store);
			getline(record, store);
			student.setlab(store);
			getline(record, store);
			student.setquiz(store);
			getline(record, store);
			student.setmidterm(store);
			getline(record, store);
			student.setfinal_exam(store);*/
			course.push_back(student);
			temp++;
		}
		course.erase(course.begin()+(temp-1));
		record.close();
		cout << "\nData has been loaded" << endl;
	}
	else
		cout << "messed up";


//	
}
void CCourse::student_info()
{
	float final_grade;
	string student_n;
	string lab;
	string quiz;
	string midterm;
	string exam;
	float lab1, quiz1, midterm1, exam1;

	int error1 = 0;
	do {
		cout << "Student Number:";
		cin >> student_n;
		student.setstudent_num(student_n);
		if (student_n.length() != 9)
			error1++;
		else if ((student_n.compare(0, 3, "A00") != 0) && (student_n.compare(0, 3, "A01") != 0) && (student_n.compare(0, 3, "a00") != 0) && (student_n.compare(0, 3, "a01") != 0))
			error1++;
		else
			error1 = 0;
		for (int i = 1; i < student_n.length(); i++)
		{
			if (!isdigit(student_n[i]))
				error1++;
		}
		if (error1)
			cout << "Invalid ID" << endl;


	} while (error1 != 0);
	do
	{
		cout << "Lab Grade:";
		cin >> lab;
		lab1 = stof(lab);
		//student.setlab(lab1);
		if (error(lab))
		{
			cout << "Invalid entry" << endl;
		}
		else
			student.setlab(lab1);
	} while (error(lab) != 0);
	do
	{
		cout << "Quiz Grade:";
		cin >> quiz;
		quiz1 = stof(quiz);
		//student.setquiz(quiz1);
		if (error(quiz))
		{
			cout << "Invalid entry" << endl;
		}
		else
			student.setquiz(quiz1);
	} while (error(quiz) != 0);
	do
	{
		cout << "Midterm Grade:";
		cin >> midterm;
		midterm1 = stof(midterm);
		//student.setmidterm(midterm1);
		if (error(midterm))
		{
			cout << "Invalid entry" << endl;
		}
		else
			student.setmidterm(midterm1);
	} while (error(midterm) != 0);
	do
	{
		cout << "FINAL exam Grade:";
		cin >> exam;
		exam1 = stof(exam);
		//student.setfinal_exam(exam1);
		if (error(exam))
		{
			cout << "Invalid entry" << endl;
		}
		else
			student.setfinal_exam(exam1);
	} while (error(exam) != 0);

}
int CCourse::error(string str)
{
	int err_num = 0;
	int alpha = 0;
	int beta = 0;
	int gamma = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			alpha++;
			return alpha;
		}
		if (!isalnum(str[i]))
		{
			if (str[i] != '.')
			{
				beta++;
				return beta;
			}
			if (str[0] == '.')
			{
				gamma++;
				return gamma;
			}
		}
	}
	if ((stof(str) < 0) || (stof(str) > 100))
		gamma++;
	if (gamma || beta || alpha)
		err_num = 1;
	else
		err_num = 0;
	return err_num;
}
