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

	PrintSign();
	int NewSize;
	cout << "\nВведите размерность вектора: ";
	cin >> NewSize;
	CVector vMain;
	vMain.SetSize(NewSize);
	cout << "\nВектор размерности " << NewSize << ":";
	vMain.PrintElVec();
	
	PrintSign();
	int VecSize = vMain.GetSize();
	cout << "\nРазмерность вектора равна " << VecSize << endl;
	
	PrintSign();
	int Ind;
	cout << "\nВведите индекс желаемого элемента: ";
	cin >> Ind;
	int ValueInd = vMain.GetIndElement(Ind);
	cout << "\nЭлемент под индексом " << Ind << ": " << ValueInd << endl;

	PrintSign();
	CVector vMain_Insert = vMain;
	int EnterInd, Value;
	cout << "\nВведите индекс элемента для вставки: ";
	cin >> EnterInd;
	cout << "Введите элемент для вставки: ";
	cin >> Value;
	cout << "\nИтоговый вектор:";
	vMain_Insert.EnterValue(EnterInd, Value);	
	vMain_Insert.PrintElVec();

	PrintSign();
	CVector vMain_1 = vMain, vMain_2 = vMain, vMain_3 = vMain, vMain_4 = vMain;
	int Scalar;
	cout << "\nВведите скаляр для выполнения мат. операций: ";
	cin >> Scalar;
	cout << "\nРезультат сложения:";
	vMain_1.AdditionScalar(Scalar);
	vMain_1.PrintElVec();
	cout << "\nРезультат вычитания:";
	vMain_2.SubtractScalar(Scalar);
	vMain_2.PrintElVec();
	cout << "\nРезультат умножения:";
	vMain_3.MultiplicationScalar(Scalar);
	vMain_3.PrintElVec();
	cout << "\nРезультат деления:";
	vMain_4.DivisionScalar(Scalar);
	vMain_4.PrintElVec();

	PrintSign();
	double VecLen = vMain.DetLengthVec();
	cout << "\nДлина вектора равна: " << VecLen << endl;

	PrintSign();
	cout << "\nСтарый вектор:";
	vMain.PrintElVec();
	CVector New_vMain(10, 10);
	cout << "Новый вектор:";
	New_vMain.PrintElVec();
	CVector New_vMain_1 = New_vMain, New_vMain_2 = New_vMain, New_vMain_3 = New_vMain, New_vMain_4 = New_vMain;
	cout << "\nРезультат сложения векторов:";
	New_vMain_1.AdditionVectors(vMain);
	New_vMain_1.PrintElVec();
	cout << "\nРезультат вычитания векторов:";
	New_vMain_2.SubtractVectors(vMain);
	New_vMain_2.PrintElVec();
	cout << "\nРезультат умножения векторов:";
	New_vMain_3.MultiplicationVectors(vMain);
	New_vMain_3.PrintElVec();
	cout << "\nРезультат деления векторов:";
	New_vMain_4.DivisionVectors(vMain);
	New_vMain_4.PrintElVec();

	PrintSign();
	CVector vRand;
	cout << "\nВвектор с рандомными элементами от 0 до 10:";
	vRand.FillElRand();
	vRand.PrintElVec();
	PrintSign();
	
	cout << "\nВектор:";
	vRand.PrintElVec();
	CVector Z;
	Z.MainFunction(vRand);
	cout << "\nНовый вектор Z с элементами Zi = Xi + max:";
	Z.PrintElVec();
	PrintSign();

	return 0;
}