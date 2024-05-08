#include "CVector.h"

void PrintSign()
{
	cout << "\n================================================================================\n";
}

CVector::CVector()
{
	Size = 10;
	for (int i = 0; i < Size; ++i)
		Elements[i] = i + 1;
}

CVector::CVector(int size, double value)
{
	Size = size;
	for (int i = 0; i < Size; ++i)
		Elements[i] = value;
}

CVector::CVector(const CVector& Another)
{
	Size = Another.Size;
	for (int i = 0; i < Size; ++i)
		Elements[i] = Another.Elements[i];
}

CVector::CVector(CVector&& Another)
{
	Size = Another.Size;
	for (int i = 0; i < Size; ++i)
		Elements[i] = Another.Elements[i];

	Another.Size = 0;
	for (int i = 0; i < Size; ++i)
	{
		Another.Elements[i] = 0;
	}
}

CVector::~CVector()
{
	cout << "\nDestructor CVector done";
}

void CVector::SetSize(int NewSize)
{
	Size = NewSize;
}

int CVector::GetSize() const
{
	return Size;
}

double CVector::GetIndElement(int Ind) const
{
	if (Ind < 0 || Ind >= Size)
	{
		do
		{
			cout << "Введен некорректный индекс\nВведите индекс: ";
			cin >> Ind;
		} while (Ind < 0 || Ind >= Size);
	}
	return Elements[Ind];
}

void CVector::EnterValue(int EnterInd, double Value)
{
	if (EnterInd < 0 || EnterInd >= Size)
	{
		do
		{
			cout << "Введен некорректный индекс\nВведите индекс: ";
			cin >> EnterInd;
		} while (EnterInd < 0 || EnterInd >= Size);
	}
	Elements[EnterInd] = Value;
}

void CVector::AdditionScalar(int Scalar)
{
	for (int i = 0; i < Size; ++i)
	{
		Elements[i] += Scalar;
	}
}

void CVector::SubtractScalar(int Scalar)
{
	for (int i = 0; i < Size; ++i)
	{
		Elements[i] -= Scalar;
	}
}

void CVector::MultiplicationScalar(int Scalar)
{
	for (int i = 0; i < Size; ++i)
	{
		Elements[i] *= Scalar;
	}
}

void CVector::DivisionScalar(int Scalar)
{
	if (Scalar == 0)
	{
		do
		{
			cout << "Деление на ноль запрещено!\nВведите новое число: ";
			cin >> Scalar;
		} while (Scalar == 0);
	}

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] /= Scalar;
	}
}

double CVector::DetLengthVec() const
{
	double sum = 0;
	for (int i = 0; i < Size; ++i)
	{
		sum += Elements[i] * Elements[i];
	}
	return sqrt(sum);
}

void CVector::AdditionVectors(const CVector& Another)
{
	if (Size != Another.Size)
	{
		cout << "Размерности векторов не равны, операция невозможна\n";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] += Another.Elements[i];
	}
}

void CVector::SubtractVectors(const CVector& Another)
{
	if (Size != Another.Size)
	{
		cout << "Размерности векторов не равны, операция невозможна\n";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] -= Another.Elements[i];
	}
}

void CVector::MultiplicationVectors(const CVector& Another)
{
	if (Size != Another.Size)
	{
		cout << "Размерности векторов не равны, операция невозможна\n";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] *= Another.Elements[i];
	}
}

void CVector::DivisionVectors(const CVector& Another)
{
	if (Size != Another.Size)
	{
		cout << "Размерности векторов не равны, операция невозможна\n";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		if (Another.Elements[i] == 0)
		{
			cout << "Элемент с индексом " << i + 1 << " = 0. Деление на ноль запрещено!";
			return;
		}
		Elements[i] /= Another.Elements[i];
	}
}

void CVector::PrintElVec() const
{
	cout << endl;
	for (int i = 0; i < Size; ++i)
	{
		cout << Elements[i] << "   ";
	}
	cout << endl;
}

void CVector::InputElFromKeyboard()
{
	cout << "\nВведите " << Size << " элементов:\n";
	for (int i = 0; i < Size; ++i)
	{
		cin >> Elements[i];
	}
}

void CVector::FillElRand()
{
	srand(time(nullptr));
	for (int i = 0; i < Size; ++i)
	{
		Elements[i] = rand() % 10;
	}
}

double CVector::FindAverageElements()
{
	double AverageValue = 0;
	for (int i = 0; i < Size; ++i)
	{
		AverageValue += Elements[i];
	}
	return AverageValue / Size;
}

double CVector::FindMaxDeviation(double AverageValue)
{
	double max = abs(Elements[0] - AverageValue);
	for (int i = 1; i < Size; ++i)
	{
		if (abs(Elements[i] - AverageValue) > max)
			max = abs(Elements[i] - AverageValue);
	}

	return max;
}

void CVector::GetNewVector(double max, const CVector& Another)
{
	for (int i = 0; i < Size; ++i)
	{
		Elements[i] = Another.Elements[i] + max;
	}
}

void CVector::MainFunction(const CVector& Another)
{
	double AverageValue;
	double sum = 0;

	for (int i = 0; i < Size; ++i)
		sum += Another.Elements[i];

	AverageValue = sum / Size;
	cout << "\nСреднее значение элементов вектора: " << AverageValue;

	double max = abs(Another.Elements[0] - AverageValue);
	for (int i = 0; i < Size; ++i)
	{
		if (abs(Elements[i] - AverageValue) > max)
			max = abs(Elements[i] - AverageValue);
	}
	cout << "\nМаксимальное отклонение значений от среднего значения: " << max;

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] = Another.Elements[i] + max;
	}
}

istream& operator>>(istream& Input, CVector& vOperator)
{
	for (int i = 0; i < vOperator.GetSize(); ++i)
	{
		double value;
		Input >> value;
		vOperator.EnterValue(i, value);
	}
	return Input;
}

ostream& operator<<(ostream& Output, CVector& vOperator)
{
	Output << "Вектор: ";
	for (int i = 0; i < vOperator.GetSize(); ++i)
	{
		Output << vOperator.GetIndElement(i) << " ";
	}
	return Output;
}