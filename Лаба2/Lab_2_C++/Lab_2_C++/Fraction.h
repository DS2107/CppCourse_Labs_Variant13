#pragma once
class Fraction
{
	int x, y;
	static int nCount;


private:
	Fraction();

public:
	
	Fraction(const Fraction& f);
	Fraction(int number);
	Fraction(double number);
	Fraction(int i, int j);
	

	Fraction operator+(const Fraction& number);
	Fraction operator-(const Fraction& number);
	Fraction operator*(const Fraction& number);
	Fraction operator/(const Fraction& number);

	void reduce();
	static int getCount();
	void print();

	static int gsd(int n1, int n2);
	static void printAsFraction(double number_dec);
	static void printAsFraction1(const char* number_dec);

	~Fraction();
};
