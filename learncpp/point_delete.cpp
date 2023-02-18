// #include <NumCpp.hpp>
#include <iostream>
using namespace std;
#include <string>
int main()
{
    const int k = 4;
    int** data = new int*[k];
    for (int i = 0; i < k; i++) {
        data[i] = new int[k];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            data[i][j] = i;
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    int* p = data[1];
    cout << p[1] << endl;
    for (int i = 0; i < k; i++) {
        if (data[i] != nullptr) {
            delete[] data[i];
            data[i] = nullptr;
        }
    }
    delete[] data;

    // cout << p[1] << endl;
    // cout << data[10][1] << endl;
    return 0;
}
