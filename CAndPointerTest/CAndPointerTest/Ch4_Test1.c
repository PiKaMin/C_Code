#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�����ϰ 4.1
//���ý���ֵ��  ����n  ��ƽ����
//������̣���һ������ֵΪ1���������Ľ���ֵ���㹫ʽΪ��next = ��now + ��n / now���� / 2
//���� next ��һ��Ľ���ֵ   now ��ǰ�Ľ���ֵ��
//��ĳ������ֵ��ǰһ�����ʱ��ֹͣ���㣬���ý������Ҫ��ĸ���
void MySqrt()
{
	int n = 0;
	printf("����һ��������");
	scanf("%d" , &n);

	double nowNum = 1;
	double preNum = -1;
	

	while (nowNum != preNum)
	{
		preNum = nowNum;
		nowNum = (nowNum + (n / preNum)) / 2;
	}

	printf("���Ϊ:%f\n" , nowNum);
}

//�����ϰ4.2 ��ӡ1~100������
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