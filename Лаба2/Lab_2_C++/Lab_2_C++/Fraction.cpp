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

// ������� ����� � ����� , �������� 10 = 10/1
Fraction::Fraction(int number){
	// x - ���� ����� 
	// y - ��������
	x = number, y = 1;

	// �� ������� ���������� ���-�� ��������� ������
	nCount++;
} // Fraction

// ����� � ��������� �������
Fraction::Fraction(double number){
	// x -  ���� �����, ��� ��� ��� � ��������� �������, ������� �������  
	x = number * 1000000;
	
	// ��� ���������� ����������� ������ �������� ��� ����������� ��� �����
	y = 1000000;

	// �������� ����� ��� ���������� ����� 
	reduce();

	// �� ������� ���������� ���-�� ��������� ������
	nCount++;
} // Fraction

// ����������� ������� ������ ��������� �����
Fraction::Fraction(int i, int j){
	// �������� 
	if (j == 0)
		cout << "Exeption!" << endl;
	else
		// ����������� ��������
		x = i, y = j;
	// �������� ����� ��� ���������� ����� 
	reduce();
	// �� ������� ���������� ���-�� ��������� ������
	nCount++;
} // Fraction

Fraction::~Fraction(){
	nCount--;
} // ~Fraction

Fraction Fraction::operator+(const Fraction & number){
	// ����������� ������� ������ ��������� �����
	Fraction f(x*number.y + number.x*y, y*number.y);

	// ����� ������������ �������� � ������ �����������,
	// � ������� �������� ����� �������� x � y
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

// ����� ��� ���������� �����
void Fraction::reduce(){
		// ������� ��������� ����������, � ������� �������� ��� x,y
		// ��� �������� � ������� ����� ������� gsd
		int temp = gsd(abs(x), abs(y));

		// ���� ����� � ���������� ������� 
		// �������� ����� ��� ������� ������� ��������� ��������� ����� �������� 3.14 = 157/50 
		// ��� 157 - x, � y - 50 
		x /= temp, y /= temp;	
} // reduce

// �� ������� �������� ���-�� ��������� ������ 
int Fraction::getCount() {
	return nCount;
} // getCount

// ����� �� �����
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


