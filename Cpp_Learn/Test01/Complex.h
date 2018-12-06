#pragma once
#include <iostream>
using namespace std;
//Class �������������,��������ʱ��Ҫ�����費��Ҫָ��(����ռ�):
//1. Class without pointer member(s): Complex
//û��ָ�����,һ�㲻��Ҫ�������������ڴ�

//2. Class with pointer member(s): string

//������ֵ Vs ����������(�Ƿ��const)
//���ڴ��ݲ���,һ����������ȿ��Ǵ�������
//�����ϣ�������ı����(ֻʹ��),���Լ���const

//����ֵ��ֵ Vs ����ֵ������(const)
//һ��ͬ�����Կ��Ǵ�����
//*һ�����ܷ��ؾֲ�����������,���Ҫ���ؾֲ�������ֵ,һ��Ҫ��ֵ(�ֲ������ں�������ʱ����)


class Complex
{
public:

	Complex(double  r = 0, double i = 0) //���캯��,����������Ĭ��ֵ
		:re(r), im(i)                   //��һ���ǳ�ʼ���б�,��ʼ��!= ��ֵ
	{
		//re = r;
		//im = i;  ����дҲû������,��������Ͳ��ǳ�ʼ��,���Ǹ�ֵ.���Ծ���ʹ�ó�ʼ��
	}

	//Complex() {}  //������캯��������,��Ϊ�����Ǹ����캯����Ĭ��ֵ,
					//������������� Complex c() �ͻ��ñ������ֲ��嵽�׵�����һ������

	
	double GetRe() const { return re; }
	double GetIm() const { return im; }
	//�ں����� () �� {} ǰ��const: ��ʾ������������޸ĳ�Ա����������
	//���û�м�const����ֵ�����:
	//��ͨʹ��û������.
	//������������涨�� const Complex c(1 , 2) cout << c.GetRe();�ᱨ��
	//��Ϊһ��const������÷�const�����п��ܱ��޸�,���Ա�����Ҫ�ų�������Ϊ

	Complex& operator += (const Complex& r); // ���� += ����
	

	//friend ��Ԫ ����ֱ�������ڲ��ĺ���һ��ʹ��˽�еĳ�Ա
	
private:   // �������ݵ�������Ӧ����private��
	double re; // ʵ��
	double im; // �鲿
};



//���� += ����
inline Complex& Complex::operator+=(const Complex& r)
{
	this->re += r.re;
	this->im += r.im;
	return *this;
}



Complex operator + (const Complex& x) //ȡ����
{
	return x;
}


//���� << ,ʹComplex���Ա���ӡ����Ļ��
ostream& operator << (ostream& os, const Complex& x)
{
	return os << "(" << x.GetRe() << "," << x.GetIm() << ")";
}



