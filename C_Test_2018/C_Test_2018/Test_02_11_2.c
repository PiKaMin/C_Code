#include <stdio.h>

//2.д����������������������в�����Ҫ�����֣� 
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

//int* arr : �������� 
//int len  : ���鳤��
//int num  : ��������
int BinSearch(int* arr , int len , int num)
{
	int left = 0;           //����������±�
	int right = len - 1;    //�������ұ��±�
	int mid = 0;            //�����м��±�

	while (left <= right)
	{
		mid = (left + right) / 2; //���м��±�


		if (arr[mid] > num)
		{
			right = mid - 1;  //��С��Χ
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;  //��С��Χ
		}
		else
		{
			return mid;      //�鵽
		} 
	}
	return -1;
}