
#pragma once
class Vektor {
private:
	int Ni;
	int Nj;
	//  ���������� ������
	//= new double[Ni*Nj]
	double* Array1d;
public:
	// ����������� ��� ����������
	Vektor();
	
	// ����������� � �����������
	Vektor(int Ni,int Nj);

	// ��������
	void Initial_Array(size_t Ni,size_t Nj);

	// �����
	void PrintArray();

	// �������� ����������
	double& operator [](int pos);


	// �������� (����������/����������)
	double& operator ++ ();
	double& operator ++ (int m);
	double& operator -- ();
	double& operator -- (int m);

	// ����������
	~Vektor();





};