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
			cout << "������ ������������ ������\n������� ������: ";
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
			cout << "������ ������������ ������\n������� ������: ";
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
			cout << "������� �� ���� ���������!\n������� ����� �����: ";
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
		cout << "����������� �������� �� �����, �������� ����������\n";
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
		cout << "����������� �������� �� �����, �������� ����������\n";
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
		cout << "����������� �������� �� �����, �������� ����������\n";
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
		cout << "����������� �������� �� �����, �������� ����������\n";
		return;
	}

	for (int i = 0; i < Size; ++i)
	{
		if (Another.Elements[i] == 0)
		{
			cout << "������� � �������� " << i + 1 << " = 0. ������� �� ���� ���������!";
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
	cout << "\n������� " << Size << " ���������:\n";
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

void CVector::MainFunction(const CVector& Another)
{
	double AverageValue;
	double sum = 0;

	for (int i = 0; i < Size; ++i)
		sum += Another.Elements[i];

	AverageValue = sum / Size;
	cout << "\n������� �������� ��������� �������: " << AverageValue;

	double max = abs(Another.Elements[0] - AverageValue);
	for (int i = 0; i < Size; ++i)
	{
		if (abs(Elements[i] - AverageValue) > max)
			max = abs(Elements[i] - AverageValue);
	}
	cout << "\n������������ ���������� �������� �� �������� ��������: " << max;

	for (int i = 0; i < Size; ++i)
	{
		Elements[i] = Another.Elements[i] + max;
	}
}

//CVector CVector::operator*(const CVector& Another) const
//{
//	if (Size != Another.Size)
//	{
//		cout << "\n����������� �������� �� �����, ������� ����������\n������� ������� �������:";
//		return Another;
//	}
//
//	CVector ResVector(Size, 0);
//	for (int i = 0; i < Size; ++i)
//	{
//		ResVector.Elements[i] = Elements[i] * Another.Elements[i];
//	}
//	return ResVector;
//}

CVector operator*(const CVector& vOperator_1, const CVector& vOperator_2)
{
	if (vOperator_1.GetSize() != vOperator_2.GetSize())
	{
		cout << "\n����������� �������� �� �����, ������� ����������\n������� ������� �������:";
		return vOperator_2;
	}

	CVector ResVector;
	ResVector.SetSize(vOperator_1.GetSize());
	for (int i = 0; i < vOperator_1.GetSize(); ++i)
	{
		ResVector.EnterValue(i, vOperator_1.GetIndElement(i) * vOperator_2.GetIndElement(i));
	}
	return ResVector;
}
