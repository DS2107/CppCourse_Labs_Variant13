#pragma once
#include <iostream>
#include <vector>
#include <string>
class Musician
{
	// ������ ���������
	struct DataMusician {
		// ���
		std::string FirstName;

		// �������
		std::string LastName;

		// ���
		std::string Gender;

		// ��� ��������
		int Birthday;

		// ���������� 
		std::string Tool;

		// �������
		int Rating;
	};
	// ������� ������ ��� ��������� � ���������
	DataMusician musician;

	// ���� � �������
	std::string filename = "DataMusician.txt";


public:
	// ����������� ��� ����������
	Musician();

	// ���������� � ����������� 
	Musician(const char* FirstName, const char* LastName, const char* Gender,
	int Birthday, const char* Tool, int Rating);

	// ����������� � ���������� 
	Musician(const Musician& m);

	// seter
	void Set_FirstName(const char* mFirstName);
	void Set_LastName(const char* mLastName);
	void Set_Gender(const char* mGender);
	void Set_Birthday(int mBirthday);
	void Set_Tool(const char* mTool);
	void Set_Rating(int mRating);

	// ������ � ����
	void serialize();

	// ������ � ��������� ����
	void serialize(std::string filename);

	// ������ �� �����
	void deserialize();

	// ������ �� ���������� �����
	 void deserialize(std::string filename);

	// �������
	void Performance();

	// ���������� ���������� �� �������� (�������� � �����)
	 static void MySort(std::vector<Musician> &MusicRat);

	// ����� �� �����
	void print();


	// ����������
	~Musician();

private:

};