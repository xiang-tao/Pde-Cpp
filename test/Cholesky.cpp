#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    Matrix A = { { 4, 2, 4 }, { 2, 37, 8 }, { 4, 8, 14 } };
    int n = A.shape[0];
    Matrix L(n, n, 0);
    cout << L << endl;
    Cholesky(A, L);
    cout << L << endl;
    cout << L.transpose() << endl;
    cout << L * L.transpose() << endl;

    return 0;
}
