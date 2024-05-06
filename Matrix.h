#pragma once
class Matrix
{
private:
	
	static int count;

	int dim;
	double** a;
	int num;

public:
	static unsigned GetCount();
	unsigned GetDimension() const;

	void print();

	Matrix(int d, double** arr);
	~Matrix();

	Matrix operator+(Matrix const& other);
	Matrix operator-(Matrix const& other);
	Matrix operator-();
	Matrix operator*(Matrix const& other);
	Matrix operator*(double const& other);
	Matrix& operator=(Matrix const& other);
};
