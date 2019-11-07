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



// Дополнительно
#pragma region extra
// Концерт
void Musician::Performance() {
	musician.Rating = 0 + rand() % 5;
} // Performance



void Musician::print() {
	cout << "FirstName: " << musician.FirstName << endl
		<< "LastName: " << musician.LastName << endl
		<< "Gender: " << musician.Gender << endl
		<< "Birthday: " << musician.Birthday << endl
		<< "Tool: " << musician.Tool << endl
		<< "Rating: " << musician.Rating << endl;

} //  print

void Musician::printRe()
{
	cout << "Rating: " << musician.Rating << endl;
}

#pragma endregion




// Деструктор
Musician::~Musician(){
	
} // ~Musician
