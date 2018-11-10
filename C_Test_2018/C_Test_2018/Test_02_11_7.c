#include <stdio.h>

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
//Ҫ����  n ^ k  �ȼ���  n ^ (k - 1) * n
//.....
//���� n ^ 0 * ... * n * n
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