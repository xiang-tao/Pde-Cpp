#include <iostream>
#include <fstream>
#include "thirdparty/matplotlibcpp.h"
#include "algebra/Algebra_kernel.h"
using namespace std;
namespace plt = matplotlibcpp;

int main()
{
   int n = 100;
   double m;
   double h = 2.0/n;
   Matrix A(n+1,n+1);
   A.fill_diag(2);
   A.fill_diag(-1,-1);
   A.fill_diag(-1,1);
   Vector b(n+1);
   Vector x(n+1);//数值解数据
   Vector x1(n+1);//保留横坐标数据
   Vector x2(n+1);//真实解数据
   x1[0] = -1;
   x1[n] = 1;
   //两个边界点已知，故不再计算，因此循环n-1次，本来是循环n+1次
   for(int i=0;i<n+1;i++)
   {
      m = i*h-1;
      x1[i] = m;
      b[i] = h*h*(4*pow(m,4)-14*m*m+4)*pow(2.718,-m*m);
      x2[i] = pow(2.718,-m*m)*(1-m*m);
   }
   jacobi(A, b, x);

   ofstream ofs;
   ofs.open("data.dat", ios::out);
   ofs<<"x"<<" "<<"y1"<<endl;
   for(int i=0; i<n+1;i++)
   {
      ofs<<x1[i]<<" "<<x[i]<<endl;
   }
   ofs.close();

   ofstream ofs1;
	ofs1.open("data1.dat", ios::out);
   ofs1<<"x"<<" "<<"y2"<<endl;
   for(int i=0; i<n+1;i++)
   {
      ofs1<<x1[i]<<" "<<x2[i]<<endl;
   }
   ofs1.close();

   //vector<double> xx(n+1),xx1(n+1),xx2(n+1);
   vector<double> xx,xx1,xx2;
   for(int i=0;i<n+1;i++)
   {
      // xx[i] = x[i];
      // xx1[i] = x1[i];
      // xx2[i] = x2[i];
      xx.push_back(x[i]);
      xx1.push_back(x1[i]);
      xx2.push_back(x2[i]);
      // if(i%20==0)
      // {
      //    plt::clf();
      //    plt::title("n=20");  //加标题
      //    //plt::xlabel("Iteration steps");//加横坐标标签
      //    //plt::ylabel("Error norm");//加纵坐标标签
      //    plt::named_plot("Jacobi",xx1, xx);
      //    plt::xlim(-1, 1);
      //    plt::ylim(0, 1);
      //    //plt::named_plot("GS",xx1, xx2, "g--");
      //    plt::legend();
      //    plt::pause(0.1);
      // }
   }

   plt::title("n=20");  //加标题
   plt::xlabel("Iteration steps");//加横坐标标签
   plt::ylabel("Error norm");//加纵坐标标签
   plt::named_plot("Jacobi",xx1, xx, "r-");
   plt::named_plot("GS",xx1, xx2, "g--");
   plt::legend();
   //plt::save("test.gif");
   plt::show();

   return 0;
}
