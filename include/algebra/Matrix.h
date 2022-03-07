#ifndef Matrix_h
#define Matrix_h

#include <cassert>
#include <cmath>

#include <initializer_list>
#include <iostream>
#include <string>

namespace PDECPP {
namespace AlgebraObject {

    template <typename F = double, typename I = int>
    struct Matrix {
        typedef F Float;
        typedef I Int;
        F** data;
        I shape[2];

        // static std::string format;

        /*
     * 默认构造函数
     */
        Matrix()
        {
            //std::cout<<"无参构造函数调用"<<std::endl;
            data = nullptr;
            shape[0] = shape[1] = 0;
        }

        Matrix(I nr, I nc, F val = 0.0)
        {
            //std::cout<<"有参构造函数调用"<<std::endl;
            shape[0] = nr;
            shape[1] = nc;
            data = new F*[shape[0]];
            for (I i = 0; i < shape[0]; i++) {
                data[i] = new F[shape[1]];
                for (I j = 0; j < shape[1]; j++)
                    data[i][j] = val;
            }
        }

        Matrix<F, I>& operator=(const Matrix<F, I>& rhs)
        {
            if (this->shape[0] != rhs.shape[0] || this->shape[1] != rhs.shape[1]) {
                std::cout << "维度不一致，不能够赋值" << std::endl;
                assert(0);
            }
            if (this != &rhs) {
                for (I i = 0; i < shape[0]; i++) {
                    for (I j = 0; j < shape[1]; j++)
                        data[i][j] = rhs.data[i][j];
                }
            }
            return *this;
        }

        //拷贝构造函数
        Matrix(const Matrix& rhs)
        {
            this->shape[0] = rhs.shape[0];
            this->shape[1] = rhs.shape[1];

            data = new F*[shape[0]];
            for (I i = 0; i < shape[0]; i++) {
                data[i] = new F[shape[1]];
                for (I j = 0; j < shape[1]; j++)
                    this->data[i][j] = rhs.data[i][j];
            }
        }

        Matrix(const std::initializer_list<std::initializer_list<F>>& l)
        {
            shape[0] = l.size();
            shape[1] = l.begin()->size();

            data = new F*[shape[0]];
            I i = 0;
            for (auto& row : l) {
                data[i] = new F[shape[1]];
                I j = 0;
                for (auto& val : row) {
                    data[i][j] = val;
                    j++;
                }
                i++;
            }
        }

        /*
     *
     * Notes
     * -----
     *  填充矩阵的对角线元素, 为一固定的值 val.
     *
     *  目前假设矩阵是方阵
     *
     */
        void fill_diag(const F val, const I diag = 0)
        {
            I i = 0;
            I j = 0;

            if (diag >= 0) {
                j = diag;
                for (; j < shape[1]; i++, j++) {
                    data[i][j] = val;
                }
            } else {
                i = std::abs(diag);
                for (; i < shape[0]; i++, j++) {
                    data[i][j] = val;
                }
            }
        }

        void fill_diag(const F val[], const I diag = 0)
        {
            I i = 0;
            I j = 0;

            if (diag >= 0) {
                j = diag;
                for (; j < shape[1]; i++, j++) {
                    data[i][j] = val[i];
                }
            } else {
                i = std::abs(diag);
                for (; i < shape[0]; i++, j++) {
                    data[i][j] = val[i];
                }
            }
        }

        ~Matrix()
        {
            //std::cout<<"析构函数调用"<<std::endl;
            for (int i = 0; i < shape[0]; i++) {
                if (data[i] != nullptr) {
                    delete[] data[i];
                    data[i] = nullptr;
                }
            }
            if (data != nullptr) {
                delete[] data;
                data = nullptr;
            }
        }

        F& operator()(const I i, const I j)
        {
            return data[i][j];
        }

        const F& operator()(const I i, const I j) const
        {
            return data[i][j];
        }

