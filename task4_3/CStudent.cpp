#include "CStudent.h"

void ClearCache(int N)
{
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(N + 1, '\n');
	}
}

void CStudent::FillFromKeyboard()
{
	/*while (true)
	{
		bool NewStudent;
		cout << "\n�������� ������ ��������? (1 - ��, 0 - ���): ";
		cin >> NewStudent;
		if (NewStudent != 1 && NewStudent != 0)
		{
			cout << "(1 - ��, 0 - ���): ";
			bool p = true;
			while (p)
			{
				cin >> NewStudent;
				if (NewStudent == 1 || NewStudent == 0)
				{
					p = false;
					break;
				}
				cout << "(1 - ��, 0 - ���): ";
			}
		}

		if (NewStudent == 0)
			break;
	}*/	

	cout << "������� ���: ";
	cin.getline(FullName, NMAX);

	do
	{
		cout << "������� �������: ";
		cin >> Age;

		if (Age < 16)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (Age < 16);

	do
	{
		cout << "������� ����: ";
		cin >> Course;

		if (Course < 1 || Course > 6)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (Course < 1 || Course > 6);

	do
	{
		cout << "������� ���(1 - ���., 0 - ���.): ";
		cin >> Gender;

		if (Gender != 1 && Gender != 0)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (Gender != 1 && Gender != 0);

	do
	{
		cout << "������� ������ �� ����������: ";
		cin >> MathProgress;

		if (MathProgress < 1 || MathProgress > 10)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (MathProgress < 1 || MathProgress > 10);

	do
	{
		cout << "������� ������ �� ������: ";
		cin >> PhysProgress;

		if (PhysProgress < 1 || PhysProgress > 10)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (PhysProgress < 1 || PhysProgress > 10);

	do
	{
		cout << "������� ������ �� ����������������: ";
		cin >> ProgProgress;

		if (ProgProgress < 1 || ProgProgress > 10)
		{
			cout << "������� ������������ �����\n";
			continue;
		}
	} while (ProgProgress < 1 || ProgProgress > 10);
}

void CStudent::LoadFromBinFile(const char* FileName)
{
	ifstream FileStudent_reading("FileStudent.bin", ios::binary);
	if (!FileStudent_reading)
	{
		cout << "������ �������� ����� ��� ������: ";
		return;
	}

	FileStudent_reading.read(reinterpret_cast<char*>(this), sizeof(CStudent));
	FileStudent_reading.close();
}

void CStudent::SaveToBinFile(const char* FileName)
{
	ofstream FileStudent_writing("FileStudent.bin", ios::binary);
	if (!FileStudent_writing)
	{
		cout << "������ �������� ����� ��� ������" << endl;
		return;
	}

	FileStudent_writing.write(reinterpret_cast<const char*>(this), sizeof(CStudent));
	FileStudent_writing.close();
}

void CStudent::Print()
{
	cout << "���: " << FullName << endl;
	cout << "�������: " << Age << endl;
	cout << "����: " << Course << endl;

	if (Gender == 1)
		cout << "���: �������" << endl;
	else if (Gender == 0)
		cout << "���: �������" << endl;

	cout << "������������ �� ����������: " << MathProgress << endl;
	cout << "������������ �� ������: " << PhysProgress << endl;
	cout << "������������ �� ����������������: " << ProgProgress << endl;
}

int CStudent::FindNumberOfExcellentStudents(CStudent* Student, int IndStudent, int SelectedCourse, int SelectedSubject)
{
	int NumberOfExcellentStudents = 0;

	if (SelectedSubject == 1)
	{
		for (int i = 0; i < IndStudent; ++i)
		{
			if (Student[i].Course == SelectedCourse && Student[i].MathProgress >= 9)
				++NumberOfExcellentStudents;
		}
	}

	if (SelectedSubject == 2)
	{
		for (int i = 0; i < IndStudent; ++i)
		{
			if (Student[i].Course == SelectedCourse && Student[i].PhysProgress >= 9)
				++NumberOfExcellentStudents;
		}
	}

	if (SelectedSubject == 3)
	{
		for (int i = 0; i < IndStudent; ++i)
		{
			if (Student[i].Course == SelectedCourse && Student[i].ProgProgress >= 9)
				++NumberOfExcellentStudents;
		}
	}

	return NumberOfExcellentStudents;
}

CStudent::CStudent()
{
	FullName[0] = '\0';
	Age = 0;
	Course = 0;
	Gender = 0;
	MathProgress = 0;
	PhysProgress = 0;
	ProgProgress = 0;
}

CStudent::CStudent(const char* Name, unsigned short age, unsigned short course, bool gender, float math_progress, float phys_progress, float prog_progress)
{
	strncpy_s(FullName, Name, NMAX);
	FullName[NMAX - 1] = '\0';
	this->Age = age;
	this->Course = course;
	this->Gender = gender;
	this->MathProgress = math_progress;
	this->PhysProgress = phys_progress;
	this->ProgProgress = prog_progress;
}

//CStudent::CStudent(const CStudent& Another)
//{
//	strncpy_s(FullName, Another.FullName, NMAX);
//	FullName[NMAX - 1] = '\0';
//	Age = Another.Age;
//	Course = Another.Course;
//	Gender = Another.Gender;
//	MathProgress = Another.MathProgress;
//	PhysProgress = Another.PhysProgress;
//	ProgProgress = Another.ProgProgress;
//}
//
//CStudent::CStudent(CStudent&& Another)
//{
//	strncpy_s(FullName, Another.FullName, NMAX);
//	FullName[NMAX - 1] = '\0';
//	Age = Another.Age;
//	Course = Another.Course;
//	Gender = Another.Gender;
//	MathProgress = Another.MathProgress;
//	PhysProgress = Another.PhysProgress;
//	ProgProgress = Another.ProgProgress;
//
//	Another.FullName[0] = '\0';
//	Another.Age = 0;
//	Another.Course = 0;
//	Another.Gender = 0;
//	Another.MathProgress = 0;
//	Another.PhysProgress = 0;
//	Another.ProgProgress = 0;
//}
//
//CStudent::~CStudent()
//{
//	cout << "Destructor CStudent done" << endl;
//}

const char* CStudent::GetName() const
{
	return FullName;
}

bool CStudent::IsExcellent (unsigned short SelectedCourse, int SelectedSubect) const
{
	if (Course != SelectedCourse)
		return false;

	float Progress;
	if (SelectedSubect == 1)
		Progress = MathProgress;
	else if (SelectedSubect == 2)
		Progress = PhysProgress;
	else if (SelectedSubect == 3)
		Progress = ProgProgress;

	return Progress >= 9;
}