#include <stdio.h>
 //2.ʹ�ú���ʵ���������Ľ�����
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}