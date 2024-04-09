#include <iostream>
#include "Matrix.h"

using namespace std;


int Matrix::count = 0;

Matrix::Matrix(int d, double** arr) {
	count++;
	num = count;
	dim = d;

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

	count -= 1;
	cout << "Matrix " << num << " destroyed" << endl;
}





