#include <stdio.h>
//1.����Ļ���������ͼ����
//      *       1
//     ***      3
//    *****     5
//   *******    7
//  *********   9
// ***********  11
//************* 13 
// ***********  11                
//  *********   9   
//   *******    7   
//    *****     5   
//     ***      3   
//      *       1   
//2018 10.31 
void PrintDiamond(int k)
{
	int line = k; //����
	int max  =  2 * k - 1;//���һ������

	for (int i = 1; i <= max; i++)
	{
		
		int virtualLine = (i > line) ? max - i + 1 : i; //�����У���ʵ������С��7 ������ = ʵ����
		                                                //        ��ʵ����������7 ������ = ʵ���еĶԳ���
		int star = (2 * virtualLine) - 1; // ÿ�����ǵĸ���
		int count = (max - star) / 2;     // ÿ�пո�ĸ���
		

	
		for (int j = 1; j <= (star + count); j++)
		{
			if (j <= count) //��ӡ�ո�
			{
				printf(" ");
			}
			else           //��ӡ��
			{
				printf("*");
			}
		}
		printf("\n");

	}
}