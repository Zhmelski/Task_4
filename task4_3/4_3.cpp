#include "CStudent.h"
#include "CStudentDB.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MaxNameStud = 100;
	char FileName[] = "Students.bin";

	CStudent student1("Pasha Kuzich", 18, 1, 1, 10, 10, 10);
	CStudent student2("Andrey Dubrovski", 20, 3, 1, 9, 8, 10);
	CStudent student3("Masha Evolskaya", 19, 1, 0, 10, 10, 10);

	CStudent ArrayStudents[] = { student1, student2, student3 };
	
	CStudentDataBase DataBase(ArrayStudents, 3, FileName);
	DataBase.PrintDataBase();

	DataBase.AddStudentFromKeyboard();	
	DataBase.SaveDataBaseToBinFile(FileName);
	DataBase.LoadDataBaseFromBinFile(FileName);
	cout << "\n\n************************************************************\n\n";
	DataBase.PrintDataBase();

	cout << "\n\nÂâåäèòå èìÿ ñòóäåíòà äëÿ ïîèñêà: ";
	char NameStudent[MaxNameStud];
	ClearCache(MaxNameStud);
	cin.getline(NameStudent, MaxNameStud);

	/*CStudent* FoundStudent = DataBase.FindStudentDataBase(NameStudent);
	if (FoundStudent != nullptr)
	{
		cout << "\n\nÑòóäåíò(û) ñ èìåíåì " << NameStudent << ":\n";
		for (int i = 0; i < DataBase.GetSize(); ++i)
		{
			cout << "\n========================================\n";
			FoundStudent[i].Print();
			cout << "========================================\n";
		}
		delete[] FoundStudent;
	}
	else
		cout << "Ñòóäåíò(û) ñ èìåíåì " << NameStudent << " íå íàéäåí(û).\n";*/

	const int maxFoundStudents = 100;
	CStudent FoundStudens[maxFoundStudents];
	int foundCount = DataBase.FindStudentDataBase(NameStudent, FoundStudens, maxFoundStudents);

	if (foundCount > 0)
	{
		cout << "\n\nÑòóäåíò(û) ñ èìåíåì " << NameStudent << ":\n";
		for (int i = 0; i < foundCount; ++i)
		{
			cout << "\n----------------------------------------\n";
			FoundStudens[i].Print();
			cout << "----------------------------------------\n";
		}
	}
	else
		cout << "Ñòóäåíò ñ èìåíåì " << NameStudent << " íå íàéäåí.\n";

	unsigned short SelectedCourse;
	do
	{
		cout << "\n\nÂâåäèòå ïðîâåðÿåìûé êóðñ: ";
		cin >> SelectedCourse;
		if (SelectedCourse < 1 || SelectedCourse > 6)
			cout << "Ââåäåíî íåêêîðåêòíîå ÷èñëî";
	} while (SelectedCourse < 1 || SelectedCourse > 6);

	cout << "\n\n1 - Ìàòåìàòèêà\n2 - Ôèçèêà\n3 - Ïðîãðàììèðîâàíèå\n";
	unsigned short SelectedSubject;
	do
	{
		cout << "Âûáåðèòå ïðåäìåò: ";
		cin >> SelectedSubject;
		if (SelectedSubject < 1 || SelectedSubject > 3)
			cout << "Ââåäåíî íåêêîðåêòíîå ÷èñëî";
	} while (SelectedSubject < 1 || SelectedSubject > 3);

	int AmountEx = DataBase.FindCountOfExcellentStudents(SelectedCourse, SelectedSubject);
	
	if (SelectedSubject == 1)
		cout << "\nÊîëè÷åñòâî îòëè÷íèêîâ ïî ÌÀÒÅÌÀÒÈÊÅ íà " << SelectedCourse << " êóðñå: " << AmountEx;
	else if (SelectedSubject == 2)
		cout << "\nÊîëè÷åñòâî îòëè÷íèêîâ ïî ÔÈÇÈÊÅ íà " << SelectedCourse << " êóðñå: " << AmountEx;
	else if (SelectedSubject == 3)
		cout << "\nÊîëè÷åñòâî îòëè÷íèêîâ ïî ÏÐÎÃÐÀÌÌÈÐÎÂÀÍÈÞ íà " << SelectedCourse << " êóðñå: " << AmountEx;

	return 0;
}
