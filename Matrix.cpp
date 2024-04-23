#include <iostream>
#include "Matrix.h"

using namespace std;

int Matrix::count = 0;

unsigned Matrix::GetCount()
{
	return count;
}

unsigned Matrix::GetDimension() const
{
	return dim;
}

void Matrix::print()
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

Matrix::Matrix(int d, double** arr) {
	count++;
	num = count;
	dim = d;

	a = new double* [dim];

	for (int i = 0; i < d; i++) {
		a[i] = new double[dim];
		for (int j = 0; j < d; j++) {
			a[i][j] = arr[i][j];
		}
	}

	cout << "Matrix " << num << " created" << endl;
}



Matrix::~Matrix() {
	for (int i = 0; i < dim; i++) {
		delete[] a[i];
	}

	delete[] a;

	count -= 1;
	cout << "Matrix " << num << " destroyed" << endl;
}

Matrix Matrix::operator+(Matrix const& other)
{
	if (dim != other.dim) cerr << "Error: Matrixes are not same dimensional";

	double** arr_new = new double* [dim];

	for (int i = 0; i < dim; i++) {
		arr_new[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			arr_new[i][j] = a[i][j] + other.a[i][j];
		}
	}

	Matrix new_matrix = Matrix(3, arr_new);

	for (int i = 0; i < dim; i++) {
		delete[] arr_new[i];
	}

	delete[] arr_new;

	return new_matrix;
}

Matrix Matrix::operator-(Matrix const& other)
{
	if (dim != other.dim) cerr << "Error: Matrixes are not same dimensional";

	double** arr_new = new double* [dim];

	for (int i = 0; i < dim; i++) {
		arr_new[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			arr_new[i][j] = a[i][j] - other.a[i][j];
		}
	}

	Matrix new_matrix = Matrix(3, arr_new);

	for (int i = 0; i < dim; i++) {
		delete[] arr_new[i];
	}

	delete[] arr_new;

	return new_matrix;
}

Matrix Matrix::operator-()
{
	double** arr_new = new double* [dim];

	for (int i = 0; i < dim; i++) {
		arr_new[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			arr_new[i][j] = -a[i][j];
		}
	}

	Matrix new_matrix = Matrix(3, arr_new);

	for (int i = 0; i < dim; i++) {
		delete[] arr_new[i];
	}

	delete[] arr_new;

	return new_matrix;
}

Matrix Matrix::operator*(Matrix const& other)
{
	if (dim != other.dim) cerr << "Error: Matrixes are not same dimensional";

	double** arr_new = new double* [dim];

	for (int i = 0; i < dim; i++) {
		arr_new[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			arr_new[i][j] = a[i][j] * other.a[i][j];
		}
	}

	Matrix new_matrix = Matrix(3, arr_new);

	for (int i = 0; i < dim; i++) {
		delete[] arr_new[i];
	}

	delete[] arr_new;

	return new_matrix;
}

Matrix Matrix::operator*(double const& other)
{
	double** arr_new = new double* [dim];

	for (int i = 0; i < dim; i++) {
		arr_new[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			arr_new[i][j] = a[i][j] * other;
		}
	}

	Matrix new_matrix = Matrix(3, arr_new);

	for (int i = 0; i < dim; i++) {
		delete[] arr_new[i];
	}

	delete[] arr_new;

	return new_matrix;
}

Matrix Matrix::operator=(Matrix const& other)
{
	if (this == &other) {
		cerr << "Error: Equivalent objects" << endl;
		return *this;
	}

	for (int i = 0; i < dim; i++) {
		delete[] a[i];
	}

	delete[] a;

	dim = other.dim;
	double** a = new double* [dim];

	for (int i = 0; i < dim; i++) {
		a[i] = new double[dim];
		for (int j = 0; j < dim; j++) {
			a[i][j] = other.a[i][j];
		}
	}

	return *this;
}





