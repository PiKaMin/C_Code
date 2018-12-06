#pragma once
#include <stdio.h>
//1.编写函数： 
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
unsigned int reverse_bit(unsigned int value)
{
	unsigned int reverseNum = 0;
	int j = 31;
	for (int i = 0; i < 32; i++ , j--)
	{
		int temp = (value >> i) & 1; //当前最后一位
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



//2.不使用（a + b） / 2这种方式，求两个数的平均值。
void PrintAverage(int a , int b)
{
	int temp = (a - b) / 2;
	int avg = temp + b;
	printf("平均数是%d" , avg);
}



//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//利用异或的特性:两个相同数异或等于0,一个数和 0 异或等于本身
void FindSingleNum()
{
	int arr[] = { 18, 6, 17, 17, 18  , 19 , 1 , 6 , 19 }; //一组数据
	int length = sizeof(arr) / sizeof(arr[0]);
	int res = arr[0];
	for (int i = 1; i < length; i++)
	{
		res = res ^ arr[i];
	}
	printf("出现一次的数字是 : %d\n", res);
}

//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//	student a am i
//	i ma a tneduts
//	i am a student
int MyLen(char* str)
{
	int len = 0;
	for (char* cur = str; *cur != '\0'; cur++)
	{
		len++;
	}
	return len;
}
void reverse_string(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}
void reverse(char* str)
{
	int len = MyLen(str);
	char* start = str;
	char* end = str + len - 1;
	reverse_string(start, end);

	char* cur = str;
	while (*cur)
	{
		char* st = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		reverse_string(st, cur);
		while (cur == ' ')
		{
			cur++;
		}
	}

}


