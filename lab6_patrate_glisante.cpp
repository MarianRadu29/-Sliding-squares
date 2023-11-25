#include<iostream>
#include<fstream>
#include<graphics.h>
#include<winbgim.h>
#include<conio.h>
using namespace std;
int tabla[6][6]={0} , i , j , i0 , j0 , cas, is , js , dx[]={-1 , 0 ,1 ,0} , dy[]={0 , 1 , 0 , -1} , t[6][6]={0};
int T[26]={0,6,7,8,5,4,1,2,3,10,9,12,11,0,15,14,21,22,19,18,25,16,17,24,23,20};
void w(int color,int i0,int j0)
{   for(j=0;j<=100;j++)
        {
            setfillstyle(1,color);
            bar(100*i0+10, 100*j0+10-j , 100*i0+90 , 100*j0+90-j);
            setcolor(LIGHTRED);
            line(100*i0+10 , 100*j0+90-j, 100*i0+90 , 100*j0+90-j); 
            delay(10);
        }
}
void s(int color , int io , int jo)
{
    for(j=0;j<=100;j++)
    {
        setfillstyle(1,color);
        bar(100*i0+10, 100*j0+10+j , 100*i0+90 , 100*j0+90+j);
        setcolor(LIGHTRED);
        line(100*i0+10 , 100*j0+10+j , 100*i0+90 , 100*j0+10+j);
        delay(10);
    }
}
void a(int color,int i0 ,int j0)
{   for(j=0;j<=100;j++)
        {   setfillstyle(1,color);
            bar(100*i0+10-j,100*j0+10,100*i0+90-j,100*j0+90);
            setcolor(LIGHTRED);
            line( 100*i0+90-j-1,100*j0+10,100*i0+90-j-1,100*j0+90);
            delay(10);
        }
}
void d(int color,int i0 ,int j0)
{
    for(j=0;j<=100;j++)
        {
            setfillstyle(1,color);
            bar(100*i0+10+j , 100*j0+10 , 100*i0+90+j,100*j0+90);
            setcolor(LIGHTRED);
            line(100*i0+10+j , 100*j0+10 , 100*i0+10+j , 100*j0+90);
            delay(10);
        }
}
void pc()
{
    cas = T[5*(i0-1)+j0];
    is=(cas-1)/5+1;
       js=(cas-1)%5+1;
    for(i=1;i<=10;i++)
    delay(25);
    if(is==i0)
        if(j0<js)
            {   swap(tabla[j0][i0],tabla[j0+1][i0]);
                 j0=js;
                 w(RED,i0,j0);
            }
        else
             {   swap(tabla[j0][i0],tabla[j0-1][i0]);
                j0=js;
                s(RED,i0,j0);
            }
    else
        if(i0<is)
             {   swap(tabla[j0][i0],tabla[j0][i0+1]);
                 i0=is;
                 a(RED,i0,j0);
            }
        else
             {   swap(tabla[j0][i0],tabla[j0][i0-1]);
                 i0=is;
                d(RED,i0,j0);
            } 
}
void game()
{   //1 este pentru bot
    //-1 pentru om
    RESTART:
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            tabla[i][j]=t[i][j];
    setbkcolor(LIGHTRED);
    cleardevice();
    for(i=0;i<=100;i+=10)
        {
            setcolor(BLACK); 
            rectangle(90-i,90-i,610+i,610+i);
        }


    for(i=0;i<=10;i++)
        {
            setcolor(BLACK); 
            rectangle(90-i,90-i,610+i,610+i);
            rectangle(10-i,10-i,690+i,690+i);
            line(0,695+i,695+i,0);
        }
    line(0,0,700,700);
    for(i=0;i<=5;i++)
    {
        line(0,i,695+i,700);
        line(i,0,700,695+i);
    }
    for(i=0;i<=700;i+=10)
        {
            setcolor(BLACK);
            line(0,i,i,0);
            line(700,700-i,700-i,700);
            line(0,700-i,i,700);
            line(700-i,0,700,i);
        }
    setfillstyle(1,LIGHTRED);
    bar(91,91,610,610);
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            switch (tabla[i][j])
            {
            case 1:
                setfillstyle(1,RED);
                bar(100*i+10 , 100*j+10 , 100*i+90 , 100*j+90);
                break;
            case -1:
                setfillstyle(1,BLUE);
                bar(100*i+10 , 100*j+10 , 100*i+90 , 100*j+90);
            default:
                break;
            }
    i0=3;
    j0=3;
    bool game=1;
        do
            {       bool mutat=0;
                    if(_kbhit())
                        {     
                                char c = getch();
                                switch (c)
                                {   
                                    case 'w':
                                        
                                            if(j0>=1&&tabla[j0+1][i0]==-1)
                                            {  
                                                            swap(tabla[j0][i0],tabla[j0+1][i0]);
                                                        j0++;
                                                        w(BLUE,i0,j0);
                                                        pc();
                                            }
                                        break;
                                    case 's':
                                        if(j0<=5&&tabla[j0-1][i0]==-1)
                                                        {        
                                                        
                                                            swap(tabla[j0][i0],tabla[j0-1][i0]);
                                                                j0--;
                                                                s(BLUE,i0,j0);  
                                                                pc();
                                                        }
                                      break;
                                case 'a':       
                                    if(i0<=5&&tabla[j0][i0+1]==-1)
                                        {   
                                            swap(tabla[j0][i0],tabla[j0][i0+1]);
                                        i0++;
                                        a(BLUE,i0,j0);
                                        pc();
                                        }
                                break;
                            case 'd':
                                if(i0>=1&&tabla[j0][i0-1]==-1)
                                {       
                                            swap(tabla[j0][i0],tabla[j0][i0-1]);
                                        i0--;
                                        d(BLUE,i0,j0);
                                        pc();
                                }
                                    break;
                              default:
                                        break;
                                    }
                        }
                    bool sw=1;
                    for(i=0;i<4;i++)
                    {
                        if(tabla[j0+dx[i]][i0+dy[i]]!=1 && j0+dx[i]>0 && j0+dx[i]<=5 && i0+dy[i]>0 &&i0+dy[i]<=5)
                                    sw=0;
                    }
                    if(sw==1)
                        game=0;
            }
            while(game);
        setcolor(MAGENTA);
        outtextxy(330,350,"     Ati pierdut!!       ");
        E:
        char tasta=getch();
        if(tasta==NULL)
            goto E;
        else 
        {
            if(tasta=='r')
                goto RESTART;
            if(tasta=='e')
                closegraph();
        }   
}
int main()
{  
    ifstream f("tabla.txt");
     for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            f>>tabla[i][j];
     for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            t[i][j]=tabla[i][j];
    /*
        1 -1 1 -1 1
        -1 1 -1 1 -1
        1 -1 0 -1 1
        -1 1 -1 1 -1
        1 -1 1 -1 1
    */
    initwindow(700,700,"JOC");
    game();
    getch();
    closegraph();
}