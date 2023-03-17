#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    // Matrix A = { { 1, 1, 1 }, { 2, -1, -1 }, { 2, -4, 10 } };
    Matrix A = { { 1, 1 }, { 2, -1 }, { 2, -4 } };
    int m = A.shape[0];
    int n = A.shape[1];
    Matrix Q(m, n);
    Matrix R(n, n);
    qr_mgs<Matrix, Vector>(A, Q, R);
    cout << A << endl;
    cout << Q << endl;
    cout << R << endl;
    cout << Q * R << endl;

    return 0;
}
