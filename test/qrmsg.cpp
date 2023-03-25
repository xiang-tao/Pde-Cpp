#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    Matrix m = get_givens<Matrix>(6, 2, 4, 1, -1);
    cout << m << endl;

    return 0;
}
