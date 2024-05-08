#include "CVector.h"
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "����������� ��� ����������:";
	CVector v1;
	v1.PrintElVec();

	cout << "\n����������� � �����������:";
	CVector v2(5, 5);
	v2.PrintElVec();

	cout << "\n����������� �����������:";
	CVector v3 = v2;
	v3.PrintElVec();

	cout << "\n����������� �����������:";
	CVector v4 = move(v2);
	v4.PrintElVec();
	cout << "\n�������� �� ��������:";
	v2.PrintElVec();

	/*PrintSign();
	cout << "\n���������� ��������� ��� ����� ������:\n";
	CVector vOperator_1(4, 4), vOperator_2(4, 5);
	cout << "\n������ ������:";
	vOperator_1.PrintElVec();
	cout << "\n������ ������:";
	vOperator_2.PrintElVec();
	cout << "\n��������� ������������ ��������:";
	CVector vOperator = vOperator_1 * vOperator_2;
	vOperator.PrintElVec();
	PrintSign();*/

	PrintSign();
	cout << "\n���������� ��������� ��� ����������� ������� �������:\n";
	CVector vOperator_3(4, 6), vOperator_4(4, 7);
	cout << "\n������ ������:";
	vOperator_3.PrintElVec();
	cout << "\n������ ������:";
	vOperator_4.PrintElVec();
	CVector vOp = vOperator_3 * vOperator_4;
	cout << "\n��������� ������������ ��������:";
	vOp.PrintElVec();
	PrintSign();

	return 0;
}