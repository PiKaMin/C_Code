#pragma once
#include <stdio.h>
//1.��д������ 
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
unsigned int reverse_bit(unsigned int value)
{
	unsigned int reverseNum = 0;
	int j = 31;
	for (int i = 0; i < 32; i++ , j--)
	{
		int temp = (value >> i) & 1; //��ǰ���һλ
		if (temp == 1)
		{
			reverseNum |= (1 << j); 
		}
		else
		{
			reverseNum &= ~(1 << j);
		}
		
	}
	return reverseNum;
}



//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
void PrintAverage(int a , int b)
{
	int temp = (a - b) / 2;
	int avg = temp + b;
	printf("ƽ������%d" , avg);
}



//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//������������:������ͬ��������0,һ������ 0 �����ڱ���
void FindSingleNum()
{
	int arr[] = { 18, 6, 17, 17, 18  , 19 , 1 , 6 , 19 }; //һ������
	int length = sizeof(arr) / sizeof(arr[0]);
	int res = arr[0];
	for (int i = 1; i < length; i++)
	{
		res = res ^ arr[i];
	}
	printf("����һ�ε������� : %d\n", res);
}

//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//	student a am i
//	i ma a tneduts
//	i am a student
