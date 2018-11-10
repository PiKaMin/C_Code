#include <stdio.h>

//2.写代码可以在整型有序数组中查找想要的数字， 
//找到了返回下标，找不到返回 - 1.（折半查找）

//int* arr : 待查数组 
//int len  : 数组长度
//int num  : 待查数字
int BinSearch(int* arr , int len , int num)
{
	int left = 0;           //数组最左边下标
	int right = len - 1;    //数组最右边下标
	int mid = 0;            //数组中间下标

	while (left <= right)
	{
		mid = (left + right) / 2; //求中间下标


		if (arr[mid] > num)
		{
			right = mid - 1;  //缩小范围
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;  //缩小范围
		}
		else
		{
			return mid;      //查到
		} 
	}
	return -1;
}