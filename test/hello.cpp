#include "algebra/Algebra_kernel.h"
#include <iostream>
using namespace std;

template <typename T>
void mv(T& v)
{
    if (typeid(v) == typeid(Vector))
        cout << "vector" << endl;
    else
        cout << "matrix" << endl;
}

int main()
{
    Vector v(4);
    Matrix m(4, 4, 1);
    mv(v);
    return 0;
}
