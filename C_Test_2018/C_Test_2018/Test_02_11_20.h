#pragma once
#include <stdio.h>

//
//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}

int count_one_bits(int value)
{
	int one_num = 0;
	for (int i = 0; i < 32; i++)    //32位数 
	{
		if ((value >> i) & 0x1)     //判断每一位是否为 1
		{
			one_num++;
		}
		
	}

	return one_num;
}

//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。

void GetBinaryEvenAndOddSeq(int num)
{
	printf("偶数位:");
	for (int i = 0; i < 32; i += 2)
	{
		printf("%d " , (num >> i) & 0x1);
	}
	printf("\n");

	printf("奇数位:");
	for (int i = 1; i < 32; i += 2)
	{
		printf("%d ", (num >> i) & 0x1);
	}
}

//3. 输出一个整数的每一位。
// 忽略输入 0 的情况    num != 0
void PrintNum(int num)
{
	if (num == 0)
		return;

	int tmp = num % 10;
	PrintNum(num / 10);
	if (tmp < 0) tmp = -tmp;
	printf("%d " , tmp);
}


//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7

void FindBitDifferent(int num1 , int num2)
{
	int differentCount = 0;
	//都是32位,所以循环32次
	for (int i = 0; i < 32; i++)
	{
		int temp1 = (num1 >> i) & 1; // num1当前的最后一位
		int temp2 = (num2 >> i) & 1;

		if (temp1 != temp2)
			++differentCount;

	}

	printf("有 %d 个bit位不一样", differentCount);
}