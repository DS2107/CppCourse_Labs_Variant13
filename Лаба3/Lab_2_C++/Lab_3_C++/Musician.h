#pragma once
#include <iostream>
#include <vector>
#include <string>
class Musician
{
	protected:
	// Данные музыканта
	struct DataMusician {
		// Имя
		const char* FirstName;

		// Фамилия
		const char*  LastName;

		// Пол
		const char*  Gender;

		// Год рождения
		int Birthday;

		// Инструмент 
		const char*  Tool;

		// Рейтинг
		int Rating;
	};
	
	// Создаем объект для обращения к структуре
	DataMusician musician;

	// Файл с даннымм
	std::string filename = "DataMusician.txt";

	int nalog = 12;							//налог с концерта

	int time_of_work[2];					//время работы

	int vip_clients;						//клиенты vip


	enum TypeWork { close, not_close };

	std::vector<int> create;
	TypeWork typeWorkMusic;					//тип концерта (круглосуточно или нет)
	
	

public:
	static TypeWork getTypeWork(int i) {
		if (i == 1)
			return close;
		return not_close;
	};
	// Конструктор без параметров
	Musician();

	// Конструктор с параметром 
	Musician(const Musician& m);


	// Деструктор
	~Musician();

	// seter
	void Set_FirstName(const char* mFirstName);
	void Set_LastName(const char* mLastName);
	void Set_Gender(const char* mGender);
	void Set_Birthday(int mBirthday);
	void Set_Tool(const char* mTool);
	void Set_Rating(int mRating);
	

	// концерт
	void Performance();


	// Вывод на экран
	void print();

	void printRe();

	virtual void sale(int sum) = 0;



private:

};