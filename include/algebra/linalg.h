#ifndef linalg_h
#define linalg_h
#include <math.h>

namespace PDECPP {
namespace AlgebraAlgrithom {

    template <typename Matrix, typename Vector>
    void jacobi(const Matrix& A, const Vector& b, Vector& x,
        int times = 5000, double tol = 1e-6)
    {
        int size = x.size;
        int d;
        Vector x1(size);
        for (int i = 0; i < times; i++) {
            for (int j = 0; j < size; j++) {
                x1[j] = b[j];
                for (int k = 0; k < size; k++) {
                    if (k == j)
                        d = A[j][j];
                    else
                        x1[j] -= A[j][k] * x[k];
                }
                x1[j] = x1[j] / d;
            }
            x = x1;
            auto err = b - A * x;
            auto err_norm = err.norm();
            if (err_norm < tol)
                break;
        }
    }

    template <typename Matrix>
    void LU(const Matrix& A, Matrix& L, Matrix& U)
    {
        int n = A.shape[0];
        Matrix B = A;
        for (int i = 0; i < n; i++) {
            U[0][i] = B[0][i];
        }
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                L[i][k] = B[i][k] / B[k][k];
            }
            for (int i = k + 1; i < n; i++) {
                for (int j = k + 1; j < n; j++) {
                    B[i][j] = B[i][j] - L[i][k] * U[k][j];
                }
            }
            for (int j = k + 1; j < n; j++) {
                U[k + 1][j] = B[k + 1][j];
            }
        }
    }

    template <typename Matrix>
    void Cholesky(const Matrix& A, Matrix& L)
    {
        int n = A.shape[0];
        int sum = 0;
        int sum1 = 0;
        for (int j = 0; j < n; j++) {
            sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[j][k] * L[j][k];
            }
            L[j][j] = sqrt(A[j][j] - sum);
            for (int i = j + 1; i < n; i++) {
                sum1 = 0;
                for (int k = 0; k < j; k++)
                    sum1 += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum1) / L[j][j];
            }
        }
    }
} // end of PDECPP
} //end of AlgebraAlgrithom
#endif
