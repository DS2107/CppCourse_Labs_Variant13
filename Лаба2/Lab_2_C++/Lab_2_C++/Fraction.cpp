#include "Fraction.h"
#include <iostream>

using namespace std;

int Fraction::nCount = 0;

Fraction::Fraction(){

} // Fraction

Fraction::Fraction(const Fraction & f){
	x = f.x, y = f.y;
	nCount++;
} // Fraction

// обычное число в дробь , например 10 = 10/1
Fraction::Fraction(int number){
	// x - наше число 
	// y - делитель
	x = number, y = 1;

	// по заданию записываем кол-во созданных дробей
	nCount++;
} // Fraction

// Число с плавающей запятой
Fraction::Fraction(double number){
	// x -  наше число, так как оно с палвающей запятой, убираем запятую  
	x = number * 1000000;
	
	// При нахождении найбольшего общего делителя нам понадобится это число
	y = 1000000;

	// вызываем метод для сокращения дроби 
	reduce();

	// по заданию записываем кол-во созданных дробей
	nCount++;
} // Fraction

// Конструктор который сравзу сокращает дробь
Fraction::Fraction(int i, int j){
	// проверка 
	if (j == 0)
		cout << "Exeption!" << endl;
	else
		// Присваеваем значения
		x = i, y = j;
	// Вызываем метод для сокращения дроби 
	reduce();
	// по заданию записываем кол-во созданных дробей
	nCount++;
} // Fraction

Fraction::~Fraction(){
	nCount--;
} // ~Fraction

Fraction Fraction::operator+(const Fraction & number){
	// Конструктор который сравзу сокращает дробь
	Fraction f(x*number.y + number.x*y, y*number.y);

	// Когда возвращаемся попадаем в другой коснтруктор,
	// В котором присваем новое значение x и y
	return f;
} // operator+

Fraction Fraction::operator-(const Fraction & number){
	Fraction f(x*number.y - number.x*y, y*number.y);
	return f;
	
} // operator-

Fraction Fraction::operator*(const Fraction & number){
	Fraction f(x*number.x, y*number.y);
	return f;
} // operator*

Fraction Fraction::operator/(const Fraction & number){
	Fraction f(x*number.y, y*number.x);
	return f;
} // operator/

// метод для сокращения дроби
void Fraction::reduce(){
		// Создаем временную переменную, в которую помещаем НОД x,y
		// Нод получаем с помощью нашей функции gsd
		int temp = gsd(abs(x), abs(y));

		// Если число с плаваеющей запятой 
		// получаем числа при делении которых получится введенное число например 3.14 = 157/50 
		// где 157 - x, а y - 50 
		x /= temp, y /= temp;	
} // reduce

// По заданию получить кол-во созданных дробей 
int Fraction::getCount() {
	return nCount;
} // getCount

// Вывод на экран
void Fraction::print(){
	cout << x << "/" << y << endl;
} // print

int Fraction::gsd(int n1, int n2){
	if (n2 == 0) {
		return n1;
	}
	else {
		return gsd(n2, n1 % n2);
	}
} // gsd

void Fraction::printAsFraction(double number_dec){
	int temp = gsd(abs(number_dec * 1000000), 1000000);
	int x = (number_dec * 1000000) / temp;
	int y = 1000000 / temp;
	cout << number_dec << " = " << x << "/" << y << endl;
} // printAsFraction

void Fraction::printAsFraction1(const char * number_dec){
	double x = atof(number_dec);
	int temp = gsd(abs(x * 1000000), 1000000);
	x = (x * 1000000) / temp;
	int y = 1000000 / temp;
	cout << number_dec << " = " << x << "/" << y << endl;
} // printAsFraction


