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
	cout << "\nПерегрузка оператора как метод класса:\n";
	CVector vOperator_1(4, 4), vOperator_2(4, 5);
	cout << "\nПервый вектор:";
	vOperator_1.PrintElVec();
	cout << "\nВторой вектор:";
	vOperator_2.PrintElVec();
	cout << "\nРезультат перемножения векторов:";
	CVector vOperator = vOperator_1 * vOperator_2;
	vOperator.PrintElVec();
	PrintSign();*/

	PrintSign();
	cout << "\nПерегрузка оператора как независимая внешняя функция:\n";
	CVector vOperator_3(4, 6), vOperator_4(4, 7);
	cout << "\nПервый вектор:";
	vOperator_3.PrintElVec();
	cout << "\nВторой вектор:";
	vOperator_4.PrintElVec();
	CVector vOp = vOperator_3 * vOperator_4;
	cout << "\nРезультат перемножения векторов:";
	vOp.PrintElVec();
	PrintSign();

	return 0;
}