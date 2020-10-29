#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#define clrscr() system("cls")

using namespace std;

void application();
void brinks();
void game();
void help();
void _search();
void settings();
void close();
void gotoxy(int x, int y)
{
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;
void application()
{
clrscr();


}

int main()
{

   return 0;
}
