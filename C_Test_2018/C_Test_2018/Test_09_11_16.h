#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_ROW 10                 //地图行数
#define MAP_COL 10                 //地图列数
#define DEFAULT_MINE_COUNT 10      //默认地雷数
#define DEFAULT_JUDGE_GRID 4       //默认判断周围 4 个格子

//2018 / 11 /16 扫雷游戏

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
	//打印菜单  读取用户输入
	//输入 1 开始游戏  输入 0 退出游戏
	printf("**************************************\n");
	printf("***************扫雷游戏***************\n\n");
	printf("              0.退出游戏              \n\n");
	printf("              1.开始游戏              \n\n");
	printf("**************************************\n");
	printf("输入(0或1)选择:");
	int chioce;
	scanf("%d" , &chioce);

	return chioce;
}

//扫雷游戏资源初始化
static void MineSweeperInit(char showMap[MAP_ROW + 2][MAP_COL + 2] , char mineMap[MAP_ROW + 2][MAP_COL + 2])
{
	//初始化显示用的地图,默认全部初始化为 * 
	for (int row = 1; row < MAP_ROW + 1; row++)
	{
		for (int col = 1; col < MAP_COL + 1; col++)
		{
			showMap[row][col] = '*';
		}
	}

	//初始化地雷位置,使用随机数生成地雷位置,先全部初始化为 '0' ,地雷初始化为 '1'  不是地雷初始化为 '0'
	for (int row = 0; row < MAP_ROW + 2; row++)
	{
		for (int col = 0; col < MAP_COL + 2; col++)
		{
			mineMap[row][col] = '0';
		}
	}

	//初始化地雷,将生成的地雷位置的 '0' 改为 '1' 
	srand((unsigned int)time(0));  //初始化随机数种子 , 随机生成地雷位置

	//利用 rand 函数生成随机数为地雷位置  row[1 , 10]  col[1 , 10] 
	int row;
	int col;
	int placeMineCount = 0;  // 成功放置的地雷个数

	while (1)
	{
		row = (rand() % 10) + 1;
		col = (rand() % 10) + 1;
		if (mineMap[row][col] == '1')  //这个位置已经有地雷了
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

//打印  显示地图 或 地雷地图
static void MineSweeperMapPrint(char map[MAP_ROW + 2][MAP_ROW + 2])
{
	//打印列标号
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


	//打印地图
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

//检测用户输入合法性
static int CheckUserInput(char showMap[MAP_ROW + 2][MAP_COL + 2] , int row , int col)
{
	//检测用户输入坐标的合法性  row[1 , 10]   col[1 , 10]  showMap[row][col] == *
	if ((row >= 1 && row <= 10)
		&& (col >= 1 && col <= 10)
		&& (showMap[row][col] == '*'))
	{
		return 1;
	}

	return 0;
}


//计算 showMap[row][col]周围8个格子的地雷数量
//,并显示在 showMap[row][col]格子上
//Todo: 打开周围不是地雷的格子
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

	if (mineCount > 0 && !oneDO) return;    //oneDo 不是第一次打开(当前函数在递归中),说明递归
											//到达了一个边界,退出这次递归

	else
	{
		for (int i = 0; i < DEFAULT_JUDGE_GRID; i++)
		{
			UpdateShowMap(showMap, mineMap, row + g_dir_row[i], col + g_dir_col[i] , 0);
		}
	}
	
}
//扫雷游戏主循环
static int MineSweeperGameLoop(char showMap[MAP_ROW + 2][MAP_COL + 2] 
	, char mineMap[MAP_ROW + 2][MAP_COL + 2])
{
	//1. 循环读取用户输入坐标 , 直到游戏结束
	
	int row, col;
	while (1)
	{
		int c;
		
		printf("输入要打开的 * 坐标 (row col) : ");
		scanf("%d %d" , &row , &col);
		while ((c = getchar()) != EOF && c != '\n')
			;
		//检测用户输入坐标的合法性  row[1 , 10]   col[1 , 10]  showMap[row][col] == *
		if (!CheckUserInput(showMap , row , col))
		{
			
			//输入不合法
			printf("输入不合法 , 重新输入\n");
			continue;
		}

		
		
		//打开了一个 * ,判断是否是 地雷 , 是 地雷 游戏结束
		if (mineMap[row][col] == '1')
		{
			showMap[row][col] = 'M';
			return 0;   //游戏结束
		}

		//没有扫到地雷,游戏继续 , 打开这个 * , 并检查周围 8 个格子的地雷数量,显示到这个格子上
		//打开周围没有地雷的格子,更新showMap信息
		UpdateShowMap(showMap, mineMap, row, col ,1);

		//点开了所有的格子
		if (g_success_count == MAP_COL * MAP_ROW - DEFAULT_MINE_COUNT)
		{
			return 1;
		}

		//没有点到地雷,也没有开完所有的格子,刷新一下地图,进入下一次循环
		system("cls");
		MineSweeperMapPrint(showMap);
		MineSweeperMapPrint(mineMap); //TODO : 打印地雷地图,测试用  
		//printf("%d\n", g_success_count);
	}
}

//合并地图,用于最终显示
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
//扫雷游戏主函数
void MineSweeper()
{
	//-1.用到的一些变量
	char showMap[MAP_ROW + 2][MAP_COL + 2];    //显示的地图,加一圈边框
	char mineMap[MAP_ROW + 2][MAP_COL + 2];    //生成的地雷地图,用来和判断是否是地雷,加了一圈边框
	//0.打印菜单
	if (!PrintMineSweeperMenu())
	{  
		printf("游戏退出\n");     //用户输入为 0 退出游戏 
		return;
	}
	//1.初始化游戏
	MineSweeperInit(showMap , mineMap);

	//2.打印扫雷区域
	MineSweeperMapPrint(showMap);
	MineSweeperMapPrint(mineMap);
	


	
	// 3.游戏主循环
		//3.1 用户输入
			//3.1.1 判定输入合法性
		//3.2 判定胜利 (失败条件: 点到地雷   胜利条件: 打开所有不是地雷的地方)

	int gameStatus = MineSweeperGameLoop(showMap , mineMap);

	
	//4. 游戏结束,打印地雷地图 gameStatus == 0 扫到雷,游戏失败 gameStatus == 1 扫完一局游戏胜利
	system("cls");

	if (gameStatus)
	{
		printf("游戏胜利!!!\n");
	}
	else
	{
		printf("游戏结束,游戏失败!!!\n");
	}

	//合并并打印地图
	MergeMap(showMap , mineMap);
	MineSweeperMapPrint(showMap);
	MineSweeperMapPrint(mineMap);
}