#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    // Matrix A = { { 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 12 } };
    Matrix A = { { 0.02, 61.3 }, { 3.43, -8.5 } };
    int n = A.shape[0];
    Matrix L(n, n, 0);
    L.fill_diag(1);
    Matrix U(n, n, 0);
    cout << A << endl;
    LU(A, L, U);
    cout << L << endl;
    cout << U << endl;
    cout << L * U << endl;

    return 0;
}
