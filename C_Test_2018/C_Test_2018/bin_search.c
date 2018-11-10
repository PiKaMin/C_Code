#include <stdio.h>

//题目：在一个有序数组中查找具体的某个数字n
//实现：折半查找算法

//返回值：n在数组中的下标，未找到返回-1
//参数：arr---待查数组   num---待查数字  len---数组长度
int BinarySearch(int* arr, int num , int len)
{
	int right = len - 1;
	int left = 0;
	int mid = 0;
	
	while (left <= right)
	{
		mid = (right + left) / 2                       ; 

		if (num > arr[mid])
		{
			left = mid + 1;
		}
		else if (num < arr[mid])
		{
			 right = mid - 1;
		}
		else
		{
			return mid; //找到了
		}
	}

	return -1; //没找到
}