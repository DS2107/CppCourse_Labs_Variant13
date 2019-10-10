#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Musician.h"

using namespace std;

// Конструкторы 
#pragma region Constructor
// Конструктор без параметров
Musician::Musician() {
	// Заполняем данные

	musician.FirstName = "Danil";
	musician.LastName = "Struchenkov";
	musician.Gender = "Man";
	musician.Birthday = 2000;
	musician.Tool = "Guitar";
	musician.Rating = 5;
} // Musician

// Конструктор с параметрами
Musician::Musician(const char * FirstName, const char * LastName,
	const char * Gender, int Birthday, const char* Tool, int Rating) {
	// Заполняем данные
	
	musician.FirstName = FirstName;
	musician.LastName = LastName;
	musician.Gender = Gender;
	musician.Birthday = Birthday;
	musician.Tool = Tool;
	musician.Rating = Rating;
} // Musician

// Конструктор с параметрам
Musician::Musician(const Musician & m) {
	// Заполняем данные
	
	musician.FirstName = m.musician.FirstName;
	musician.LastName = m.musician.LastName;
	musician.Gender = m.musician.Gender;
	musician.Birthday = m.musician.Birthday;
	musician.Tool = m.musician.Tool;
	musician.Rating = m.musician.Rating;
} // Musician
#pragma endregion

// Сетеры
#pragma region Set
void Musician::Set_FirstName(const char * mFirstName) {
	musician.FirstName = mFirstName;
} // FirstName

void Musician::Set_LastName(const char * mLastName) {
	musician.LastName = mLastName;
} // LastName

void Musician::Set_Gender(const char * mGender) {
	musician.Gender = mGender;
} // Gender

void Musician::Set_Birthday(int mBirthday) {
	musician.Birthday = mBirthday;
} // Birthday

void Musician::Set_Tool(const char * mTool) {
	musician.Tool = mTool;
} // Tool

void Musician::Set_Rating(int mRating) {
	musician.Rating = mRating;
} // Rating

#pragma endregion

// Сериализация/Десериализация
#pragma region S/D
void Musician::serialize(){
	ofstream f(filename, ios_base::ate); //открываем для записи (параметр ate)
	f << musician.FirstName << std::endl
		<< musician.LastName << std::endl
		<< musician.Gender << std::endl
		<< musician.Birthday << std::endl
		<< musician.Tool << std::endl
		<< musician.Rating << std::endl;
	f.close();
} // serialize

void Musician::serialize(string filename){
	ofstream f(filename, ios_base::ate); //открываем для записи (параметр ate)
	f << musician.FirstName << std::endl
		<< musician.LastName << std::endl
		<< musician.Gender << std::endl
		<< musician.Birthday << std::endl
		<< musician.Tool << std::endl
		<< musician.Rating << std::endl;
	f.close();
} // serialize

void Musician::deserialize(){
	ifstream f(filename, ios_base::in); 
	f >> musician.FirstName
		>> musician.LastName
		>> musician.Gender
		>> musician.Birthday
		>> musician.Tool
		>> musician.Rating;
	f.close();
} // deserialize

void Musician::deserialize(string filename){
	ifstream f(filename, ios_base::in);
	f >> musician.FirstName
		>> musician.LastName
		>> musician.Gender
		>> musician.Birthday
		>> musician.Tool
		>> musician.Rating;
	f.close();
} // deserialize

#pragma endregion


// Дополнительно
#pragma region extra
// Концерт
void Musician::Performance() {
	musician.Rating = 0 + rand() % 5;
} // Performance

// Сортировка музыкантов
void Musician::MySort(vector<Musician> &MusicRat) {
	for (int i = 0; i < MusicRat.size(); i++) {
		
		for (int j = 0; j < MusicRat.size()-1; j++) {
			if (MusicRat[j].musician.Rating < MusicRat[j + 1].musician.Rating   ) {
				
					Musician b = MusicRat[j];
					MusicRat[j] = MusicRat[j + 1];
					MusicRat[j + 1] = b;
				
			}
			
		}		
	}

	for (int i = 0; i < MusicRat.size(); i++) {

		for (int j = 0; j < MusicRat.size() - 1; j++) {
			if (MusicRat[j].musician.Tool == "Keyboard") {

				Musician b = MusicRat[j+1];
				 MusicRat[j+1] = MusicRat[j];
				 MusicRat[j] = b;

			}

		}
	}
	cout << "Sort:" << endl;
	for (int i = 0; i < MusicRat.size(); i++) {
		cout <<endl<< MusicRat[i].musician.FirstName << endl
			<< MusicRat[i].musician.Rating << endl
			<< MusicRat[i].musician.Tool << endl<<endl;
	}
} // Sort

void Musician::print() {
	cout << "FirstName: " << musician.FirstName << endl
		<< "LastName: " << musician.LastName << endl
		<< "Gender: " << musician.Gender << endl
		<< "Birthday: " << musician.Birthday << endl
		<< "Tool: " << musician.Tool << endl
		<< "Rating: " << musician.Rating << endl;

} //  print

#pragma endregion




// Деструктор
Musician::~Musician(){
	
} // ~Musician
