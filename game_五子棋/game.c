#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		if(i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

//'*'代表玩家(1)
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标(样式:x y):>");
	while(1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row  && y >= 1 && y <= col)//判断输入坐标是否合法
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else if (board[x - 1][y - 1] == '#')//判断坐标是否占用另一玩家已经下过的地方
			{
				printf("占用另一玩家空格，坐标非法，请重新输入:>");
			}
			else if (board[x - 1][y - 1] == '*')//判断玩家是否占用自己已经下过的地方
			{
				printf("占用自己下过的地方，请重新输入:>");
			}
		}
		else
			printf("坐标超出范围，请重新输入:>");
	}
}

//双人对战时，'*'代表玩家2
void Player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标(样式:x y):>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入坐标是否合法
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else if (board[x - 1][y - 1] == '*')//判断坐标是否占用另一玩家已经下过的地方
			{
				printf("占用另一玩家空格，坐标非法，请重新输入:>");
			}
			else if (board[x - 1][y - 1] == '#')//判断玩家是否占用自己已经下过的地方
			{
				printf("占用自己下过的地方，请重新输入:>");
			}
		}
		else
			printf("坐标超出范围，请重新输入:>");
	}
}

//单人对战时，'#'代表电脑
//简单人机，落子位置随机
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;//0~2
        if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//填满返回1
//未填满返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断输赢
//玩家(1)赢 - '*'
//电脑(玩家2)赢 - '#'
//平局 - 'Q'
//继续 - 'C'
char IsWin(char board[ROW][COL], int row, int col)
{
	//行
	int i;
	int j;
	int count;
	for (i = 0; i < row; i++)
	{
		count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
			{
				count++;
				if (count == PIECE - 1)
					return board[i][j];
			}
		}
	}
	//列
	for (i = 0; i < row; i++)
	{
		count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j][i] != ' ')
			{
				count++;
				if (count == PIECE - 1)
					return board[j][i];
			}
		}
	}
	//对角线1: 从左上到右下
	count = 0;
	for (i = 0; i < row - 1; i++)
	{
		if(board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ')
		{ 
			count++;
			if(count == PIECE - 1)
				return board[i][i];
		}
	}
	//对角线2: 从右上到左下
	count = 0;
	for (i = 0; i < row - 1; i++)
	{
		if (board[i][row - 1 - i] == board[i + 1][row -2 - i] && board[i][row - 1 - i] != ' ')
		{
			count++;
			if (count == PIECE - 1)
                return board[i][row - 1 - i];
		}
	}
	//判断是否平局
	if (IsFull(board, row, col))
		return 'Q';

	return 'C';
}