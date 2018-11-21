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

}