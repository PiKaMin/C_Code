#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_ROW 10                 //��ͼ����
#define MAP_COL 10                 //��ͼ����
#define DEFAULT_MINE_COUNT 10      //Ĭ�ϵ�����
#define DEFAULT_JUDGE_GRID 4       //Ĭ���ж���Χ 4 ������

//2018 / 11 /16 ɨ����Ϸ

enum Dir
{
	none  = 0  ,
	up    = -1 ,
	down  = 1  ,
	left  = -1 ,
	right = 1

};
//int g_dir_row[] = {-1 ,-1 , 0 , 1  , 1 , 1 , 0 , -1};
//int g_dir_col[] = {0 , -1 , -1 ,-1 , 0 , 1 , 1 , 1 };
int g_success_count = 0;
int g_dir_row[] = { up ,  none ,  down  , none };
int g_dir_col[] = { none , left ,  none , right };


static int PrintMineSweeperMenu()
{
	return 1;
	//��ӡ�˵�  ��ȡ�û�����
	//���� 1 ��ʼ��Ϸ  ���� 0 �˳���Ϸ
	printf("**************************************\n");
	printf("***************ɨ����Ϸ***************\n\n");
	printf("              0.�˳���Ϸ              \n\n");
	printf("              1.��ʼ��Ϸ              \n\n");
	printf("**************************************\n");
	printf("����(0��1)ѡ��:");
	int chioce;
	scanf("%d" , &chioce);

	return chioce;
}

//ɨ����Ϸ��Դ��ʼ��
static void MineSweeperInit(char showMap[MAP_ROW + 2][MAP_COL + 2] , char mineMap[MAP_ROW + 2][MAP_COL + 2])
{
	//��ʼ����ʾ�õĵ�ͼ,Ĭ��ȫ����ʼ��Ϊ * 
	for (int row = 1; row < MAP_ROW + 1; row++)
	{
		for (int col = 1; col < MAP_COL + 1; col++)
		{
			showMap[row][col] = '*';
		}
	}

	//��ʼ������λ��,ʹ����������ɵ���λ��,��ȫ����ʼ��Ϊ '0' ,���׳�ʼ��Ϊ '1'  ���ǵ��׳�ʼ��Ϊ '0'
	for (int row = 0; row < MAP_ROW + 2; row++)
	{
		for (int col = 0; col < MAP_COL + 2; col++)
		{
			mineMap[row][col] = '0';
		}
	}

	//��ʼ������,�����ɵĵ���λ�õ� '0' ��Ϊ '1' 
	srand((unsigned int)time(0));  //��ʼ����������� , ������ɵ���λ��

	//���� rand �������������Ϊ����λ��  row[1 , 10]  col[1 , 10] 
	int row;
	int col;
	int placeMineCount = 0;  // �ɹ����õĵ��׸���

	while (1)
	{
		row = (rand() % 10) + 1;
		col = (rand() % 10) + 1;
		if (mineMap[row][col] == '1')  //���λ���Ѿ��е�����
		{
			continue;
		}
		mineMap[row][col] = '1';
		placeMineCount++;
		if (placeMineCount == 10)
		{
			break;
		}
	}

}

