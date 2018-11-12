#include <stdio.h>

//第五章 示例程序 计数一个二进制数中1的个数:初级版本
int CountOneBits(unsigned int value)
{
	int ones = 0;

	for (ones = 0; value != 0; value >>= 1)   //每次右移一位
	{
		if (value % 2 != 0)
			ones += 1;         //如果不能整除说明二进制数最后一位为 1 
	}

	return ones;
}