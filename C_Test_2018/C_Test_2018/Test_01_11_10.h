#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
#define RULER 3          //���򣺵�ǰ����3����
char g_board[ROW][COL];
int g_startCheck = 0;    //1.�Ƿ�ʼ���   2.�Ѿ��µ�����

//���������
//��ʼ�����̣�ȫ��Ϊ�ո�
void InitBorad()
{
	srand((unsigned int)time(0));
	for(int row = 0 ; row < ROW ; row++)
		for (int col = 0; col < COL; col++)
		{
			g_board[row][col] = ' ';
		}
}


//��ӡ���̱߽�
void PrintBoard()
{
	printf("|---|---|---|\n");
	for (int row = 0; row < ROW; row++)
	{
		
		printf("| %c | %c | %c |\n" , g_board[row][0] , g_board[row][1] , g_board[row][2]);
		if (row >= 0 && row < ROW - 1)
		{
			printf("|---|---|---|\n");
		}
	}
	printf("|---|---|---|\n");
}

//��һغ�
static void PlayerRound()
{
	//�����к��У����ж������Ƿ�Ϸ� row:[0 , ROW) col:[0 , COL) g_borad[row][col] == ' '
	int row;
	int col;
	while (1)
	{
		printf("�����к��е����� (row col)\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW) continue;
		if (col < 0 || col >= COL) continue;
		if (g_board[row][col] != ' ') continue;

		g_board[row][col] = 'x';
		g_startCheck++;
		break;
	}
	//��������
	PrintBoard();

}

//���Իغ�
static void ComputerRound()
{
	printf("�����ж�:\n");
	//ʹ��rand()����row��col g_borad[row][col] == ' '�Ϸ�
	while (1)
	{
		int row = rand() % 3;
		int col = rand() % 3;
		if (g_board[row][col] != ' ') continue;
		g_board[row][col] = 'o';
		g_startCheck++;
		break;
	}
	//��������
	PrintBoard();
}

//�����Ϸ�Ƿ���� 1.�����  2.�����  3.���б��
static char CheckIsGameOver(char checkChar)
{
	
	//0. �����ϵ��岻�����������µ�����ڵ���3ʱ��ʼ���
	if (g_startCheck < RULER * 2 - 1) return 'g';
	//1. �����
	for (int row = 0; row < ROW; row++)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ')
		{
			return checkChar;
		}
	}
	
	//2. �����
	for (int col = 0; col < COL; col++)
	{
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return checkChar;
		}
	}
	//3. ���б��
	//g_board[0][0] == g_board[1][1] == g_board[2][2]
	//g_board[0][2] == g_board[1][1] == g_board[2][0]
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2] && g_board[0][0] != ' ')
		return checkChar;
	if (g_board[0][2] == g_board[1][1] && g_board[0][2] == g_board[2][0] && g_board[0][2] != ' ')
		return checkChar;
	//4. ������ ,����������û�����㣬˵����û��һ��ʤ��
	//δ����������û��ʤ������ g  ������Ϸ
	//����������û��ʤ������   p  ƽ��
	if (g_startCheck < ROW * COL)  //û������,��û��ʤ����
	{

		return 'g';
	}
	else                                 //������û��ʤ����
	{
		return 'p';
	}

}

//��Ϸѭ��
void BoradGameLoop()
{
	char winner = 'g';//winner == g ������Ϸ�м���ѭ��
	printf("��Ϸ��ʼ , �������\n");
	while (1)
	{
		//1. �������
		PlayerRound();
		//2. �ж���Ϸ�Ƿ����
		winner = CheckIsGameOver('x');
		if (winner != 'g') break;     //�����������
		//3. ��������
		ComputerRound();
		//4. �ж���Ϸ�Ƿ����
		winner = CheckIsGameOver('o');

		if (winner != 'g') break;
	}

	printf("��Ϸ��������\n");
	
	//�жϷ��ص� winner ��ֵ��ȷ����ʤ�� 
	// winner == 'x'    ��һ�ʤ
	// winner == 'o'    ���Ի�ʤ
	// winner == 'p'    ����
	if (winner == 'x')   printf("��һ�ʤ����\n");
	else if (winner == 'o')   printf("���Ի�ʤ����\n");
	else if (winner == 'p')   printf("���壬ƽ�֣�\n");
	else printf("error : %d", winner);
}
