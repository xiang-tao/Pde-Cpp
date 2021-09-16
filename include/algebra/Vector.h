#ifndef Vector_h
#define Vector_h
/*
此文件作用：创建一个数学中的向量，使用c++类和模板进行实现
*/
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath> 
#include <initializer_list>

namespace PDECPP {
namespace AlgebraObject {

template<typename F=double, typename I=int>
struct Vector 
{
    F * data; //管理向量中的数据
    I size; //控制向量的维度

    /*
     * 默认构造函数
     使用方式：Vector v;默认向量v为空。
     */
    Vector()
    {
        data = NULL;
        size = 0;
    }

    //有参构造函数，调用形式 Vector v(5,1);向量维度是5，初始化全为1.
    //若使用Vector v(5);则向量维度为5，初始化默认val = 0;
    Vector(I s, F val=0.0)
    {
        size = s;
        init(val);
    }

    //initializer_list目的是为了初始化更加的灵活方便，参见https://blog.csdn.net/fengxinlinux/article/details/72614874
    //初始化方式：vector v = { 1, 2, 3, 4 };
    Vector(const std::initializer_list<F> &l)
    {
        //std::cout<<"初始化列表调用"<<std::endl;
        size = l.size();
        data = new F[size];
        I i = 0;
        for(auto & val: l)
        {
            data[i] = val;
            i++;
        }
    }

    /*
    此处重载 = 的原因是防止调用赋值符号时候由于类自身的浅拷贝是将地址一并拷贝，
    所以析构函数会释放同一个内存多次，有了这个重载，不同对象拷贝时候属性的地址就不一样了，
    因此不会释放同一个内存多次。
    注意:当使用Vector v1 = v2;等价于Vector v1(v2),这并不会调用重载的“=”函数，
    而是在调用拷贝构造函数,使用
    Vector v;
    v = v1;此处才会调用重载的“=”函数
    */
    Vector<F,I>& operator = (const Vector<F, I> & rhs)
    {
        // constructassert( this->size == rhs.size );//判断维度是否一致，不一致的话报错并终止程序。	    
	    if(this->size != rhs.size)
	    {
            //注意此处需要改进，应该终止程序报错，若不满足上述条件
            //但就目前而言，先使用此方法。
	    	std::cout<<"维度不一致，不能赋值"<<std::endl;
	    	return *this;
	    }
        else
        {
            if(this != & rhs)
            {
                //copy_n来自于STL中的算法头文件algorithm
                std::copy_n(rhs.data, size, data);
            }
            return *this;
        }       
    }

    //同时我们还要重写拷贝构造函数，防止当用户使用p(a)，即p=a，但是此处不会调用上面的重载“=”
    //函数，而是调用系统的拷贝构造函数，系统的浅拷贝对于指针会带来内存泄露问题，
    //因此要自己重新写。使用方式Vector v = v1; or Vector v(v1);    
    Vector(const Vector &v)
    {
        std::cout<<"拷贝构造调用"<<std::endl;
    	this->size = v.size;
    	this->data = new F[this->size];
    	for(int i=0;i<this->size;i++)
    	{
    	     this->data[i] = v.data[i];
    	}
    }
    
    void init(F val=0.0)
    {
        data = new F[size];
        for(I i=0; i < size; i++)
            data[i] = val;
    }

    //析构函数，释放内存空间
    ~Vector()
    {
        if(data != NULL)
            delete [] data;
    }

    F & operator[](const I i) 
    {
        return data[i];
    }

    const F & operator[](const I i) const
    {
        return data[i];
    }

};

//下面是一些重载运算符的函数，之所以返回的不是引用，原因是返回的变量是一个函数
//临时变量，返回引用不能够返回临时变量。
//重载向量减法
template<typename F, typename I>
inline Vector<F, I> operator - (const Vector<F, I> & v0, 
        const Vector<F, I> & v1)
{
    Vector<F, I> r(v0.size);
    for(auto i=0; i < v0.size; i++)
    {
        r[i] = v0[i] - v1[i];
    }
    return r;
}

//重载向量加法
template<typename F, typename I>
inline Vector<F, I> operator + (const Vector<F, I> & v0, 
        const Vector<F, I> & v1)
{
    Vector<F, I> r(v0.size);
    for(auto i=0; i < v0.size; i++)
    {
        r[i] = v0[i] + v1[i];
    }
    return r;
}

//重载向量乘法，即数学中的点乘，对应相乘相加
template<typename F, typename I>
inline double operator * (const Vector<F, I> & v0, 
        const Vector<F, I> & v1)
{
    double r=0;
    for(auto i=0; i < v0.size; i++)
    {
        r += v0[i]*v1[i];
    }
    return r;
}

//重载数字与向量乘法，数字在左边
template<typename F, typename I>
inline Vector<F, I> operator * (const double & v0, 
        const Vector<F, I> & v1)
{
    Vector<F, I> r(v1.size);
    for(auto i=0; i < v1.size; i++)
    {
        r[i] = v0*v1[i];
    }
    return r;
}

//重载数字与向量乘法，数字在右边
template<typename F, typename I>
inline Vector<F, I> operator * ( const Vector<F, I> & v1,
                            const double & v0)
{
    Vector<F, I> r(v1.size);
    for(auto i=0; i < v1.size; i++)
    {
        r[i] = v0*v1[i];
    }
    return r;
}

//重载左移运算符，实现向量输出自由
template<typename F, typename I>
std::ostream& operator << (std::ostream & os, const Vector<F, I> & v)
{
    std::cout << "Vector("<< v.size <<")" << std::endl;

    for(I i = 0; i < v.size; i++)
    {
        os << v[i] << " ";
    }
    os << std::endl;
    return os;
}

} // end of namespace AlgebraObject

} // end of namespace PDECPP
#endif // end of Vector_h
