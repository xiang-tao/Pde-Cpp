#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 100; // 矩阵的最大维度

void Cholesky(double A[][MAXN], int n, double L[][MAXN])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * L[j][k];
            }
            if (i == j) {
                L[i][i] = sqrt(A[i][i] - sum);
            } else {
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main()
{
    int n;
    double A[MAXN][MAXN], L[MAXN][MAXN];

    cout << "请输入矩阵的维度：";
    cin >> n;

    cout << "请输入矩阵的元素：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    Cholesky(A, n, L);

    cout << "Cholesky分解结果为：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << L[i][j] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
