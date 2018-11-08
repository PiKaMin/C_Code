#include <stdio.h>
#include "SeqList.h"
#include <stdlib.h>

int main()
{
	SeqList seqList;
	SeqListInit(&seqList);
	SeqListPushBack(&seqList, 10);
	SeqListPushBack(&seqList, 20);
	SeqListPushBack(&seqList, 30);
	SeqListPushBack(&seqList, 40);
	SeqListPushBack(&seqList, 50);
	SeqListPushBack(&seqList, 50);
	SeqListPushBack(&seqList, 50);
	SeqListPushBack(&seqList, 50);
	SeqListPushBack(&seqList, 80);
	SeqListPushBack(&seqList, 90);

	//SeqListDestory(&seqList);  销毁
	//SeqListPushFront(&seqList, 100); 头插
	//SeqListInsert(&seqList, 0, 100);
	//SeqListInsert(&seqList, 2, 100); 中间插入 
	//SeqListInsert(&seqList, 4, 100);

	//SeqListPopBack(&seqList);
	//SeqListPopFront(&seqList);
	//SeqListErase(&seqList, 4);

	SeqListPrint(&seqList);

	SeqListRemoveAll(&seqList , 50);

	SeqListPrint(&seqList);

	system("pause");
	return 0;
	
}