#include <stdio.h>

//��Ŀ����һ�����������в��Ҿ����ĳ������n
//ʵ�֣��۰�����㷨

//����ֵ��n�������е��±꣬δ�ҵ�����-1
//������arr---��������   num---��������  len---���鳤��
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
			return mid; //�ҵ���
		}
	}

	return -1; //û�ҵ�
}