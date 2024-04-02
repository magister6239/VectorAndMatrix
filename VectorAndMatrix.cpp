#include <iostream>
#include "Vector.h"

using namespace std;



int main()
{
    double arr1[] = {3, 7, 9};
    double arr2[] = {1, 1, 1};

    Vector v1 = Vector(3, arr1);
    Vector v2 = Vector(3, arr2);
    Vector v3 = v1 + v2;
    
    v1.print();
    v2.print();
    v3.print();
}

