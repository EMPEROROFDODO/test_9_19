#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

//引用头函数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义宏
#define ROW 9 
#define COL 9 
#define ROWS ROW+2 
#define COLS COL+2 
#define EASY_COUNT 10

//菜单
void meun();

//函数
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void Display(char board[ROWS][COLS], int row, int col);
//设置地雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//排查地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
