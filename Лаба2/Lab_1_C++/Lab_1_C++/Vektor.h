
#pragma once
class Vektor {
private:
	int Ni;
	int Nj;
	//  Одномерный массив
	//= new double[Ni*Nj]
	double* Array1d;
public:
	// Конструктор без параметров
	Vektor();
	
	// Конструктор с параметрами
	Vektor(int Ni,int Nj);

	// Создание
	void Initial_Array(size_t Ni,size_t Nj);

	// Вывод
	void PrintArray();

	// Оператор индексации
	double& operator [](int pos);


	// Оператор (Инкремента/Декремента)
	double& operator ++ ();
	double& operator ++ (int m);
	double& operator -- ();
	double& operator -- (int m);

	// Деструктор
	~Vektor();





};