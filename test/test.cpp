#include <iostream>
#include "algebra/Vector.h"
using namespace std;
using namespace PDECPP::AlgebraObject;
int main()
{
   using F = double;
   using I = int;
   int size = 5,val = 2;
   Vector<F,I> v(size);
   Vector<F,I> v1(size,val);
   Vector<F,I> v2 = {1,2,3,4,5};
   cout<<val*v<<endl;
   v1 = v2;
   cout<<v1[2]<<endl;
   cout<<(v2*val)[2]<<endl;
   cout<<v2*v1[2]<<endl;
   return 0;
}