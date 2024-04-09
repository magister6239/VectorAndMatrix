#pragma once

class Vector
{
private:
	static int count;
	int num;

	int dim;
	double* a;

public:
	static unsigned GetCount();
	unsigned GetDimension() const;

	void print();

	Vector(unsigned d, double* arr);
	~Vector();

	Vector operator+(Vector const& other);
	Vector operator-(Vector const& other);
	Vector operator-();
	Vector operator*(Vector const& other);
	Vector operator*(double const& other);
	Vector operator=(Vector const& other);

	const double operator[](unsigned index) const;
};
