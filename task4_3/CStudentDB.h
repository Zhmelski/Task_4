#pragma once
#include "CStudent.h"
#include <iostream>
#include <fstream>

class CStudentDataBase
{
	CStudent* ArrayStudents;
	int Size;
	char* FilePath;

public:
	CStudentDataBase();
	CStudentDataBase(CStudent* array_students, int AmountStudents, const char* file_path);
	CStudentDataBase(const CStudentDataBase& another);
	CStudentDataBase(CStudentDataBase&& another);
	~CStudentDataBase();

	void AddStudentFromKeyboard();
	void LoadDataBaseFromBinFile(const char* FileName);
	void SaveDataBaseToBinFile(const char* FileName);
	void PrintDataBase();
	//CStudent* FindStudentDataBase(char* Name);
	int FindStudentDataBase(char* Name, CStudent* FoundStudent, int maxFoudnStudents);
	int FindCountOfExcellentStudents(unsigned short SelectedCourse, unsigned short SelectedSubject);
	int GetSize() const;
};