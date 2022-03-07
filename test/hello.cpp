#include "algebra/Algebra_kernel.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix A(3, 5, 1);
    Matrix B(A);
    Matrix C(B.shape[0], B.shape[1]);
    C = B;
    cout << C << endl;
    return 0;
}
