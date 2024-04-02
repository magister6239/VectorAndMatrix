#pragma once

class Vector
{
private:
	static unsigned count;
	unsigned num;

	unsigned dim;
	double* a;

public:
	Vector(unsigned d, double* arr);
	~Vector();

	Vector operator+(Vector const& other);
	Vector operator-(Vector const& other);
	Vector operator-();
	Vector operator*(Vector const& other);
	Vector operator=(Vector const& other);

	const double operator[](unsigned index);

	void print();

};

