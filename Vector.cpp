#include <iostream>
#include "Vector.h"

using namespace std;


Vector::Vector(unsigned d, double* arr) {

	count++;
	num = count;
	dim = d;
	a = new double[d];

	for (int i = 0; i < d; i++) {
		a[i] = arr[i];
	}
}

Vector::~Vector() {
		cout << "Vector " << num << " destroyed" << endl;

		delete[] a;
}

Vector Vector::operator+(Vector const& other)
{
	if (dim != other.dim) cerr << "Error: Vectors are not same dimensional";

	double* arr = new double[dim];
	for (int i = 0; i != dim; i++) arr[i] = a[i] + other.a[i];

	return Vector(dim, arr);
}

Vector Vector::operator-(Vector const& other)
{
	if (dim != other.dim) cerr << "Error: Vectors are not same dimensional";

	double* arr = new double[dim];
	for (int i = 0; i != dim; i++) arr[i] = a[i] - other.a[i];

	return Vector(dim, arr);
}

Vector Vector::operator-()
{
	double* arr = new double[dim];
	for (int i = 0; i != dim; i++) arr[i] = -a[i];

	return Vector(dim, arr);
}

const double Vector::operator[](unsigned index)
{
	if (index >= dim) {
		throw std::out_of_range("Index out of range");
	}

	return a[index];
}

void Vector::print()
{
	for (int i = 0; i < 3; i++) cout << a[i] << " ";

	cout << endl;
}

unsigned Vector::count = 0;
