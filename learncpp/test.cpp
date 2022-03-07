#include <iostream>
#include <string>

using namespace std;
class Person {
public:
    static int m_A;
};

int main()
{
    Person::m_A = 10;
    return 0;
}
