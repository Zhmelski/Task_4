#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

void ClearCache(int);

class CStudent
{
	char FullName[NMAX];
	unsigned short Age;
	unsigned short Course;
	bool Gender;
	float MathProgress;
	float PhysProgress;
	float ProgProgress;

public:
	void FillFromKeyboard();
	void LoadFromBinFile(const char* FileName);
	void SaveToBinFile(const char* FileName);
	void Print();
	static int FindNumberOfExcellentStudents(CStudent* Student, int IndStudent, int SelectedCourse, int SelectedSubject);

	CStudent();
	CStudent(const char* Name, unsigned short Age, unsigned short Course, bool Gender, float MathProgress, float PhysProgress, float ProgProgress);
	/*CStudent(const CStudent& Another);
	CStudent(CStudent&& Another);
	~CStudent();*/

	const char* GetName() const;
	bool IsExcellent(unsigned short SelectedCourse, int SelectedSubect) const;
};