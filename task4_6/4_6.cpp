#include "CVector.h"
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Конструктор БЕЗ параметров:";
	CVector v1;
	v1.PrintElVec();

	cout << "\nКонструктор С параметрами:";
	CVector v2(5, 5);
	v2.PrintElVec();

	cout << "\nКонструктор копирования:";
	CVector v3 = v2;
	v3.PrintElVec();

	cout << "\nКонструктор перемещения:";
	CVector v4 = move(v2);
	v4.PrintElVec();
	cout << "\nПроверка на удаление:";
	v2.PrintElVec();

	/*PrintSign();
	cout << "\nПрегрузка как метод класса:";
	CVector vOperator;
	cout << "\nВведите размерность вектора: ";
	int SizeVec;
	cin >> SizeVec;
	vOperator.SetSize(SizeVec);
	cout << "\nВведите " << SizeVec << " элементов вектора: ";
	cin >> vOperator;
	cout << vOperator;*/
	
	
	PrintSign();
	cout << "\nПерегрузка как независимая внешняя функция:";
	CVector vOperator;
	cout << "\nВведите размерность вектора: ";
	int SizeVec;
	cin >> SizeVec;
	vOperator.SetSize(SizeVec);
	cout << "\nВведите " << SizeVec << " элементов вектора: ";
	cin >> vOperator;
	cout << vOperator;
	PrintSign();


	return 0;
}