#include <iostream>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "ILoggable.h"
#include "IShuffle.h"

using namespace std;

void main()
{
	ExpressionEvaluator* MyCalc[3];

	MyCalc[0] = new CustomExpressionEvaluator();
	double custom_operands[] = { 2.5, -5, -3, 2, 10};
	MyCalc[0]->setOperands(custom_operands, 5);

	MyCalc[1] = new Subtractor();
	MyCalc[1]->setOperand(0, 23.65);
	MyCalc[1]->setOperand(1, -12.15);
	
	MyCalc[2] = new Multiplier();
	MyCalc[2]->setOperand(0, 2.5);
	MyCalc[2]->setOperand(1, -3);
	MyCalc[2]->setOperand(2, 4);
	MyCalc[2]->setOperand(3, -1);

	for (int i = 0; i < 3; i++)
	{
		double res = MyCalc[i]->calculate();
		MyCalc[i]->logToFile("lab3.log");
		MyCalc[i]->logToScreen();
		std::cout << "\nEquals to " << res << std::endl << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		
		IShuffle* loga = dynamic_cast<IShuffle*>(MyCalc[i]);
		
		if (loga)
		{
			loga->shuffle();
			double res = MyCalc[i]->calculate();
			MyCalc[i]->logToScreen();
			std::cout << "\nEquals to " << res << std::endl << std::endl;
		}
	}


	system("pause");

	delete MyCalc[0];
	delete MyCalc[1];
	delete MyCalc[2];
}