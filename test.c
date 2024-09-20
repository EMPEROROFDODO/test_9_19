#include "game.h"

//运行游戏
void game()
{
	//创建棋盘
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//Display(mine, ROW, COL);
	//设置地雷
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);
	//排查地雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
		int input = 0;
	do
	{
		//打印菜单
		meun();
		printf("请做出你的选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//运行游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}