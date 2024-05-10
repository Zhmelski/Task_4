#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "CStudent.h"
#include "CStudentDB.h"

CStudentDataBase::CStudentDataBase()
{
	ArrayStudents = nullptr;
	Size = 0;
	FilePath = nullptr;
}

CStudentDataBase::CStudentDataBase(CStudent* array_students, int AmountStudents, const char* file_path)
{
	Size = AmountStudents;
	ArrayStudents = new CStudent[Size];
	for (int i = 0; i < Size; ++i)
	{	
		ArrayStudents[i] = array_students[i];
	}

	FilePath = new char[strlen(file_path) + 1];
	strcpy(FilePath, file_path);
}

CStudentDataBase::CStudentDataBase(const CStudentDataBase& Another)
{
	Size = Another.Size;
	ArrayStudents = new CStudent[Size];
	for (int i = 0; i < Size; ++i)
	{
		ArrayStudents[i] = Another.ArrayStudents[i];
	}

	FilePath = new char[strlen(Another.FilePath) + 1];
	strcpy(FilePath, Another.FilePath);
}

CStudentDataBase::CStudentDataBase(CStudentDataBase&& Another)
{
	Size = Another.Size;
	ArrayStudents = new CStudent[Size];
	for (int i = 0; i < Size; ++i)
	{
		ArrayStudents[i] = Another.ArrayStudents[i];
	}
	FilePath = new char[strlen(Another.FilePath) + 1];
	strcpy(FilePath, Another.FilePath);

	Another.ArrayStudents = nullptr;
	Another.Size = 0;
	Another.FilePath = nullptr;
}

CStudentDataBase::~CStudentDataBase()
{
	delete[] ArrayStudents;
	delete[] FilePath;
}

void CStudentDataBase::AddStudentFromKeyboard()
{
	CStudent NewStudent;
	cout << "\n\nВведите информаию о новом студенте:\n\n";
	NewStudent.FillFromKeyboard();
	ClearCache(NMAX);

	CStudent* temp = new CStudent[Size + 1];
	for (int i = 0; i < Size; ++i)
	{
		temp[i] = ArrayStudents[i];
	}
	temp[Size++] = NewStudent;

	delete[] ArrayStudents;
	ArrayStudents = temp;
}

void CStudentDataBase::LoadDataBaseFromBinFile(const char* FileName)
{
	ifstream InFile(FileName, ios::binary);
	if (!InFile)
	{
		cout << "Ошибка открытия файла для чтения";
		return;
	}

	delete[] ArrayStudents;
	ArrayStudents = nullptr;
	Size = 0;

	CStudent Student;
	while (InFile.read(reinterpret_cast<char*>(&Student), sizeof(CStudent)))
	{
		CStudent* temp = new CStudent[Size + 1];
		for (int i = 0; i < Size; ++i)
		{
			temp[i] = ArrayStudents[i];
		}
		temp[Size++] = Student;

		delete[] ArrayStudents;
		ArrayStudents = temp;
	}
	InFile.close();
}

void CStudentDataBase::SaveDataBaseToBinFile(const char* FileName)
{
	ofstream OutFile(FileName, ios::binary);
	if (!OutFile)
	{
		cout << "Ошибка открытия файла для записи";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		OutFile.write(reinterpret_cast<char*>(&ArrayStudents[i]), sizeof(CStudent));
	}
	OutFile.close();
}

void CStudentDataBase::PrintDataBase()
{
	for (int i = 0; i < Size; ++i)
	{
		cout << "============================================================\n";
		ArrayStudents[i].Print();
		cout << "============================================================\n\n";
	}
}

//CStudent* CStudentDataBase::FindStudentDataBase(char* Name)
//{
//	CStudent* foundStudent = nullptr;
//	int foundCount = 0;
//
//	for (int i = 0; i < Size; ++i)
//	{
//		if (strcmp(ArrayStudents[i].GetName(), Name) == 0)
//		{
//			// Нашли студента с совпадающим именем
//			// Увеличиваем размер массива foundStudents и добавляем студента
//			CStudent* temp = new CStudent[foundCount + 1];
//			for (int j = 0; j < foundCount; ++j)
//			{
//				temp[j] = foundStudent[j];
//			}
//			temp[foundCount++] = ArrayStudents[i];
//
//			delete[] foundStudent;
//			foundStudent = temp;
//		}
//	}
//
//	return foundStudent;
//}

int CStudentDataBase::FindStudentDataBase(char* Name, CStudent* FoundStudent, int maxFoundStudents)
{
	int foundCount = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (foundCount >= maxFoundStudents)
			break;

		if (strcmp(ArrayStudents[i].GetName(), Name) == 0)
			FoundStudent[foundCount++] = ArrayStudents[i];
	}
	return foundCount;
}

int CStudentDataBase::FindCountOfExcellentStudents(unsigned short SelectedCourse, unsigned short SelectedSubject)
{
	int count = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (ArrayStudents[i].IsExcellent(SelectedCourse, SelectedSubject))
			++count;
	}
	return count;
}

int CStudentDataBase::GetSize() const
{
	return Size;
}