//��ӡ  ��ʾ��ͼ �� ���׵�ͼ
static void MineSweeperMapPrint(char map[MAP_ROW + 2][MAP_ROW + 2])
{
	//��ӡ�б��
	printf("     ");
	for (int i = 1; i <= MAP_ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("     ");
	for (int i = 1; i <= MAP_ROW; i++)
	{
		printf("--");
	}
	printf("\n");


	//��ӡ��ͼ
	for (int row = 1; row < MAP_ROW + 1; row++)
	{
		printf("%02d | ", row);
		for (int col = 1; col < MAP_COL + 1; col++)
		{
			printf("%c " , map[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

//����û�����Ϸ���
static int CheckUserInput(char showMap[MAP_ROW + 2][MAP_COL + 2] , int row , int col)
{
	//����û���������ĺϷ���  row[1 , 10]   col[1 , 10]  showMap[row][col] == *
	if ((row >= 1 && row <= 10)
		&& (col >= 1 && col <= 10)
		&& (showMap[row][col] == '*'))
	{
		return 1;
	}

	return 0;
}


//���� showMap[row][col]��Χ8�����ӵĵ�������
//,����ʾ�� showMap[row][col]������
//Todo: ����Χ���ǵ��׵ĸ���
void UpdateShowMap(char showMap[MAP_ROW + 2][MAP_COL + 2]
	, char mineMap[MAP_ROW + 2][MAP_COL + 2], int row, int col , int oneDO)
{
	
	if (mineMap[row][col] == '1') return;
	if (showMap[row][col] != '*') return;
	if (row < 1 || row > MAP_ROW) return;
	if (col < 1 || col > MAP_COL) return;

	int mineCount = (mineMap[row - 1][col] - '0') +
		(mineMap[row - 1][col - 1] - '0') +
		(mineMap[row][col - 1] - '0') +
		(mineMap[row + 1][col - 1] - '0') +
		(mineMap[row + 1][col] - '0') +
		(mineMap[row + 1][col + 1] - '0') +
		(mineMap[row][col + 1] - '0') +
		(mineMap[row - 1][col + 1] - '0');
	showMap[row][col] = mineCount + '0';
	g_success_count++;

	if (mineCount > 0 && !oneDO) return;    //oneDo ���ǵ�һ�δ�(��ǰ�����ڵݹ���),˵���ݹ�
											//������һ���߽�,�˳���εݹ�

	else
	{
		for (int i = 0; i < DEFAULT_JUDGE_GRID; i++)
		{
			UpdateShowMap(showMap, mineMap, row + g_dir_row[i], col + g_dir_col[i] , 0);
		}
	}
	
}
//ɨ����Ϸ��ѭ��
static int MineSweeperGameLoop(char showMap[MAP_ROW + 2][MAP_COL + 2] 
	, char mineMap[MAP_ROW + 2][MAP_COL + 2])
{
	//1. ѭ����ȡ�û��������� , ֱ����Ϸ����
	
	int row, col;
	while (1)
	{
		int c;
		
		printf("����Ҫ�򿪵� * ���� (row col) : ");
		scanf("%d %d" , &row , &col);
		while ((c = getchar()) != EOF && c != '\n')
			;
		//����û���������ĺϷ���  row[1 , 10]   col[1 , 10]  showMap[row][col] == *
		if (!CheckUserInput(showMap , row , col))
		{
			
			//���벻�Ϸ�
			printf("���벻�Ϸ� , ��������\n");
			continue;
		}

		
		
		//����һ�� * ,�ж��Ƿ��� ���� , �� ���� ��Ϸ����
		if (mineMap[row][col] == '1')
		{
			showMap[row][col] = 'M';
			return 0;   //��Ϸ����
		}

		//û��ɨ������,��Ϸ���� , ����� * , �������Χ 8 �����ӵĵ�������,��ʾ�����������
		//����Χû�е��׵ĸ���,����showMap��Ϣ
		UpdateShowMap(showMap, mineMap, row, col ,1);

		//�㿪�����еĸ���
		if (g_success_count == MAP_COL * MAP_ROW - DEFAULT_MINE_COUNT)
		{
			return 1;
		}

		//û�е㵽����,Ҳû�п������еĸ���,ˢ��һ�µ�ͼ,������һ��ѭ��
		system("cls");
		MineSweeperMapPrint(showMap);
		MineSweeperMapPrint(mineMap); //TODO : ��ӡ���׵�ͼ,������  
		//printf("%d\n", g_success_count);
	}
}

//�ϲ���ͼ,����������ʾ
void MergeMap(char showMap[MAP_ROW + 2][MAP_COL + 2], char mineMap[MAP_ROW + 2][MAP_COL + 2])
{
	for (int row = 1; row < MAP_ROW + 1; row++)
	{
		for (int col = 1; col < MAP_COL + 1; col++)
		{
			if (mineMap[row][col] == '1')
			{
				showMap[row][col] = 'M';
			}
		}
	}
}
//ɨ����Ϸ������
void MineSweeper()
{
	//-1.�õ���һЩ����
	char showMap[MAP_ROW + 2][MAP_COL + 2];    //��ʾ�ĵ�ͼ,��һȦ�߿�
	char mineMap[MAP_ROW + 2][MAP_COL + 2];    //���ɵĵ��׵�ͼ,�������ж��Ƿ��ǵ���,����һȦ�߿�
	//0.��ӡ�˵�
	if (!PrintMineSweeperMenu())
	{  
		printf("��Ϸ�˳�\n");     //�û�����Ϊ 0 �˳���Ϸ 
		return;
	}
	//1.��ʼ����Ϸ
	MineSweeperInit(showMap , mineMap);

	//2.��ӡɨ������
	MineSweeperMapPrint(showMap);
	MineSweeperMapPrint(mineMap);
	


	
	// 3.��Ϸ��ѭ��
		//3.1 �û�����
			//3.1.1 �ж�����Ϸ���
		//3.2 �ж�ʤ�� (ʧ������: �㵽����   ʤ������: �����в��ǵ��׵ĵط�)

	int gameStatus = MineSweeperGameLoop(showMap , mineMap);

	
	//4. ��Ϸ����,��ӡ���׵�ͼ gameStatus == 0 ɨ����,��Ϸʧ�� gameStatus == 1 ɨ��һ����Ϸʤ��
	system("cls");

	if (gameStatus)
	{
		printf("��Ϸʤ��!!!\n");
	}
	else
	{
		printf("��Ϸ����,��Ϸʧ��!!!\n");
	}

	//�ϲ�����ӡ��ͼ
	MergeMap(showMap , mineMap);
	MineSweeperMapPrint(showMap);
	MineSweeperMapPrint(mineMap);
}