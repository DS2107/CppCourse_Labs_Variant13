#pragma once
#include "Musician.h"
#include "IPayment.h"

class Not_Close :
	public Musician,
	public IPayment
{
public:
	Not_Close(const char* FirstName, const char* Tool, const char* Gender, TypeWork t);
	int pay();
	void sale(int sum);
	~Not_Close();
};