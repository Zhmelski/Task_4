#pragma once

#include <iostream>
#include <ctime>
using namespace std;

const int NMAX = 10;

void PrintSign();

class CVector
{
	double Elements[NMAX];
	int Size;

public:
	CVector();
	CVector(int size, double value);
	CVector(const CVector& Another);
	CVector(CVector&& Another);
	~CVector();

	void SetSize(int NewSize);
	int GetSize() const;

	double GetIndElement(int Ind) const;
	void EnterValue(int EnterInd, double Value);

	void AdditionScalar(int Scalar);
	void SubtractScalar(int Scalar);
	void MultiplicationScalar(int Scalar);
	void DivisionScalar(int Scalar);

	double DetLengthVec() const;

	void AdditionVectors(const CVector& Another);
	void SubtractVectors(const CVector& Another);
	void MultiplicationVectors(const CVector& Another);
	void DivisionVectors(const CVector& Another);

	void PrintElVec() const;
	void InputElFromKeyboard();
	void FillElRand();

	double FindAverageElements();
	double FindMaxDeviation(double AverageValue);
	void GetNewVector(double max, const CVector& Another);

	void MainFunction(const CVector& Another);

	/*friend istream& operator>>(istream& Input, CVector& vOperator)
	{
		for (int i = 0; i < vOperator.Size; ++i)
		{
			Input >> vOperator.Elements[i];
		}
		return Input;
	}

	friend ostream& operator<<(ostream& Output, CVector& vOperator)
	{
		Output << "Вектор: ";
		for (int i = 0; i < vOperator.Size; ++i)
		{
			Output << vOperator.Elements[i] << " ";
		}
		return Output;
	}*/
};

istream& operator>>(istream& Input, CVector& vOperator);

ostream& operator<<(ostream& Output, CVector& vOperator);