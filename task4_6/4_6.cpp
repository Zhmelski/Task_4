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
	cout << "\n��������� ��� ����� ������:";
	CVector vOperator;
	cout << "\n������� ����������� �������: ";
	int SizeVec;
	cin >> SizeVec;
	vOperator.SetSize(SizeVec);
	cout << "\n������� " << SizeVec << " ��������� �������: ";
	cin >> vOperator;
	cout << vOperator;*/
	
	
	PrintSign();
	cout << "\n���������� ��� ����������� ������� �������:";
	CVector vOperator;
	cout << "\n������� ����������� �������: ";
	int SizeVec;
	cin >> SizeVec;
	vOperator.SetSize(SizeVec);
	cout << "\n������� " << SizeVec << " ��������� �������: ";
	cin >> vOperator;
	cout << vOperator;
	PrintSign();


	return 0;
}