#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    // Matrix A = { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 3, 4, 5, 6 }, { 4, 5, 6, 7 } };
    Matrix A = { { 0, 1, 1, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 } };
    int n = A.shape[0];
    Vector x(n);
    cout << x << endl;
    Matrix Q(n, n);
    Matrix R(n, n);
    Vector b = { 1, 0, 0, 0 };
    // qr_mgs<Matrix, Vector>(A, Q, R);
    qr_givens<Matrix>(A, Q, R);
    // cout << Q << endl;
    // cout << R << endl;
    Vector b1 = Q.transpose() * b;
    solve_ssj(R, x, b1);
    cout << x << endl;
    cout << A * x << endl;

    return 0;
}
