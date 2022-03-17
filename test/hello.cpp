#include "algebra/Algebra_kernel.h"
#include "mesh/Mesh.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix A(3, 4, 2);
    Matrix B = A.reshape(4, -1);
    auto C = B;
    cout << B << endl;
    cout << C << endl;

    return 0;
}
