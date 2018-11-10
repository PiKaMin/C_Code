#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.完成猜数字游戏。(1 ~ 100)

int GameInit()
{
	int choose = 0;
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("输入数字(1 or 2) : ");
	scanf("%d" , &choose);
	return choose;
}
void GameLoop()
{
	int guess = 0;                        //输入的数
	srand((unsigned int)time(0));        //设置随机数种子
	int randomNum = rand() % 100 + 1;   //生成一个 1~100的随机数

	for (int i = 1; i <= 10; i++)
	{
		printf("输入第%d次要猜的数 : " , i);
		scanf("%d", &guess);

		if (guess > randomNum)
		{
			printf("大了\n");
		}
		else if (guess < randomNum)
		{
			printf("小了\n");
		}
		else
		{
			printf("猜中了\n");
			return ;
		}
	}

	printf("十次都没有猜中\n");
}
void GuessNum()
{


	if (GameInit() == 1)  //开始游戏
	{
		
		GameLoop();
	}
	else                 //退出游戏
	{
		return;
	}
	

}
