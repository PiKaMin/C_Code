#include <stdio.h>
#include <math.h>
//3.
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

void PolynomialSum(int a)
{
	/*int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j <= i; j++)
		{
			
			sum += a * pow(10, j);
			
		}
	}
	printf("%d\n", sum);*/

	int lastRes = a;
	int sum = a;
	for (int i = 1; i < 5; i++)
	{
		int temp = lastRes * 10 + a;
		sum += temp;
		lastRes = temp;
	}
	printf("%d\n" , sum);
}
