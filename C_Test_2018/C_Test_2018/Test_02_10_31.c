#include <stdio.h>

//2.���100��999֮������С�ˮ�ɻ������������

void PrintNarcissisticNumber()
{
	for (int i = 100; i <= 999; i++)
	{
		int ge = i % 10;           //��λ
		int shi = (i / 10) % 10;   //ʮλ
 		int bai = i / 100;         //��λ

		int temp = ge * ge * ge + shi * shi * shi + bai * bai * bai;
		if (i == temp)
		{
			printf("%d��ˮ�ɻ���\n" , i);
		}
	}
}