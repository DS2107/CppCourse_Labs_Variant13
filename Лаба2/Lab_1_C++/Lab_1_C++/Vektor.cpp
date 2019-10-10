#include "Vektor.h"
#include <iomanip>
#include <iostream>

using namespace std;

Vektor::Vektor(){

} // Vektor

Vektor::Vektor(int Ni, int Nj){
	this->Ni = Ni;
	this->Nj = Nj;
	 Array1d = new double[Ni*Nj];
} // Vektor

void Vektor::Initial_Array(size_t Ni, size_t Nj){

	double ** Array2D = new double*[Ni];
	// ѕоместить указатель в массив, который будет указывать на другой одномерный массив 
	// √де буду хранить уже реальные данные
	for (int i = 0; i < Ni; i++) {

		// ¬ каждый элемент, который хранить указатель на int ,
		// присваеваем новый динамический массив 
		*(Array2D + i) = new double[Nj];
	}

	// «аполн€ем  значени€ми
	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			*(*(Array2D + i) + j) = sqrt(i + j + 1);
		}
	}


	// —оздаем 1D
	int k = 0;
	for (int i = 0; i < Ni; i++)
	{
		for (int j = Nj - 1; j >= 0; j--)
		{

			Array1d[k] = *(*(Array2D + i) + j);
			k++;
		}
	}

	// „истим двумерный массив
	// Ѕежим по нашему начальному массиву , который хранит указатели
	// и дл€ каждого указател€ вызываем оператор Delete
	for (int i = 0; i < Ni; i++)
	{
		delete[] Array2D[i];
	}

	delete[] Array2D;
	
} // Initial_Array

void Vektor::PrintArray(){
	int size = Ni * Nj;
	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(5) << *(Array1d + i) << ", ";
	}
	cout << "}";
} // PrintArray

double & Vektor::operator[](int pos){
	int Size = Ni * Nj;
	if (pos-1 >= 0 && pos-1 < Size)
	{
		return Array1d[pos-1];
	}
	return Array1d[0];
	
} // operator

double & Vektor::operator++(){
	int size = Ni * Nj;
	
	for (int i = 0; i < size; i++)
	{
		Array1d[i] = Array1d[i]++;
	}

	return *Array1d;
} // operator++

double & Vektor::operator++(int m){
	int size = Ni * Nj;

	for (int i = 0; i < size; i++)
	{
		Array1d[i] = ++Array1d[i];
	}

	return *Array1d;
} // operator++

double & Vektor::operator--(){
	
	int size = Ni * Nj;

	for (int i = 0; i < size; i++)
	{
		Array1d[i] = Array1d[i]--;
	}

	return *Array1d;
} // operator--

double & Vektor::operator--(int m){
	int size = Ni * Nj;

	for (int i = 0; i < size; i++)
	{
		Array1d[i] = --Array1d[i];
	}

	return *Array1d;
	
} // operator--

Vektor::~Vektor(){

	delete[] Array1d;
} // ~Vektor
