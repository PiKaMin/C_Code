#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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