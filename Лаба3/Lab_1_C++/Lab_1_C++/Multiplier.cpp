#include "Multiplier.h"
#include <iostream>
#include <fstream>
using namespace std;

Multiplier::Multiplier()
{
}

Multiplier::~Multiplier()
{
}

double Multiplier::calculate()
{
	double* tmpArr = getArr();
	mult = *(tmpArr + 0);
	for (int i = 1; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) == 0)
			return 0.0;
		mult *= *(tmpArr + i);
	}

	return mult;
}

void Multiplier::logToScreen()
{
	std::cout << "Multiplier____" << endl;
	double* tmpArr = getArr();
	cout << "Total: " << getoperandsLenght() << " \n ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			cout << *(tmpArr + i);
		else
			cout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			cout << "*";
	}
	cout << " = " << mult << endl;
}

void Multiplier::logToFile(const std::string & filename)
{
	double* tmpArr = getArr();

	std::fstream fout(filename, std::ios::app);

	fout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			fout << *(tmpArr + i);
		else
			fout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			fout << "*";
	}
	fout << " = " << mult << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void Multiplier::shuffle()
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

void Multiplier::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		double tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}
