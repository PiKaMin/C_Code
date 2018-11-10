#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序

//密码 ：123456
void Login()
{
	char pwd[1024] = "";

	for (int i = 0; i < 3; i++)
	{
		printf("输入密码 : ");
		scanf("%s", pwd);

		if (strcmp(pwd, "123456") == 0)
		{
			printf("登录成功！\n");
			return;
		}
	
		
	}
	printf("密码错误三次 , 退出程序\n");
}