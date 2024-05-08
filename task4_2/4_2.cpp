#include "CStudent.h"
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const char* FileName = "FileStudent.bin";
	
	const int MaxNumStudent = 5;
	CStudent Student[MaxNumStudent];

	int IndStudent;
	cout << "������� ���������� ���������: ";
	cin >> IndStudent;

	for (int i = 0; i < IndStudent; ++i)
	{
		cout << "\n������� " << i + 1 << ":" << endl;
		Student[i].FillFromKeyboard();
		Student[i].SaveToBinFile(FileName);
	}

	for (int i = 0; i < IndStudent; ++i)
	{
		cout << "\n\n==================== ������� " << i + 1 << " ====================" << endl;
		Student[i].Print();
		cout << "===================================================";
	}

	int SelectedCourse;
	cout << "\n�������� ����������� ����: ";
	cin >> SelectedCourse;

	int SelectedSubject;
	cout << "\n1 - ����������\n2 - ������\n3 - ����������������";
	do
	{
		cout << "\n�������� �������: ";
		cin >> SelectedSubject;
		if (SelectedSubject < 1 || SelectedSubject > 3)
		{
			cout << "������� ������������ �����";
			continue;
		}
	} while (SelectedSubject < 1 || SelectedSubject > 3);

	int CountStudent = CStudent::FindNumberOfExcellentStudents(Student, IndStudent, SelectedCourse, SelectedSubject);

	if (SelectedSubject == 1)
		cout << "\n���������� ���������� �� ���������� �� " << SelectedCourse << " �����: " << CountStudent;
	else if (SelectedSubject == 2)
		cout << "\n���������� ���������� �� ������ �� " << SelectedCourse << " �����: " << CountStudent;
	else if (SelectedSubject == 3)
		cout << "\n���������� ���������� �� ���������������� �� " << SelectedCourse << " �����: " << CountStudent;
	cout << "\n===================================================";

	cout << "\n\n\n\n\n============ ����������� ��� ���������� ===========";
	CStudent Student1;
	cout << "\n���������� � Sudent 1:\n";
	Student1.Print();
	cout << "===================================================";

	cout << "\n\n============ ���������� � ����������� =============";
	CStudent Student2("Pavel Kuzich", 18, 1, 1, 10, 10, 10);
	cout << "\n���������� � Student 2:\n";
	Student2.Print();
	cout << "===================================================";

	cout << "\n\n============= ����������� ����������� =============";
	CStudent Student3 = Student2;
	cout << "\n���������� � Student 3:\n";
	Student3.Print();
	cout << "===================================================";

	cout << "\n\n============= ����������� ����������� =============";
	CStudent Student4 = move(Student2);
	cout << "\n���������� � Student 4:\n";
	Student4.Print();
	cout << "--------------------\n";
	cout << "�������� �� ��������:\n";
	Student2.Print();
	cout << "===================================================\n";

	return 0;
}