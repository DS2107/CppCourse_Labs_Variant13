#include "Not_Close.h"

Not_Close::Not_Close(const char* FirstName, const char* Tool, const char* Gender, TypeWork t) {
	musician.Gender = Gender;
	musician.Tool = Tool;
	musician.FirstName = FirstName;
	musician.FirstName = "s";
	musician.Birthday = 2222;
	musician.Rating = 0;
	create = {};
	typeWorkMusic = t;
	if (typeWorkMusic == 1) {
		time_of_work[0] = 8;
		time_of_work[1] = 21;
	}

}

int Not_Close::pay()
{
	return int(0.25*create.back()) + nalog;
}

void Not_Close::sale(int sum)
{
	create.push_back(sum);
	musician.Rating += sum - pay();
}

Not_Close::~Not_Close()
{
}
