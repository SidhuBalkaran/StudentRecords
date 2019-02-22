
#include "stdafx.h"
#include "CStudent.h"
#include "CCourse.h"







string CStudent::getstudent_num() {
	return newstudent_num;
}
float CStudent::getlab() {
	return newlab;
}
float CStudent::getquiz() {
	return newquiz;
}
float CStudent::getmidterm() {
	return newmidterm;
}
float CStudent::getfinal_exam() {
	return newfinal_exam;
}

void CStudent::setstudent_num(string  student_num)
{
	newstudent_num = student_num;
}
void CStudent::setlab(float lab)
{
	newlab= lab;
}
void CStudent::setquiz(float quiz)
{
	newquiz = quiz;
}
void CStudent::setmidterm(float  midterm)
{
	newmidterm = midterm;
}
void CStudent::setfinal_exam(float final_exam)
{
	newfinal_exam= final_exam;
}