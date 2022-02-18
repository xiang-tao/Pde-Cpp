#ifndef linalg_h
#define linalg_h

namespace PDECPP {
namespace AlgebraAlgrithom {

template<typename Matrix, typename Vector>
void jacobi(const Matrix &A, const Vector &b, Vector &x,
                     int times = 5000, double tol = 1e-6)
{
   int size = x.size;
   int d;
   Vector x1(size);
   for(int i = 0; i < times;i++)
   {
      for(int j = 0;j<size;j++)
      {
         x1[j] = b[j];
         for(int k=0;k<size;k++)
         {
            if(k==j)
               d = A[j][j];
            else
               x1[j] -= A[j][k]*x[k];
         }
         x1[j] = x1[j]/d;
      }
      x = x1;
      auto err = b - A*x;
      auto err_norm = err.norm();
      if(err_norm < tol)
         break;
   }
}

}// end of PDECPP
}//end of AlgebraAlgrithom
#endif