#include "Subtractor.h"
#include <iostream>
#include <fstream>

using namespace std;


Subtractor::Subtractor()
{
}

Subtractor::~Subtractor()
{

}

double Subtractor::calculate()
{
	double* tmpArr = getArr();
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		sub -= *(tmpArr + i);
	}

	return sub;
}

void Subtractor::logToScreen()
{
	std::cout << "Subtractor" << endl;
	double* tmpArr = getArr();
	cout << "Total: " << getoperandsLenght() << " \n";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			cout << *(tmpArr + i);
		else
			cout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			cout << "-";
	}
	cout << "=" << sub << endl;
}

void Subtractor::logToFile(const std::string & filename)
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
			fout << "-";
	}
	fout << "=" << sub << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void Subtractor::shuffle()
{
	double* tmpArr = getArr();
	double mytemp1 = 0;
	double mytemp2 = 0;
	
	sub = 0;
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

void Subtractor::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		int tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}
