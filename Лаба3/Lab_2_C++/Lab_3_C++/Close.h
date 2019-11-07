#pragma once
#include "Musician.h"
#include "IPayment.h"

class Close :
	public Musician,
	public IPayment
{
public:
	Close(const char* FirstName, const char* Tool, const char* Gender, TypeWork t);
	int pay();
	void sale(int sum);
	~Close();
};