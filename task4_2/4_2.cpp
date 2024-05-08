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
	cout << "Введите количиство студентов: ";
	cin >> IndStudent;

	for (int i = 0; i < IndStudent; ++i)
	{
		cout << "\nСтудент " << i + 1 << ":" << endl;
		Student[i].FillFromKeyboard();
		Student[i].SaveToBinFile(FileName);
	}

	for (int i = 0; i < IndStudent; ++i)
	{
		cout << "\n\n==================== Студент " << i + 1 << " ====================" << endl;
		Student[i].Print();
		cout << "===================================================";
	}

	int SelectedCourse;
	cout << "\nВыберите проверяемый курс: ";
	cin >> SelectedCourse;

	int SelectedSubject;
	cout << "\n1 - математика\n2 - физика\n3 - программирование";
	do
	{
		cout << "\nВыберите предмет: ";
		cin >> SelectedSubject;
		if (SelectedSubject < 1 || SelectedSubject > 3)
		{
			cout << "Введено некорректное число";
			continue;
		}
	} while (SelectedSubject < 1 || SelectedSubject > 3);

	int CountStudent = CStudent::FindNumberOfExcellentStudents(Student, IndStudent, SelectedCourse, SelectedSubject);

	if (SelectedSubject == 1)
		cout << "\nКоличество отличников по МАТЕМАТИКЕ на " << SelectedCourse << " курсе: " << CountStudent;
	else if (SelectedSubject == 2)
		cout << "\nКоличество отличников по ФИЗИКЕ на " << SelectedCourse << " курсе: " << CountStudent;
	else if (SelectedSubject == 3)
		cout << "\nКоличество отличников по ПРОГРАММИРОВАНИЮ на " << SelectedCourse << " курсе: " << CountStudent;
	cout << "\n===================================================";

	cout << "\n\n\n\n\n============ Констурктор без параметров ===========";
	CStudent Student1;
	cout << "\nИнформация о Sudent 1:\n";
	Student1.Print();
	cout << "===================================================";

	cout << "\n\n============ Коструктор с параметрами =============";
	CStudent Student2("Pavel Kuzich", 18, 1, 1, 10, 10, 10);
	cout << "\nИнформация о Student 2:\n";
	Student2.Print();
	cout << "===================================================";

	cout << "\n\n============= Конструктор копирования =============";
	CStudent Student3 = Student2;
	cout << "\nИнформация о Student 3:\n";
	Student3.Print();
	cout << "===================================================";

	cout << "\n\n============= Конструктор перемещения =============";
	CStudent Student4 = move(Student2);
	cout << "\nИнформация о Student 4:\n";
	Student4.Print();
	cout << "--------------------\n";
	cout << "Проверка на удаление:\n";
	Student2.Print();
	cout << "===================================================\n";

	return 0;
}