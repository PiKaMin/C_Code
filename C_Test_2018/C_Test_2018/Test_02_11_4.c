#include <stdio.h>
 //2.使用函数实现两个数的交换。
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}