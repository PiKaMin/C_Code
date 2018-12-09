#pragma once
//第二种典型的类 class with point
//这类 类在设计时,要考虑加上三大函数: 拷贝构造 , 拷贝赋值 , 析构函数

class MyString
{
public:
	MyString(const char* str = 0); //构造函数 传入一个字符指针

	MyString(const MyString& str); //拷贝构造 调用: MyString str1(str2),
	                               //传入一个MyString类型的对象
	MyString& operator=(const MyString& str); //拷贝赋值

	~MyString(); //析构函数
private:
	char* m_data; //这里不用数组的原因是数组必须指定大小,用指针更加灵活
};


