#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
#define RULER 3          //规则：当前规则3子棋
char g_board[ROW][COL];
int g_startCheck = 0;    //1.是否开始检查   2.已经下的棋数

//三子棋程序
//初始化棋盘，全部为空格
void InitBorad()
{
	srand((unsigned int)time(0));
	for(int row = 0 ; row < ROW ; row++)
		for (int col = 0; col < COL; col++)
		{
			g_board[row][col] = ' ';
		}
}


//打印棋盘边界
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

//玩家回合
static void PlayerRound()
{
	//输入行和列，并判断输入是否合法 row:[0 , ROW) col:[0 , COL) g_borad[row][col] == ' '
	int row;
	int col;
	while (1)
	{
		printf("输入行和列的坐标 (row col)\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW) continue;
		if (col < 0 || col >= COL) continue;
		if (g_board[row][col] != ' ') continue;

		g_board[row][col] = 'x';
		g_startCheck++;
		break;
	}
	//更新棋盘
	PrintBoard();

}

//电脑回合
static void ComputerRound()
{
	printf("电脑行动:\n");
	//使用rand()生成row和col g_borad[row][col] == ' '合法
	while (1)
	{
		int row = rand() % 3;
		int col = rand() % 3;
		if (g_board[row][col] != ' ') continue;
		g_board[row][col] = 'o';
		g_startCheck++;
		break;
	}
	//更新棋盘
	PrintBoard();
}

//检查游戏是否结束 1.检查行  2.检查列  3.检查斜线
static char CheckIsGameOver(char checkChar)
{
	
	//0. 棋盘上的棋不足检查规则，玩家下的棋大于等于3时开始检查
	if (g_startCheck < RULER * 2 - 1) return 'g';
	//1. 检查行
	for (int row = 0; row < ROW; row++)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2]
			&& g_board[row][0] != ' ')
		{
			return checkChar;
		}
	}
	
	//2. 检查列
	for (int col = 0; col < COL; col++)
	{
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col]
			&& g_board[0][col] != ' ')
		{
			return checkChar;
		}
	}
	//3. 检查斜线
	//g_board[0][0] == g_board[1][1] == g_board[2][2]
	//g_board[0][2] == g_board[1][1] == g_board[2][0]
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2] && g_board[0][0] != ' ')
		return checkChar;
	if (g_board[0][2] == g_board[1][1] && g_board[0][2] == g_board[2][0] && g_board[0][2] != ' ')
		return checkChar;
	//4. 检查和棋 ,上面条件都没有满足，说明还没有一方胜利
	//未下满棋盘且没有胜利返回 g  继续游戏
	//下满棋盘且没有胜利返回   p  平局
	if (g_startCheck < ROW * COL)  //没有下满,且没有胜利者
	{

		return 'g';
	}
	else                                 //下满且没有胜利者
	{
		return 'p';
	}

}

//游戏循环
void BoradGameLoop()
{
	char winner = 'g';//winner == g 还在游戏中继续循环
	printf("游戏开始 , 玩家先下\n");
	while (1)
	{
		//1. 玩家下棋
		PlayerRound();
		//2. 判断游戏是否结束
		winner = CheckIsGameOver('x');
		if (winner != 'g') break;     //满足结束条件
		//3. 电脑下棋
		ComputerRound();
		//4. 判断游戏是否结束
		winner = CheckIsGameOver('o');

		if (winner != 'g') break;
	}

	printf("游戏结束！！\n");
	
	//判断返回的 winner 的值来确定获胜者 
	// winner == 'x'    玩家获胜
	// winner == 'o'    电脑获胜
	// winner == 'p'    和棋
	if (winner == 'x')   printf("玩家获胜！！\n");
	else if (winner == 'o')   printf("电脑获胜！！\n");
	else if (winner == 'p')   printf("和棋，平局！\n");
	else printf("error : %d", winner);
}
