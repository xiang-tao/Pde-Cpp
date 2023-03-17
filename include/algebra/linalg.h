#ifndef linalg_h
#define linalg_h
#include <iostream>
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

    /*
     *请注意，下面的gm_col和gm_row分别表示获取矩阵的某列和某行数据，但是模板中使用了Matrix和Vector
     *两个数据类型，如果在函数的参数列表中，例如gm_col中只使用了Matrix数据类型，而Vector类型没有
     只是出现在了返回类型中时，直接使用gm_col（A，r），系统会报错，无法找到该函数，原因是由于Vector
     未出现在函数参数列表中时，直接使用gm_col(A,r)他无法自动推导出Vector数据类型，因此需要告诉他的
     函数模板类型，即正确的使用方式是gm_col<matrix,Vector>(A,r)
     * */
    template <typename Matrix, typename Vector>
    Vector gm_col(const Matrix& A, int r)
    {
        int row = A.shape[0];
        int col = A.shape[1];
        Vector v(row);
        for (int i = 0; i < col; i++) {
            if (r >= col) {
                std::cout << "列标越界" << std::endl;
                break;
            } else {
                v[i] = A[i][r];
            }
        }
        return v;
    }

    template <typename Matrix, typename Vector>
    Vector gm_row(const Matrix& A, int r)
    {
        int row = A.shape[0];
        int col = A.shape[1];
        Vector v(col);
        for (int i = 0; i < col; i++) {
            if (r >= row) {
                std::cout << "行标越界" << std::endl;
                break;
            } else {
                v[i] = A[r][i];
            }
        }
        return v;
    }

    //计算向量的内积
    template <typename Vector>
    double inner(const Vector& v, const Vector& u)
    {
        int n1 = v.size;
        int n2 = u.size;
        double inn = 0;
        if (n1 == n2) {
            for (int i = 0; i < n1; i++) {
                inn += v[i] * u[i];
            }
            return inn;
        } else {
            std::cout << "error,维度不一致无法内积计算" << std::endl;
            return 0;
        }
    }

    //使用修正的施密特正交化计算A=QR分解，目前仅仅适用计算A是列满秩（含非奇异的方正），因为对于
    //奇异的矩阵，对于扩展基还未实现该功能，理论详细见矩阵计算讲义P82-83页。
    //注意这里跟上面一样要使用qr_mgs<Matrix,Vector>(A,Q,R)才不会报错
    template <typename Matrix, typename Vector>
    void qr_mgs(const Matrix& A, Matrix& Q, Matrix& R)
    {
        int n1 = A.shape[0];
        int n2 = A.shape[1];
        Vector zeros(n1);
        Vector a = gm_col<Matrix, Vector>(A, 0);
        Vector qk(n1);
        Vector qi(n1);
        if (a != zeros) {
            R[0][0] = sqrt(inner(a, a));
            for (int i = 0; i < n1; i++) {
                Q[i][0] = A[i][0] / R[0][0];
            }
        }
        for (int k = 1; k < n2; k++) {
            a = gm_col<Matrix, Vector>(A, k);
            qk = a;
            for (int i = 0; i < k; i++) {
                qi = gm_col<Matrix, Vector>(Q, i);
                R[i][k] = inner(qi, qk);
                qk -= R[i][k] * qi;
            }
            if (qk != zeros) {
                R[k][k] = sqrt(inner(qk, qk));
                qk = qk / R[k][k];
            }
            for (int i = 0; i < n1; i++) {
                Q[i][k] = qk[i];
            }
        }
    }

} // end of PDECPP
} //end of AlgebraAlgrithom
#endif
