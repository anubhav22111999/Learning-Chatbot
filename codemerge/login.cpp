#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include<fstream>
#include<process.h>
#define clrscr() system("cls")

using namespace std;
bool l;
string username1,password1,sq1,ans1;
char fp,ch;

void input();

void gotoxy(int x, int y)
{
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class login
    {
    public:
    string dob,username,password,sq,ans;
    char sex;
    int age;

    void signup();
    int signin();
    void forgotpassword();
    void interphase();

    }o;

    void login ::signup()
    {
        cin.ignore();
        ofstream x;
        x.open("login.dat",ios::binary|ios::app);
        gotoxy(0,10);
        cout<<"USERNAME -> ";
        cout<<endl;
        gotoxy(0,12);
        cout<<"PASSWORD -> ";
        cout<<endl;
        gotoxy(0,14);
        cout<<"DATE OF BIRTH -> ";
        cout<<endl;
        gotoxy(0,16);
        cout<<"AGE -> ";
        cout<<endl;
        gotoxy(0,18);
        cout<<"SEX (M/F) -> ";
        cout<<endl;
        gotoxy(0,20);
        cout<<"SEQURITY QUESTION -> ";
        cout<<endl;
        gotoxy(0,22);
        cout<<"ANSWER -> ";

        fflush(stdin);
        gotoxy(13,10);
        getline(cin,o.username);
        fflush(stdin);
        gotoxy(13,12);
        getline(cin,o.password);
        fflush(stdin);
        gotoxy(17,14);
        getline(cin,o.dob);
        fflush(stdin);
        gotoxy(8,16);
        cin>>o.age;
        fflush(stdin);
        gotoxy(14,18);
        cin>>o.sex;
        fflush(stdin);
        gotoxy(22,20);
        getline(cin,o.sq);
        fflush(stdin);
        gotoxy(11,22);
        getline(cin,o.ans);
        fflush(stdin);
        cout<<endl;

        x.write((char*)&o,sizeof(o));
        x.close();
    }

    int login::signin()
    {
        ifstream x;
        x.open("login.dat",ios::binary);
        bool c;

        gotoxy(0,10);
        cout<<"USERNAME -> ";
        cout<<endl;
        gotoxy(0,12);
        cout<<"PASSWORD -> ";
        gotoxy(13,10);
        fflush(stdin);
        getline(cin,username1);
        gotoxy(13,12);
        fflush(stdin);
        getline(cin,password1);

        while(x.read((char*)&o,sizeof(o)))
           {

               if(username1==o.username)
               {
                   if(o.password==password1)
                   {
                       l="True";
                         return 1;
                   }
                   else{
                    gotoxy(0,16);
                    cout<<"Forgot Password (Y/N) -> ";
                    cin.get(fp);
                    if(fp=='Y'||fp=='y')
                        return 0;

                   }
               }
                 if(x.eof()){
                        gotoxy(0,14);
                        cout<<"Incorrect Username";
                        gotoxy(13,10);
                        getline(cin,username1);
                        x.seekg(0,ios::beg);
                   }
               }
           x.close();
    }

    void login::forgotpassword()
    {
         clrscr();
         int temp=0;
         ifstream x;
         x.open("login.dat",ios::binary);

         gotoxy(0,10);
         cout<<"USERNAME -> ";
         gotoxy(0,12);
         cout<<"NEW PASSWORD -> ";
         gotoxy(12,10);
         fflush(stdin);
         getline(cin,username1);


         while(x.read((char*)&o,sizeof(o)))
           {
               temp++;
               if(username1==o.username)
                {
                    gotoxy(0,14);
                    cout<<"SEQURITY QUESTION -> ";
                    gotoxy(22,14);
                    fflush(stdin);
                    cout<<o.sq;
                    gotoxy(0,16);
                    cout<<"ANSWER -> ";
                    fflush(stdin);
                    getline(cin,ans1);
                    if(o.ans==ans1)
                    {
                        gotoxy(17,12);
                        fflush(stdin);
                        getline(cin,o.password);
                    }

                   }

                 if(x.eof()){
                        gotoxy(0,18);
                        cout<<"Incorrect Username Please Enter Again";
                        gotoxy(12,10);
                        getline(cin,username1);
                        x.seekg(0,ios::beg);
                        temp==0;
                   }
               }
               x.close();

               ofstream y;
               y.open("login.dat",ios::binary);
               y.seekp(temp,ios::beg);
               y.write((char*)&o,sizeof(o));
               y.close();


    }

    void input()
    {

      gotoxy(75,20);
        cout<<"WELCOME";
        gotoxy(74,21);
        cout<<"---------";
        gotoxy(73,23);
        cout<<"1) SIGNUP";
        gotoxy(73,25);
        cout<<"2) SIGNIN";
        cin.get(ch);
    }

    int main()
    {
        int flag,flag1;
        cin.get();
        clrscr();

        input();

        switch(ch)
        {
        case '1':
            clrscr();
            o.signup();
            input();
            break;
        case '2':
            clrscr();
            flag=o.signin();
            if(flag==0)
            {
                o.forgotpassword();
                flag1=o.signin();
            }
            if(flag==1)
            {
                cout<<"hello world";
            }
            break;
        default:
            exit(0);

        }
        return 0;
    }



