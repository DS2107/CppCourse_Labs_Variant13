#pragma once
#include <iostream>
#include <vector>
#include <string>
class Musician
{
	protected:
	// ������ ���������
	struct DataMusician {
		// ���
		const char* FirstName;

		// �������
		const char*  LastName;

		// ���
		const char*  Gender;

		// ��� ��������
		int Birthday;

		// ���������� 
		const char*  Tool;

		// �������
		int Rating;
	};
	
	// ������� ������ ��� ��������� � ���������
	DataMusician musician;

	// ���� � �������
	std::string filename = "DataMusician.txt";

	int nalog = 12;							//����� � ��������

	int time_of_work[2];					//����� ������

	int vip_clients;						//������� vip


	enum TypeWork { close, not_close };

	std::vector<int> create;
	TypeWork typeWorkMusic;					//��� �������� (������������� ��� ���)
	
	

public:
	static TypeWork getTypeWork(int i) {
		if (i == 1)
			return close;
		return not_close;
	};
	// ����������� ��� ����������
	Musician();

	// ����������� � ���������� 
	Musician(const Musician& m);


	// ����������
	~Musician();

	// seter
	void Set_FirstName(const char* mFirstName);
	void Set_LastName(const char* mLastName);
	void Set_Gender(const char* mGender);
	void Set_Birthday(int mBirthday);
	void Set_Tool(const char* mTool);
	void Set_Rating(int mRating);
	

	// �������
	void Performance();


	// ����� �� �����
	void print();

	void printRe();

	virtual void sale(int sum) = 0;



private:

};