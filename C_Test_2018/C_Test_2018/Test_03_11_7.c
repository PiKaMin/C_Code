#include <stdio.h>


//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

int  DigitSum(int n)
{

	if (n < 0)
	{
		printf("���벻�Ϸ�");
		return -1;
	}
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	return n % 10;
}
