#include <algebra/Algebra_kernel.h>
#include <iostream>
using namespace std;

int main()
{
    Vector v1 = { 1, 2, 3 };
    v1 -= 3 * v1;
    cout << v1 << endl;

    return 0;
}
