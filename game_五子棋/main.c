#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void menu() // 提供菜单页面
{
    printf("***************************\n");
    printf("** 1.play - 开始单人游戏 **\n");
    printf("** 2.play - 开始双人游戏 **\n");
    printf("** 0.exit - 退出程序 ******\n");
    printf("***************************\n");
}
void game()
{
    int ret = 0;
    char Board[ROW][COL] = { 0 };
    //初始化棋盘
    InitBoard(Board, ROW, COL);
    //打印棋盘
   DisplayBoard(Board, ROW, COL);
    while (1)
    {
        //玩家下棋
		printf("玩家(*)落子\n");
        PlayerMove(Board, ROW, COL);
        //判断输赢
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //打印棋盘
       DisplayBoard(Board, ROW, COL);
        //电脑下棋
       printf("电脑(#)落子:>\n");
        ComputerMove(Board, ROW, COL);
        //判断输赢
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //打印棋盘
        DisplayBoard(Board, ROW, COL);
    }
    if (ret == '*')
    {
        printf("玩家赢\n");
    }
    else if (ret == '#')
        printf("电脑赢\n");
    else
        printf("平局\n");
    DisplayBoard(Board, ROW, COL);
}

void game_two_player()
{
    int ret = 0;
    char Board[ROW][COL] = { 0 };
    //初始化棋盘
    InitBoard(Board, ROW, COL);
    //打印棋盘
    DisplayBoard(Board, ROW, COL);
    while (1)
    {
        //玩家1下棋
		printf("玩家1(*)下棋\n");
        PlayerMove(Board, ROW, COL);
        //判断输赢
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //打印棋盘
        DisplayBoard(Board, ROW, COL);
		printf("玩家2(#)下棋\n");
        //玩家2下棋
        Player2Move(Board, ROW, COL);
        //判断输赢
        ret = IsWin(Board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //打印棋盘
        DisplayBoard(Board, ROW, COL);
    }
    if (ret == '*')
    {
        printf("玩家1赢\n");
    }
    else if (ret == '#')
        printf("玩家2赢\n");
    else
        printf("平局\n");
    DisplayBoard(Board, ROW, COL);
}
int main()
{
    srand((unsigned)time(NULL));//使用时间戳，使随机数开头随机
    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //开始单人游戏
            printf("五子棋\n");
            game();
            break;
		case 2:
			//开始双人游戏
			printf("五子棋\n");
			game_two_player();
			break;
        case 0:
            //退出程序
            printf("按回车键退出程序\n");
            getchar();
            getchar();
            exit(0);
            break;
        default:
            //错误处理
            printf("输入错误，请重新输入:>\n");
            break;
        }
    } while (input);
    return 0;
}