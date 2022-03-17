#include "algebra/Algebra_kernel.h"
#include <iostream>

using namespace std;

class Base {
    int m_a;
    int m_b;

public:
    Base()
    {
        m_a = 0;
        m_b = 0;
    }
    Base(int a, int b)
    {
        m_a = a;
        m_b = b;
    }
    virtual int add() const
    {
        return m_a + m_b;
    }
};

class Son : public Base {
    int m_c;

public:
    Son()
        : Base()
    {
        m_c = 0;
    }
    Son(int a, int b, int c)
        : Base(a, b)
    {
        m_c = c;
    }
    virtual int add() const;
};

int Son::add() const
{
    return Base::add() + m_c;
}

int main()
{
    Base b(3, 3);
    Son s(4, 4, 4);
    Base& b1 = s;
    cout << s.add() << endl;
    return 0;
}
