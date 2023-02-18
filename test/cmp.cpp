#include "algebra/Algebra_kernel.h"
#include <iostream>
using namespace std;
Matrix zm(int n = 2)
{
    Matrix m(n, n);
    for (int i = 0; i < n - 1; i++)
        m[i][i + 1] = 1.0;
    return m;
}
int main()
{
    int n = 6;
    Matrix mm = zm(n);
    cout << mm * mm * mm * mm << endl;
    return 0;
}
