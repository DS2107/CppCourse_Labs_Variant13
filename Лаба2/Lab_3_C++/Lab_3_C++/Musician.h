#pragma once
#include <iostream>
#include <vector>
#include <string>
class Musician
{
	// Данные музыканта
	struct DataMusician {
		// Имя
		std::string FirstName;

		// Фамилия
		std::string LastName;

		// Пол
		std::string Gender;

		// Год рождения
		int Birthday;

		// Инструмент 
		std::string Tool;

		// Рейтинг
		int Rating;
	};
	// Создаем объект для обращения к структуре
	DataMusician musician;

	// Файл с даннымм
	std::string filename = "DataMusician.txt";


public:
	// Конструктор без параметров
	Musician();

	// Конструтор с параметрами 
	Musician(const char* FirstName, const char* LastName, const char* Gender,
	int Birthday, const char* Tool, int Rating);

	// Конструктор с параметром 
	Musician(const Musician& m);

	// seter
	void Set_FirstName(const char* mFirstName);
	void Set_LastName(const char* mLastName);
	void Set_Gender(const char* mGender);
	void Set_Birthday(int mBirthday);
	void Set_Tool(const char* mTool);
	void Set_Rating(int mRating);

	// Запись в файл
	void serialize();

	// Запись в указанный файл
	void serialize(std::string filename);

	// Чтение из файла
	void deserialize();

	// Чтение из указанного файла
	 void deserialize(std::string filename);

	// концерт
	void Performance();

	// Сортировка музыкантов по рейтингу (квлавиши в верху)
	 static void MySort(std::vector<Musician> &MusicRat);

	// Вывод на экран
	void print();


	// Деструктор
	~Musician();

private:

};