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


    double arr3[3][3] = {
        {3, 7, 9},
        {7, 0, 1},
        {2, 2, 2}
    };
    double arr4[3][3] = {
        {1, 1, 1}, 
        {1, 1, 1}, 
        {1, 1, 1}
    };

    cout << arr3;
    cout << endl;
    cout << arr3[2];
    cout << endl;
    cout << arr3[2][2];

    return 0;
}
