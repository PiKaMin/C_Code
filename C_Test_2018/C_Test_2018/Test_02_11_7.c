#include <stdio.h>

//2.编写一个函数实现n^k，使用递归实现
//要计算  n ^ k  先计算  n ^ (k - 1) * n
//.....
//计算 n ^ 0 * ... * n * n
double MyPow(int n, int k)
{
	if (k == 0)
		return 1;

	if (k > 0)
	{
		return MyPow(n, k - 1) * n;
	}
	else
	{	
		
		return MyPow(n, k + 1) * (double)(1.0 / n);
	}
		
}