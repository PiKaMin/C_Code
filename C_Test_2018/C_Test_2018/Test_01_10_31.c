#include <stdio.h>
//1.在屏幕上输出以下图案：
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
	int line = k; //层数
	int max  =  2 * k - 1;//最大一层星数

	for (int i = 1; i <= max; i++)
	{
		
		int virtualLine = (i > line) ? max - i + 1 : i; //虚拟行：当实际行数小于7 虚拟行 = 实际行
		                                                //        当实际行数大于7 虚拟行 = 实际行的对称行
		int star = (2 * virtualLine) - 1; // 每行星星的个数
		int count = (max - star) / 2;     // 每行空格的个数
		

	
		for (int j = 1; j <= (star + count); j++)
		{
			if (j <= count) //打印空格
			{
				printf(" ");
			}
			else           //打印星
			{
				printf("*");
			}
		}
		printf("\n");

	}
}