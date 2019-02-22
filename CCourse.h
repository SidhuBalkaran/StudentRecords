#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "stdafx.h"
#include<iomanip>
#include "CStudent.h"
using namespace std;

#ifndef CCourse_H
#define CCourse_H

class CCourse {
public:
	
	void add();
	void print_grades();
	void edit(int &x);
	void delete_student();
	void save(string &name);
	void student_info();
	int error(string str);
	void load(string &file);
private:

	CStudent student;

	vector<CStudent> course;
	
};
#endif