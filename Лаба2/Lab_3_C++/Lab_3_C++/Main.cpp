#include <iostream>
#include "Windows.h"
#include "Musician.h"
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//Работа с конструкторами 
	Musician mus1("Alex", "Petrov", "Man",1998,"Drums",3);														//в стеке
	Musician* mus2 = new Musician;																				//в хипе
	Musician* mus3 = new Musician("Petrov", "Pupkin", "Man", 1983, "Drums", 4);									//в хипе

	

	cout << endl<<"В СТЕКЕ mus1"<<endl;
	mus1.print();
	cout << endl;
	cout << endl << "В ХИПЕ mus2"<<endl;
	mus2->print();
	cout << endl;
	cout << endl << "В ХИПЕ mus3"<<endl;
	mus3->print();

// Серилизация и сет
	cout << endl << "В Стеке mus4";
	cout << endl << endl;
	Musician mus4("Dmitri", "Vasya", "Man", 1980, "Drums", 2);
	mus4.Set_FirstName("Ledi");
	mus4.Set_LastName("Gaga");
	mus4.Set_Gender("Woman");
	cout << endl << "Серилизация/Десериализация"<<endl;
	mus4.serialize();
	mus4.deserialize();
	mus4.print();

	cout << endl << endl << "Концерты" << endl;
	Musician* mus5 = new Musician("Djum", "Head", "Man", 1759, "Guitar", 0);
	Musician* mus6 = new Musician("Joe", "Barboro", "Man", 1760, "Drums", 0);
	Musician* mus7 = new Musician("Vito", "Scalleto", "Man", 1761, "Keyboard", 0);
	Musician* mus8 = new Musician("Ledi", "Head", "Man", 1759, "Guitar", 0);
	Musician* mus9 = new Musician("Malba", "Barboro", "Man", 1760, "Drums", 0);
	Musician* mus10 = new Musician("Vara", "Scalleto", "Man", 1761, "Keyboard", 0);
	Musician* mus11 = new Musician("Tara", "Head", "Man", 1759, "Guitar", 0);
	Musician* mus12 = new Musician("Gara", "Barboro", "Man", 1760, "Drums", 0);
	Musician* mus13 = new Musician("Vito22", "Scalleto", "Man", 1761, "Keyboard", 0);
	mus5->Performance();
	mus6->Performance();
	mus7->Performance();
	mus8->Performance();
	mus9->Performance();
	mus10->Performance();
	mus11->Performance();
	mus12->Performance();
	mus13->Performance();

	cout << endl << endl << "Рейтинги" << endl;
	mus5->print();
	cout << endl << endl;
	mus6->print();
	cout << endl << endl;
	mus7->print();

	cout << endl << endl;
	mus8->print();
	cout << endl << endl;
	mus9->print();
	cout << endl << endl;
	mus10->print();

	cout << endl << endl;
	mus11->print();
	cout << endl << endl;
	mus12->print();
	cout << endl << endl;
	mus13->print();

	vector<Musician> MusReiting = { *mus5, *mus6, *mus7,*mus8,*mus9,*mus10,*mus11,*mus12,*mus13, };
	
	Musician::MySort(MusReiting);
	system("pause");
	cout << endl;
	
	return 0;
} // main