
#include <vector>
#include <iostream>
#include<string>
#include "stdafx.h"
#include<iomanip>
using namespace std;

#ifndef CStudent_H
#define CStudent_H

class CStudent {
public:
	//constructors

	//accessor functions
	string getstudent_num();
	float getlab();
	float getquiz();
	float getmidterm();
	float getfinal_exam();

	//mutators
	void setstudent_num(string);
	void setlab(float);
	void setquiz(float);
	void setmidterm(float);
	void setfinal_exam(float);

private:
	string newstudent_num;
	float newlab;
	float newquiz;
	float newmidterm;
	float newfinal_exam;

};
#endif