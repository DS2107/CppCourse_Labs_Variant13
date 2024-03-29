#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Multiplier :
	public ExpressionEvaluator, public IShuffle
{
private:
	double mult;
public:
	Multiplier();
	~Multiplier();
	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(int i, int j);
};

