#include <iostream>
#include "algebra/Algebra_kernel.h"
using namespace std;

int main()
{  
   Matrix M(3,3,2);
   Matrix N = {{1,2,3},{4,5,6},{7,8,9}};
   Vector V = {1,2,3};
   cout<<N*V<<endl;
   //cout<<N.transpose()+M<<endl;
   return 0;
}