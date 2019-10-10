/*
�������� ������ Vector � Matrix ��� �������� � ��������� ���������� �
��������� ��������, ��������������. ����������� ������� 2 ������������ ������ �1
� ������� ��������� �������. ��� ������� �������� � ���� ������� �������.
� ���� �������� ���������:

-- ��������� � ������������ ������������ ������ ����������� � ������������� �
������������ �������, ��������������.

-- � ������ Vector ����������� �������� ���������� []. � ������ Matrix ��������
������ T at(int i, int j) const � setAt(int i, int j, T val), �������

��������� �������� � ���������� �������� �������� ������� � �������� [i][j], T �
��� ��� ��������� ������� �� �������� (int ��� double).

-- ����������� ��������� ���������� � ���������� (��� �����������, ��� �
������������). ����� ���������� / ���������� ����� ������� ����������� �
���������� / ���������� ������� �������� �������.
*/
#include <iostream>
#include <Windows.h>
#include "Mattrix.h"
#include "Vektor.h"

using namespace std;

int main(){
	// ������� ����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Ni;
	int Nj;

	cout << "������� ������ �������" << endl;

	cout << "���-�� �����: ";
	cin >> Ni;
	cout << endl;

	cout << "������ ���-�� ��������: ";
	cin >> Nj;
	cout << endl;

	while (Ni <= 0 || Nj <= 0)
	{
		system("cls");
		cout << "������� ������ �������" << endl;

		cout << "���-�� �����: ";
		cin >> Ni;
		cout << endl;

		cout << "������ ���-�� ��������: ";
		cin >> Nj;
		cout << endl;
	}

	// ������ � ������� Mattrix
#pragma region Mattrix
	// ������ � ���������� ������ ���������� ������� 
	
	

	// ����� ��� ������
	int value;
	int NewNi;
	int NewNj;

	// ����� ������������
	Mattrix MyMattrix(Ni, Nj);

	// �������� �������
	MyMattrix.Initial_Array();

	// ����� �� �����
	MyMattrix.PrintArray();

	cout << endl;

	// ������ ����� �������� ��� ������
	cout << "����� ��������: ";
	cin >> value;
	cout << endl;

	cout << "C�����: ";
	cin >> NewNi;
	cout << endl;

	cout << "�������: ";
	cin >> NewNj;
	cout << endl;
	// ������ ��������(��������, ������, �������)
	MyMattrix.Set_Value(value, NewNi, NewNj);

	// ����� �� �����
	MyMattrix.PrintArray();
	cout << endl;


	// �������� ����� ��������
	cout << "������� ���������� ��������� ��������" << endl;

	cout << "C�����: ";
	cin >> NewNi;
	cout << endl;

	cout << "�������: ";
	cin >> NewNj;
	cout << endl;

	double Get_IJ = MyMattrix.Get_Value(NewNi, NewNj);
	cout << "��������: " << Get_IJ << endl;
	// ������� ������

	cout << "��������� 1" << endl;

	MyMattrix.operator++();
	MyMattrix.PrintArray();


	cout << "��������� 2" << endl;

	MyMattrix.operator++(1);
	MyMattrix.PrintArray();

	cout << "��������� 1" << endl;

	MyMattrix.operator--();
	MyMattrix.PrintArray();


	cout << "��������� 2" << endl;

	MyMattrix.operator--(1);
	MyMattrix.PrintArray();
	//MyMattrix.~Mattrix();

#pragma endregion

	// ������ � ������� Vektor
#pragma region Vektor
	Vektor MyVector(Ni, Nj);

	MyVector.Initial_Array(Ni, Nj);

	MyVector.PrintArray();

	double Pos = MyVector.operator[](3);
	cout << endl << "���� �����: " << Pos << endl << endl;

	cout << "��������� 1" << endl;
	MyVector.operator++();
	MyVector.PrintArray();
	cout << endl;

	cout << "��������� 2" << endl;
	MyVector.operator++(1);
	MyVector.PrintArray();
	cout << endl;

	cout << "��������� 1" << endl;
	MyVector.operator--();
	MyVector.PrintArray();
	cout << endl;
	
	cout << "��������� 1" << endl;
	MyVector.operator--(1);
	MyVector.PrintArray();
	cout << endl;
	//MyVector.~Vektor();
#pragma endregion

	system("pause");
} // main