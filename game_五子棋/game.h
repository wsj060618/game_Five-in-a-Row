#pragma once

#define ROW 15 //Ԥ������
#define COL 15 //Ԥ������
#define PIECE 5//Ԥ�������ӻ�ʤ��������
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������

void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����

void PlayerMove(char board[ROW][COL], int row, int col);//����ƶ�

void Player2Move(char board[ROW][COL], int row, int col);//���2�ƶ�

void ComputerMove(char board[ROW][COL], int row, int col);//�����ƶ�

char IsWin(char board[ROW][COL], int row, int col);//�ж�ʤ��

