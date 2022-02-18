#include <iostream>
#include "algebra/Algebra_kernel.h"
using namespace std;
int main()
{
    double d = 1.0;
    double a = 3.0;
    double c = d / a;
    cout << c << endl;
    Vector A(2.0,3);
    cout<<A<<endl;
    return 0;
}