        F* operator[](const I i)
        {
            return data[i];
        }

        const F* operator[](const I i) const
        {
            return data[i];
        }

        Matrix<F, I>& transpose()
        {
            //std::cout<<"转置函数调用"<<std::endl;
            I row = shape[0];
            I col = shape[1];
            F arr[row][col] = { 0 };
            for (I i = 0; i < row; i++) {
                for (I j = 0; j < col; j++)
                    arr[i][j] = this->data[i][j];
            }

            if (data != NULL) {
                delete[] data;
                data = NULL;
                shape[0] = 0;
                shape[1] = 0;
            }
            shape[0] = col;
            shape[1] = row;

            data = new F*[shape[0]];
            for (I i = 0; i < shape[0]; i++) {
                data[i] = new F[shape[1]];
                for (I j = 0; j < shape[1]; j++)
                    data[i][j] = arr[j][i];
            }
            return *this;
        }
    };

    //重载矩阵的乘法
    template <typename F, typename I>
    inline Matrix<F, I> operator*(const Matrix<F, I>& m0,
        const Matrix<F, I>& m1)
    {
        auto nr = m0.shape[0];
        auto nc = m1.shape[1];
        auto n = m0.shape[1];
        Matrix<F, I> c(nr, nc);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                for (auto k = 0; k < n; k++)
                    c[i][j] += m0[i][k] * m1[k][j];
            }
        }
        return c;
    }

    //重载矩阵的减法
    template <typename F, typename I>
    inline Matrix<F, I> operator-(const Matrix<F, I>& m0,
        const Matrix<F, I>& m1)
    {
        auto nr = m0.shape[0];
        auto nc = m0.shape[1];

        Matrix<F, I> c(nr, nc);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                c[i][j] = m0[i][j] - m1[i][j];
            }
        }
        return c;
    }

    //重载矩阵的加法
    template <typename F, typename I>
    inline Matrix<F, I> operator+(const Matrix<F, I>& m0,
        const Matrix<F, I>& m1)
    {
        auto nr = m0.shape[0];
        auto nc = m0.shape[1];

        Matrix<F, I> c(nr, nc);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                c[i][j] = m0[i][j] + m1[i][j];
            }
        }
        return c;
    }

    //重载矩阵的数乘，数在左边
    template <typename F, typename I>
    inline Matrix<F, I> operator*(const double& m0,
        const Matrix<F, I>& m1)
    {
        auto nr = m1.shape[0];
        auto nc = m1.shape[1];

        Matrix<F, I> c(nr, nc);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                c[i][j] = m0 * m1[i][j];
            }
        }
        return c;
    }

    //重载矩阵的数乘，数在右边
    template <typename F, typename I>
    inline Matrix<F, I> operator*(const Matrix<F, I>& m1,
        const double& m0)
    {
        auto nr = m1.shape[0];
        auto nc = m1.shape[1];

        Matrix<F, I> c(nr, nc);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                c[i][j] = m0 * m1[i][j];
            }
        }
        return c;
    }

    //重载矩阵乘向量
    template <typename F, typename I, typename Vector>
    inline Vector operator*(const Matrix<F, I>& m1,
        const Vector& v0)
    {
        auto nr = m1.shape[0];
        auto nc = v0.size;

        Vector c(nr);
        for (auto i = 0; i < nr; i++) {
            for (auto j = 0; j < nc; j++) {
                c[i] += m1[i][j] * v0[j];
            }
        }
        return c;
    }

    template <typename F, typename I>
    std::ostream& operator<<(std::ostream& os, const Matrix<F, I>& m)
    {
        std::cout << "Matrix(" << m.shape[0] << ","
                  << m.shape[1] << "):" << std::endl;
        for (I i = 0; i < m.shape[0]; i++) {
            for (I j = 0; j < m.shape[1]; j++) {
                os << m[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

} // end of namespace AlgebraObject

} // end of namespace PDECPP
#endif // end of Matrix_h
