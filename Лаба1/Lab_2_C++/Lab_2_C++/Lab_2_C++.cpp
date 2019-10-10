/*
Преобразование: 2D → 1D. Двумерный массив 4х4 вещественных чисел необходимо
выложить в один ряд по элементам справа налево и сверху вниз.
Инициализация: заполнить массив числами x[i][j] = √(i+j+1).
Вывод на экран: каждый элемент одномерного массива вывести с точностью 4 знака
после запятой; каждый элемент двумерного массива – с точностью 2 знака.
[ 1		1.41	1.73	2
1.41	1.73	2		2.24
1.73	2		2.24	2.45
2		2.24	2.45	2.65 ]
=>
[ 2 1.7321 1.4142 1 2.2361 2 1.7321 1.4142 2.4495 2.2361 2 1.7321 2.6458
2.4495 2.2361 2 ]
*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Создание 2D массива
double** Initial_Array(double ** Array2d, const size_t Ni, const size_t Nj);

// Создание 1D массива
double* Initial_Array(double *Array1d, double ** Array2d, const size_t Ni, const size_t Nj);

// Вывод 2D массива
void PrintArray(double ** Array2d, const size_t Ni, const size_t Nj);

// Вывод 1D массива
void PrintArray(double * Array1D, int size);

// Очистка памяти 
void Clear(double *Array1D, double ** Array2d, const size_t Ni);

int main(){

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Строки 
	const size_t Ni = 4;

	// Колонки
	const size_t Nj = 4;

	// Размер одномерного массива
	int Size1D = Ni * Nj;

	// Создание массива который хранить указатели на отсальные массивы
	// Массив Указателей
	double ** Array2d = new double*[Ni];

	// Динамически создаем Одномерный массив
	double* Array1d = new double[Ni*Nj];

	// Вызов функции, которая создает 2 мерный массив
	Array2d = Initial_Array(Array2d, Ni, Nj);
	
	// Вывод двумерного массива на экран
	PrintArray(Array2d, Ni, Nj);
	
	// Вызов функции, которая создает 1  мерный массив из 2D
	Array1d = Initial_Array(Array1d,Array2d, Ni, Nj);

	// Вывод 1 массива на экран
	PrintArray(Array1d, Size1D);

	// Очистка памяти
	Clear(Array1d, Array2d, Ni);

	cout << endl;

	system("pause");
	
} // main

double** Initial_Array(double ** Array2d, const size_t Ni, const size_t Nj){

	// Поместить указатель в массив, который будет указывать на другой одномерный массив 
	// Где буду хранить уже реальные данные
	for (int  i = 0; i < Ni; i++) {

		// В каждый элемент, который хранить указатель на int ,
		// присваеваем новый динамический массив 
		*(Array2d + i) = new double[Nj];
	}
	
	// Заполняем  значениями
	for (int i = 0; i < Ni; i++)
	{
		for (int j = 0; j < Nj; j++)
		{
			*(*(Array2d + i) + j) = sqrt(i + j + 1);
		}
	}
	// Возвращаем указатель на массив
	return Array2d;

} // Initial_Array

void PrintArray(double ** Array2d, const size_t Ni, const size_t Nj){
	
	// В двойном цикле проходим по 2D Массиву и выводим на экран
	
	for (int i = 0; i < Ni; i++) {

		for (int j = 0; j < Nj; j++) {

			cout << setprecision(3)<< *(*(Array2d + i) + j) <<"\t";
		}
		cout << endl;
	}
	

} // PrintArray

void PrintArray(double * Array1D, int size){

	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		cout << setprecision(5) << *(Array1D+i)<<", ";
	}
	cout << "}";


} // PrintArray

void Clear(double * Array1D, double ** Array2D, const size_t Ni) {

	// Бежим по нашему начальному массиву , который хранит указатели
	// и для каждого указателя вызываем оператор Delete
	for (int i = 0; i < Ni; i++)
	{
		delete[] *(Array2D + i);
	} 

	delete[] Array2D;
	delete[] Array1D;
} // Clear

double * Initial_Array(double *Array1D, double ** Array2d, const size_t Ni, const size_t Nj){
	cout << endl;
	int k = 0;
	for (int i = 0; i < Ni; i++)
	{
		for (int j = Nj-1; j >= 0; j--)
		{

			Array1D[k] = *(*(Array2d + i) + j);
			k++;
		}
	}
	return Array1D;
} // Initial_Array_1D
