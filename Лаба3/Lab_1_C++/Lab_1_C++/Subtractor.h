#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Subtractor : public ExpressionEvaluator, public IShuffle
{
private:
	double sub;
public:
	Subtractor();
	~Subtractor();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(int i, int j);
};

