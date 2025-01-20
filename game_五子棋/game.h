#pragma once

#define ROW 15 //预定义行
#define COL 15 //预定义列
#define PIECE 5//预定义棋子获胜条件个数
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘

void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘

void PlayerMove(char board[ROW][COL], int row, int col);//玩家移动

void ComputerMove(char board[ROW][COL], int row, int col);//电脑移动

char IsWin(char board[ROW][COL], int row, int col);//判断胜利

