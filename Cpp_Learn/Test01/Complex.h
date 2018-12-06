#pragma once
#include <iostream>
using namespace std;
//Class 的两个经典分类,在设计类的时候要考虑需不需要指针(分配空间):
//1. Class without pointer member(s): Complex
//没有指针的类,一般不需要析构函数清理内存

//2. Class with pointer member(s): string

//参数传值 Vs 参数传引用(是否加const)
//对于传递参数,一般情况下优先考虑传递引用
//如果不希望函数改变参数(只使用),可以加上const

//返回值传值 Vs 返回值传引用(const)
//一般同样可以考虑传引用
//*一定不能返回局部变量的引用,如果要返回局部变量的值,一定要传值(局部变量在函数结束时销毁)


class Complex
{
public:

	Complex(double  r = 0, double i = 0) //构造函数,参数可以有默认值
		:re(r), im(i)                   //这一行是初始化列表,初始化!= 赋值
	{
		//re = r;
		//im = i;  这样写也没有问题,不过这个就不是初始化,而是赋值.所以尽量使用初始化
	}

	//Complex() {}  //这个构造函数有问题,因为上面那个构造函数有默认值,
					//如果在外面声明 Complex c() 就会让编译器分不清到底调用哪一个构造

	
	double GetRe() const { return re; }
	double GetIm() const { return im; }
	//在函数的 () 后 {} 前加const: 表示这个函数不会修改成员变量的内容
	//如果没有加const会出现的问题:
	//普通使用没有问题.
	//但是如果在外面定义 const Complex c(1 , 2) cout << c.GetRe();会报错
	//因为一个const对象调用非const函数有可能被修改,所以编译器要排除这种行为

	Complex& operator += (const Complex& r); // 重载 += 声明
	

	//friend 友元 可以直接像类内部的函数一样使用私有的成员
	
private:   // 所有数据的声明都应该在private下
	double re; // 实部
	double im; // 虚部
};



//重载 += 定义
inline Complex& Complex::operator+=(const Complex& r)
{
	this->re += r.re;
	this->im += r.im;
	return *this;
}



Complex operator + (const Complex& x) //取正数
{
	return x;
}


//重载 << ,使Complex可以被打印到屏幕上
ostream& operator << (ostream& os, const Complex& x)
{
	return os << "(" << x.GetRe() << "," << x.GetIm() << ")";
}



