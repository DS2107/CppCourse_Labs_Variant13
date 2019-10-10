/*
Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:

-- Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.

-- В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые

позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).

-- Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива.
*/
#include <iostream>
#include <Windows.h>
#include "Mattrix.h"
#include "Vektor.h"

using namespace std;

int main(){
	// Русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Ni;
	int Nj;

	cout << "Введите размер матрицы" << endl;

	cout << "Кол-во строк: ";
	cin >> Ni;
	cout << endl;

	cout << "Введие кол-во столбцов: ";
	cin >> Nj;
	cout << endl;

	while (Ni <= 0 || Nj <= 0)
	{
		system("cls");
		cout << "Введите размер матрицы" << endl;

		cout << "Кол-во строк: ";
		cin >> Ni;
		cout << endl;

		cout << "Введие кол-во столбцов: ";
		cin >> Nj;
		cout << endl;
	}

	// Работа с классом Mattrix
#pragma region Mattrix
	// вводим с клавиатуры размер двумерного массива 
	
	

	// Числа для замены
	int value;
	int NewNi;
	int NewNj;

	// Вызов конструктора
	Mattrix MyMattrix(Ni, Nj);

	// Создание Массива
	MyMattrix.Initial_Array();

	// Вывод на экран
	MyMattrix.PrintArray();

	cout << endl;

	// Задаем новое значение для ячейки
	cout << "Новое значение: ";
	cin >> value;
	cout << endl;

	cout << "Cтрока: ";
	cin >> NewNi;
	cout << endl;

	cout << "Столбец: ";
	cin >> NewNj;
	cout << endl;
	// Замена значения(Значение, строка, столбец)
	MyMattrix.Set_Value(value, NewNi, NewNj);

	// Вывод на экран
	MyMattrix.PrintArray();
	cout << endl;


	// Получаем новое значение
	cout << "Введите координаты желаемого значения" << endl;

	cout << "Cтрока: ";
	cin >> NewNi;
	cout << endl;

	cout << "Столбец: ";
	cin >> NewNj;
	cout << endl;

	double Get_IJ = MyMattrix.Get_Value(NewNi, NewNj);
	cout << "Значение: " << Get_IJ << endl;
	// Очистка памяти

	cout << "Инкремент 1" << endl;

	MyMattrix.operator++();
	MyMattrix.PrintArray();


	cout << "Инкремент 2" << endl;

	MyMattrix.operator++(1);
	MyMattrix.PrintArray();

	cout << "Декремент 1" << endl;

	MyMattrix.operator--();
	MyMattrix.PrintArray();


	cout << "Декремент 2" << endl;

	MyMattrix.operator--(1);
	MyMattrix.PrintArray();
	//MyMattrix.~Mattrix();

#pragma endregion

	// Работа с классом Vektor
#pragma region Vektor
	Vektor MyVector(Ni, Nj);

	MyVector.Initial_Array(Ni, Nj);

	MyVector.PrintArray();

	double Pos = MyVector.operator[](3);
	cout << endl << "Ваша Число: " << Pos << endl << endl;

	cout << "Инкремент 1" << endl;
	MyVector.operator++();
	MyVector.PrintArray();
	cout << endl;

	cout << "Инкремент 2" << endl;
	MyVector.operator++(1);
	MyVector.PrintArray();
	cout << endl;

	cout << "Декремент 1" << endl;
	MyVector.operator--();
	MyVector.PrintArray();
	cout << endl;
	
	cout << "Декремент 1" << endl;
	MyVector.operator--(1);
	MyVector.PrintArray();
	cout << endl;
	//MyVector.~Vektor();
#pragma endregion

	system("pause");
} // main