#include "Close.h"

Close::Close(const char* FirstName, const char* Tool, const char* Gender, TypeWork t) {
	musician.Gender = Gender;
	musician.Tool = Tool;
	musician.FirstName = FirstName;
	musician.FirstName = "Zzzz";
	musician.Birthday = 2222;
	musician.Rating = 0;
	create = {};
	typeWorkMusic = t;
	if (typeWorkMusic == 1) {
		time_of_work[0] = 8;
		time_of_work[1] = 21;
	}

}

int Close::pay()
{
	return int(0.25*create.back()) + nalog;
}

void Close::sale(int sum)
{
	create.push_back(sum);
	musician.Rating += sum - pay();
}

Close::~Close()
{
}
