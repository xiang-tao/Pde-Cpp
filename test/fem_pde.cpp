#include "thirdparty/matplotlibcpp.h"
#include <Constants.h>
#include <algebra/Algebra_kernel.h>
#include <iostream>
namespace plt = matplotlibcpp;
using namespace Constant;
using namespace std;

int main()
{
    int n = 21;
    double h = 1.0 / n; //注意，这里要用1.0,否则由于n是int类型，1也是int类型，导致h=0,而不是double的1/6.
    // cout << h << endl;
    Vector x((n - 1) * (n - 1));
    Vector b((n - 1) * (n - 1));
    Vector b1((n - 1) * (n - 1));
    Matrix A((n - 1) * (n - 1), (n - 1) * (n - 1));
    double arr[(n - 1) * (n - 1)];
    double arr1[(n - 1) * (n - 1)];
    for (int i = 0; i < (n - 1) * (n - 1); i++) {
        if ((i + 1) % (n - 1) == 0)
            arr[i] = 0;
        else
            arr[i] = -1;
        if (i % (n - 1) == 0)
            arr1[i] = 0;
        else
            arr1[i] = -1;
    }
    A.fill_diag(4);
    A.fill_diag(arr, 1);
    A.fill_diag(arr1, -1);
    A.fill_diag(-1, n - 1);
    A.fill_diag(-1, -(n - 1));
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            b[k] = h * h * 2.0 * pi * pi * sin(pi * (i + 1) * h) * sin(pi * (j + 1) * h); //注意这里还要乘h平方.
            b1[k] = sin(pi * (i + 1) * h) * sin(pi * (j + 1) * h);
            k = k + 1;
        }
    }
    CG(A, b, x);
    cout << (b - A * x).norm() << endl;
    k = 0;
    std::vector<std::vector<double>> x1, y, z;
    for (int i = 0; i < n - 1; i++) {
        std::vector<double> x_row, y_row, z_row;
        for (int j = 0; j < n - 1; j++) {
            x_row.push_back((i + 1) * h);
            y_row.push_back((j + 1) * h);
            z_row.push_back(x[k]);
            k += 1;
        }
        x1.push_back(x_row);
        y.push_back(y_row);
        z.push_back(z_row);
    }

    plt::plot_surface(x1, y, z);
    plt::show();

    return 0;
}
