#include <iostream>
#include "Windows.h"
#include "Musician.h"
#include "Close.h"
#include "Not_Close.h"
#include "IPayment.h"
#include <algorithm>
#include <vector>

using namespace std;
//демонстрация применения интерфейса, полиморфизма и RTTI
//2 закрытых концерта и 1 открытый, продемонстрировать полиморфизм pay()
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Musician * mus[3];
	mus[0] = new Close("Danil", "Барабаны", "Суровый мухик", Musician::getTypeWork(1));
	mus[1] = new Not_Close("Danil", "Барабаны", "Суровый мухик", Musician::getTypeWork(0));
	mus[2] = new Not_Close("Danil", "Барабаны", "Суровый мухик", Musician::getTypeWork(0));
	//демонстрирация полиморфизма payTax()
	mus[0]->sale(100);
	mus[1]->sale(100);
	mus[2]->sale(100);
	mus[0]->printRe();
	mus[1]->printRe();
	mus[2]->printRe();
	//демонстрация RTTI и полиморфизма, и применения интерфейса
	for (int i = 0; i < 3; i++) {
		IPayment* tax = dynamic_cast<IPayment*>(mus[i]);
		cout << "Налог на прибыль: " << tax->pay() << endl;
	}

	system("pause");

	
	return 0;
} // main