#include <iostream>
#include <iomanip>
#include "Mattrix.h"

using namespace std;

Mattrix::Mattrix(){

} // Mattrix

// ��������� ������
Mattrix::Mattrix(size_t Ni,size_t Nj) {
	// �������� ������� ������� ������� ��������� �� ��������� �������
	// ������ ����������
	 Array2D = new double*[Ni];
	 this->Ni = Ni;
	 this->Nj = Nj;
} // Mattrix


// �������� �������
void  Mattrix::Initial_Array(){

	// ��������� ��������� � ������, ������� ����� ��������� �� ������ ���������� ������ 
	// ��� ���� ������� ��� �������� ������
	for (int i = 0; i < Ni; i++) {

		// � ������ �������, ������� ������� ��������� �� int ,
		// ����������� ����� ������������ ������ 
		*(Array2D + i) = new double[Nj];
	}

	// ���������  ����������
	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			*(*(Array2D + i) + j) = sqrt(i + j + 1);
		}
	}

} // Initial_Array

void Mattrix::Set_Value(int value, int posI, int posJ){
	// ��������� �������� �������� �� ������� �������
	if (posI-1 >= 0 && posI-1 < Ni && posJ-1 >= 0 && posJ-1 < Nj)	
		Array2D[posI-1][posJ-1] = value;
	
} // Set_Value

double Mattrix::Get_Value(int posX, int posY){
	// ��������� �������� �������� �� ������� �������
	if (posX-1 >= 0 && posX-1 < Ni && posY-1 >= 0 && posY-1 < Nj)
		return Array2D[posX - 1][posY - 1];
	else
		return 0.0;
} // Get_Value

void Mattrix::PrintArray(){
	// � ������� ����� �������� �� 2D ������� � ������� �� �����

	for (int i = 0; i < Ni; i++) {

		for (int j = 0; j < Nj; j++) {

			cout << setprecision(3) << *(*(Array2D + i) + j) << "\t";
		}
		cout << endl;
	}
} // PrintArray

double & Mattrix::operator++(){

	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			Array2D[i][j] = Array2D[i][j]++;
		}
	}
	return **Array2D;
} // operator++

double & Mattrix::operator++(int m){
	
	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			Array2D[i][j] = ++Array2D[i][j];
		}
	}
	return **Array2D;
} // operator++

double & Mattrix::operator--(){

	
	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			Array2D[i][j] = Array2D[i][j]--;
		}
	}
	return **Array2D;
} // operator--

double & Mattrix::operator--(int m){

	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			Array2D[i][j] = --Array2D[i][j];
		}
	}
	return **Array2D;
} // operator--


// ������������ ������
Mattrix::~Mattrix() {
	// ����� �� ������ ���������� ������� , ������� ������ ���������
	// � ��� ������� ��������� �������� �������� Delete
	for (int i = 0; i < Ni; i++)
	{
		delete[] Array2D[i];
	}

	delete[] Array2D;
	
} // `Mattrix

