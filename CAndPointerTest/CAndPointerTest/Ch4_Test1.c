#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//编程练习 4.1
//利用近似值求  正数n  的平方根
//计算过程：第一个近似值为1，接下来的近似值计算公式为：next = （now + （n / now）） / 2
//其中 next 下一项的近似值   now 当前的近似值。
//当某个近似值于前一个相等时，停止计算，所得结果就是要求的根。
void MySqrt()
{
	int n = 0;
	printf("输入一个正数：");
	scanf("%d" , &n);

	double nowNum = 1;
	double preNum = -1;
	

	while (nowNum != preNum)
	{
		preNum = nowNum;
		nowNum = (nowNum + (n / preNum)) / 2;
	}

	printf("结果为:%f\n" , nowNum);
}

//编程练习4.2 打印1~100的质数
void PrintPrime()
{
	int isPrime = 1;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break; 
			}
			isPrime = 1;
		}
		if (isPrime) printf("%d\n" , i);
		
	}
}