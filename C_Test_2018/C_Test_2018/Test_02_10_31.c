#include <stdio.h>

//2.求出100～999之间的所有“水仙花数”并输出。

void PrintNarcissisticNumber()
{
	for (int i = 100; i <= 999; i++)
	{
		int ge = i % 10;           //个位
		int shi = (i / 10) % 10;   //十位
 		int bai = i / 100;         //百位

		int temp = ge * ge * ge + shi * shi * shi + bai * bai * bai;
		if (i == temp)
		{
			printf("%d是水仙花数\n" , i);
		}
	}
}