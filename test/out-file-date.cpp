#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    int n = 20;
    //double a[3][3] = {{12.52894756541,2.3265944,0.256554},
      //              {2.326594,-4.26587,2.336658},
        //            {-123.26548791,5.26687,124.69865748}};
    ofstream ofs;
    ofs.open("test.dat",ios::out);
    //ofs<<"x\t"<<"y\t"<<"z\t"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ofs<<setw(20)<<setprecision(16)<<fixed<<i/double(n)<<"  ";
            ofs<<setw(20)<<setprecision(16)<<fixed<<j/double(n)<<"  ";
            ofs<<setw(20)<<setprecision(16)<<fixed<<double(i)*0.11<<"  ";
            ofs<<endl;
        }
    }
    ofs.close();
    return 0;
}
