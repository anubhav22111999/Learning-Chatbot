#include<conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
int MapW,MapH;
char Map[100][100]={
"########################################################",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                         @            #",
"#                                                      #",
"#                                                      #",
"########################################################"};
struct snakeBlock{
    int x,y;
};

void gotoxy(int x, int y)
{
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawMap(vector <snakeBlock>snake)
{
    MapH=0;
    system("cls");
    for (int i=0;Map[i][0];i++)
    {
        MapW=0;
        for (int j = 0 ;Map[i][j];j++)
        {
            MapW++;
            if (Map[i][j]!=' ')
            {
                gotoxy(j,i);
                cout<<Map[i][j];
            }
        }
        MapH++;
    }
    for (int i =0 ;i<snake.size();i++)
    {
        gotoxy(snake[i].x,snake[i].y);
        cout<<char (219);
    }
}

bool checkLose(int x, int y,vector <snakeBlock>&snake)
{
    if (Map[y][x]=='#')
        return true;
    if (snake.size()>3)
    {
        for (int i = 3;i<snake.size();i++)
            if (snake[i].x==x&&snake[i].y==y)
                return true;
    }
    if (Map[y][x]=='@')
    {
        Map[y][x]=' ';
        snakeBlock newSnake;
        newSnake.x=snake[snake.size()-1].x;
        newSnake.y=snake[snake.size()-1].y;
        snake.push_back(newSnake);
        int rx,ry;
        do{
            rx=rand()%MapW;
            ry=rand()%MapH;
        }while (checkLose(rx, ry,snake));
        Map[ry][rx]='@';
        drawMap(snake);
    }
    return false;
}

void snakeInit(int x,int y ,vector<snakeBlock> &snake)
{
    snakeBlock newSnake;
    newSnake.x=x;
    newSnake.y=y;
    snake.push_back(newSnake);
}

bool snakeMove(vector<snakeBlock>&snake,short dire[2])
{
    int oldx,oldy,x,y;
    gotoxy(snake[snake.size()-1].x,snake[snake.size()-1].y);
    cout<<" ";
    oldx=snake[0].x;
    oldy=snake[0].y;
    snake[0].x+=dire[0];
    snake[0].y+=dire[1];
    gotoxy(snake[0].x,snake[0].y);
    cout<<char(219);
    if (snake.size()>1)
    {
        for (int i = 1;i<snake.size();i++)
        {
            x=snake[i].x;
            y=snake[i].y;
            snake[i].x=oldx;
            snake[i].y=oldy;
            oldx=x;
            oldy=y;
        }
    }
    if (checkLose(snake[0].x,snake[0].y,snake))
        return true;
    return false;
}

int snake1()
{
    cout<<"\n \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t->press enter to play";
    getch();
    bool GameIsRunning=true;
    int GameSpeed=80;
    short dire[2]={0,1};
    vector<snakeBlock> snake;
    snakeInit(1,1,snake);
    drawMap(snake);
    while (GameIsRunning)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            if (dire[1]==0)
            {
                dire[1]=-1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (dire[1]==0)
            {
                dire[1]=1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=-1;
            }
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=1;
            }
        }
        if(snakeMove(snake,dire))
        {
          system("cls");
          cout<<"Game Over"<<endl;
          system("pause");
          return 0;
        }
        Sleep(GameSpeed);
    }
}

/*int main()
{
   int c;
    c=snake1();
    if(c==0)
    {
        return 0;
    }
}*/
