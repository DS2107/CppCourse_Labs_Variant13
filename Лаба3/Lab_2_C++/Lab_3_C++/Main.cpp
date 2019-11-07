#include <iostream>
#include "Windows.h"
#include "Musician.h"
#include "Close.h"
#include "Not_Close.h"
#include "IPayment.h"
#include <algorithm>
#include <vector>

using namespace std;
//������������ ���������� ����������, ������������ � RTTI
//2 �������� �������� � 1 ��������, ������������������ ����������� pay()
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Musician * mus[3];
	mus[0] = new Close("Danil", "��������", "������� �����", Musician::getTypeWork(1));
	mus[1] = new Not_Close("Danil", "��������", "������� �����", Musician::getTypeWork(0));
	mus[2] = new Not_Close("Danil", "��������", "������� �����", Musician::getTypeWork(0));
	//�������������� ������������ payTax()
	mus[0]->sale(100);
	mus[1]->sale(100);
	mus[2]->sale(100);
	mus[0]->printRe();
	mus[1]->printRe();
	mus[2]->printRe();
	//������������ RTTI � ������������, � ���������� ����������
	for (int i = 0; i < 3; i++) {
		IPayment* tax = dynamic_cast<IPayment*>(mus[i]);
		cout << "����� �� �������: " << tax->pay() << endl;
	}

	system("pause");

	
	return 0;
} // main