#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    Vector x1 = { 2, 0, 0, 0 };
    Vector x2 = { -1, 2, 3, 4 };
    Vector x3 = { 1, 2, 3, 4 };
    Vector v1 = get_hhv(x1);
    Vector v2 = get_hhv(x2);
    Vector v3 = get_hhv(x3);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    Matrix I(4, 4);
    I.fill_diag(1);
    Matrix H2 = I - 2 / inner(v2, v2) * vv<Matrix>(v2, v2);
    Matrix H = get_hhH<Matrix, Vector>(x2);
    cout << H2 * x2 << endl;
    cout << H * x2 << endl;

    return 0;
}
