#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;


int main()
{
    double arr1[] = {3, 7, 9};
    double arr2[] = {1, 1, 1};

    Vector v1 = Vector(3, arr1);
    Vector v2 = Vector(3, arr2);

    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = -v2;
    Vector v6 = v3 * 3;

    v1.print();
    v2.print();
    v3.print();
    v4.print();
    v5.print();
    v6.print();

    double arr3[3][3] = {
        {3, 7, 9},
        {7, 0, 1},
        {2, 2, 2}
    };

    // Кастыль

    int dim = 3;

    double** arr3_d = new double* [dim];

    for (int i = 0; i < dim; i++) {
        arr3_d[i] = new double [dim];
        for (int j = 0; j < dim; j++) {
            arr3_d[i][j] = arr3[i][j];
        }
    }

    Matrix m1 = Matrix(3, arr3_d);
    Matrix m2 = Matrix(3, arr3_d);
    Matrix m3 = m1 + m2;
    Matrix m4 = m3 - m2;
    Matrix m5 = -m3;
    Matrix m6 = m4 * 3;
    Matrix m7 = m4 * m1;

    for (int i = 0; i < dim; i++) {
        delete[] arr3_d[i];
    }

    delete[] arr3_d;

    // Кастыль

    m1.print();
    m2.print();
    m3.print();
    m4.print();
    m5.print();
    m6.print();
    m7.print();

    return 0;
}
