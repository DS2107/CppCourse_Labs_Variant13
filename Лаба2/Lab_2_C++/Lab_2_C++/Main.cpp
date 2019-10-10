#include <iostream>
#include <Windows.h>
#include "Fraction.h"
using namespace std;

int main(){

	// �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	Fraction f1(-20);
	Fraction f2(6, 36);
	Fraction f3(55.20);



	Fraction f4 = f2 + f2;
	Fraction f5 = f4 - f2;
	Fraction f6 = f4 * f2;
	Fraction f7 = f4 / f6;

	cout << f1.getCount() << " ������:" << endl;
	cout << "f1 = -20 = ";
	f1.print();
	cout << "f2 = 6/36 = ";
	f2.print();
	cout << "f3 = 55.20 = ";
	f3.print();

	cout << endl;
	cout << "----------�������(*,/,+,-)-----------" << endl;

	cout << "f4 = 1/6 + 1/6 = ";
	f4.print();
	cout << "f5 = 1/3 - 1/6 = ";
	f5.print();
	cout << "f6 = 1/3 * 1/6 = ";
	f6.print();
	cout << "f7 = 1/3 / 1/18 = ";
	f7.print();

	cout << endl;
	cout << "----------���-----------" << endl;

	cout << "��� 32 � 62: " << Fraction::gsd(62, 32) << endl;

	cout << endl;
	cout << "----------��������������-----------" << endl;
	cout << "�����:" << endl;
	Fraction::printAsFraction(0.43);
	cout << "������:" << endl;
	Fraction::printAsFraction1("0.43");

	system("pause");
	return 0;
} // main