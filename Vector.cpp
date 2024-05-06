#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;


int Vector::count = 0;

unsigned Vector::GetCount()
{
	return count;
}

unsigned Vector::GetDimension() const
{
	return dim;
}

void Vector::print()
{
	cout << "Vector " << num << ": ";
	for (int i = 0; i < dim; i++) cout << a[i] << " ";

	cout << endl;
}

Vector::Vector(unsigned d, double* arr) {

	count++;
	num = count;
	dim = d;
	a = new double[d];

	for (int i = 0; i < d; i++) {
		a[i] = arr[i];
	}

	cout << "Vector " << num << " created" << endl;
}

Vector::~Vector() {
	count -= 1;
	cout << "Vector " << num << " destroyed" << endl;

	delete[] a;
}

Vector Vector::operator+(Vector const& other)
{
	if (dim != other.dim) cerr << "Error: Vectors are not same dimensional";

	double* arr = new double[dim];
	for (int i = 0; i < dim; i++) arr[i] = a[i] + other.a[i];

	return Vector(dim, arr);
}

Vector Vector::operator-(Vector const& other)
{
	if (dim != other.dim) cerr << "Error: Vectors are not same dimensional";

	double* arr = new double[dim];
	for (int i = 0; i < dim; i++) arr[i] = a[i] - other.a[i];

	return Vector(dim, arr);
}

Vector Vector::operator-()
{
	double* arr = new double[dim];
	for (int i = 0; i < dim; i++) arr[i] = -a[i];

	return Vector(dim, arr);
}

Vector Vector::operator*(Vector const& other)
{
	if (dim != other.dim) cerr << "Error: Vectors are not same dimensional";

	double* arr = new double[dim];
	for (int i = 0; i < dim; i++) arr[i] = a[i] * other.a[i];

	return Vector(dim, arr);
}

Vector Vector::operator*(double const& n)
{
	double* arr = new double[dim];
	for (int i = 0; i < dim; i++) arr[i] = a[i] * n;

	return Vector(dim, arr);
}

Vector& Vector::operator=(Vector const& other)
{
	if (this == &other) {
		cerr << "Error: Equivalent objects" << endl;
		return *this;
	}

	this->dim = other.dim;
	this->a = new double[dim];
	for (int i = 0; i < dim; ++i) this->a[i] = other.a[i];

	return *this;
}

const double Vector::operator[](unsigned index) const
{
	if (index >= dim) {
		throw std::out_of_range("Index out of range");
	}

	return a[index];
}
