#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
using namespace std;


CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}

CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}

double CustomExpressionEvaluator::calculate()
{
	double* tmpArr = getArr();
	result = *(tmpArr + 0);
	for (int i = 1; i < getoperandsLenght(); i++)
	{
		if (i == 1)
		{
			result += *(tmpArr + i);
		}
		else
		{
			result *= *(tmpArr + i);
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen()
{
	std::cout << "CustomExpressionEvaluator____" << endl;
	double* tmpArr = getArr();
	cout << "Expression [" << getoperandsLenght() << "] \n";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
		{
			if (i == 0)
			{
				cout <<"(" <<*(tmpArr + i);
			}
			else if(i==1)
			{
				cout << *(tmpArr + i)<<")";
			}
			else
			{
				cout << *(tmpArr + i) ;
			}
			
		}
		else
		{
			if(i==1)
			cout << "(" << *(tmpArr + i) << "))";
			else
				cout << "(" << *(tmpArr + i) << ")";
		}
		if (getoperandsLenght() != i + 1)
		{
			if (i == 0 )
			{
				cout << " + ";
			}
			else
			{
				cout << " * ";
			}
		}
	}
	cout << " = " << result << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string & filename)
{
	double* tmpArr = getArr();

	std::fstream fout(filename, std::ios::app);

	fout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
		{
			if(i==0)
			fout <<"("<< *(tmpArr + i);
			else if(i==1)
				fout  << *(tmpArr + i) << ")";
			else
				fout << *(tmpArr + i) ;
		}
		else
		{
				if (i == 1)
				fout << "(" << *(tmpArr + i) << "))";
				else
			fout << "(" << *(tmpArr + i) << ")";
		}
		if (getLenght() != i + 1)
		{
			if (i == 0)
			{
				fout << " + ";
			}
			else
			{
				fout << " * ";
			}
		}
	}
	fout << " = " << result << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void CustomExpressionEvaluator::shuffle()
{
	double* tmpArr = getArr();
	double mytemp1 = 0;
	double mytemp2 = 0;


	for (int i = 1; i < getoperandsLenght(); ++i)
	{
		for (int r = 0; r < getoperandsLenght() - i; r++)
		{
			if (floor(tmpArr[r]))
			{
				double temp = tmpArr[r];
				tmpArr[r] = tmpArr[r + 1];
				tmpArr[r + 1] = temp;
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		double tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}
