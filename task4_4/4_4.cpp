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

	PrintSign();
	int NewSize;
	cout << "\n������� ����������� �������: ";
	cin >> NewSize;
	CVector vMain;
	vMain.SetSize(NewSize);
	cout << "\n������ ����������� " << NewSize << ":";
	vMain.PrintElVec();
	
	PrintSign();
	int VecSize = vMain.GetSize();
	cout << "\n����������� ������� ����� " << VecSize << endl;
	
	PrintSign();
	int Ind;
	cout << "\n������� ������ ��������� ��������: ";
	cin >> Ind;
	int ValueInd = vMain.GetIndElement(Ind);
	cout << "\n������� ��� �������� " << Ind << ": " << ValueInd << endl;

	PrintSign();
	CVector vMain_Insert = vMain;
	int EnterInd, Value;
	cout << "\n������� ������ �������� ��� �������: ";
	cin >> EnterInd;
	cout << "������� ������� ��� �������: ";
	cin >> Value;
	cout << "\n�������� ������:";
	vMain_Insert.EnterValue(EnterInd, Value);	
	vMain_Insert.PrintElVec();

	PrintSign();
	CVector vMain_1 = vMain, vMain_2 = vMain, vMain_3 = vMain, vMain_4 = vMain;
	int Scalar;
	cout << "\n������� ������ ��� ���������� ���. ��������: ";
	cin >> Scalar;
	cout << "\n��������� ��������:";
	vMain_1.AdditionScalar(Scalar);
	vMain_1.PrintElVec();
	cout << "\n��������� ���������:";
	vMain_2.SubtractScalar(Scalar);
	vMain_2.PrintElVec();
	cout << "\n��������� ���������:";
	vMain_3.MultiplicationScalar(Scalar);
	vMain_3.PrintElVec();
	cout << "\n��������� �������:";
	vMain_4.DivisionScalar(Scalar);
	vMain_4.PrintElVec();

	PrintSign();
	double VecLen = vMain.DetLengthVec();
	cout << "\n����� ������� �����: " << VecLen << endl;

	PrintSign();
	cout << "\n������ ������:";
	vMain.PrintElVec();
	CVector New_vMain(10, 10);
	cout << "����� ������:";
	New_vMain.PrintElVec();
	CVector New_vMain_1 = New_vMain, New_vMain_2 = New_vMain, New_vMain_3 = New_vMain, New_vMain_4 = New_vMain;
	cout << "\n��������� �������� ��������:";
	New_vMain_1.AdditionVectors(vMain);
	New_vMain_1.PrintElVec();
	cout << "\n��������� ��������� ��������:";
	New_vMain_2.SubtractVectors(vMain);
	New_vMain_2.PrintElVec();
	cout << "\n��������� ��������� ��������:";
	New_vMain_3.MultiplicationVectors(vMain);
	New_vMain_3.PrintElVec();
	cout << "\n��������� ������� ��������:";
	New_vMain_4.DivisionVectors(vMain);
	New_vMain_4.PrintElVec();

	PrintSign();
	CVector vRand;
	cout << "\n������� � ���������� ���������� �� 0 �� 10:";
	vRand.FillElRand();
	vRand.PrintElVec();
	PrintSign();
	
	cout << "\n������:";
	vRand.PrintElVec();
	CVector Z;
	Z.MainFunction(vRand);
	cout << "\n����� ������ Z � ���������� Zi = Xi + max:";
	Z.PrintElVec();
	PrintSign();

	return 0;
}