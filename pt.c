#include <stdio.h> //输入输出函数
#include <conio.h>//字符输入输出
#include <stdlib.h>//函数调用
#include <time.h> //计时
int MenuReturn;
void RandMap(char map[][3]);//随机生成数
void Game(void);//游戏主循环
int Help(void);//游戏玩法介绍
int About(void);//关于游戏
int Menu(void);//游戏界面
void DealWithMenu(intMenuReturn); //处理菜单
void Show(char map[][3]);
int IsWin(char map[][3]);//判断是否达成胜利条件
//主函数 ######################
int main(void)
{
system("color 9f");//设置背景为淡蓝色，字为亮白色
MenuReturn = Menu();//返回菜单
DealWithMenu(MenuReturn);
return 0;
} 
//游戏界面#####################
int Menu(void)
{
int sel = 1; 
int tem = 0;
char kb;
system("cls");//清屏
printf("  数字拼图\n\n\n");
printf("->开始游戏<-\n  玩法介绍  \n  关于\n  退出游戏  \n");
do
{
kb=getch();
switch(kb)
{
case 'w':tem--;sel+=tem;break;
case 's':tem++;sel+=tem;break;
default:NULL;break;
}
tem = 0;
if (sel == 0)
{
sel = 4;
}
if (sel == 5)
{
sel = 1;
}
system("cls");
printf("  数字拼图\n\n\n");
switch (sel)
{
case 1 : printf("->开始游戏<-\n  玩法介绍  \n  关于  \n  退出游戏  \n");break;
case 2 : printf("  开始游戏  \n->玩法介绍<-\n  关于  \n  退出游戏  \n");break;
case 3 : printf("  开始游戏  \n  玩法介绍  \n->关于<-\n  退出游戏  \n");break;
case 4 : printf("  开始游戏  \n  玩法介绍  \n  关于  \n->退出游戏-<\n");break;
default: return-1; break; 
}
}while(kb != '\r');
return sel;
}
//处理菜单#####################
void DealWithMenu(intMenuReturn)
{
int retu;
switch(MenuReturn)
{
case 1 : Game();break;
case 2 : retu = Help();break;
case 3 : retu = About();break;
case 4 : exit(0);break;
case-1:printf("发生未知错误!\n"); 
}
}
//生成数阵#####################
void Show(char map[][3])
{
int i,j;
system("cls");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%2c",map[i][j]);
}
printf("\n");
}
return;
}
//移动数阵#####################
void MoveNumber(char map[][3],int *Crx,int *Cry)
{
enum {UP,DOWN ,LEFT ,RIGHT};
int kb;
int dx = 0,dy = 0;
switch(getch())
{
case 'w' :dy--;kb = UP;break;
case 's' :dy++;kb = DOWN;break;
case 'a' :dx--;kb = LEFT;break;
case 'd' :dx++;kb = RIGHT;break;
default:NULL;break; 
}
if(kb == UP&& *Cry+1<=2)
{
map[*Cry][*Crx] = map[*Cry+1][*Crx];
map[*Cry+=1][*Crx] = ' ';
}
if(kb == DOWN&&*Cry-1>=0)
{
map[*Cry][*Crx] = map[*Cry-1][*Crx];
map[*Cry-=1][*Crx] = ' ';
}
if(kb == LEFT&&*Crx+1<=2)
{
map[*Cry][*Crx] = map[*Cry][*Crx+1];
map[*Cry][*Crx+=1] = ' ';
}
if(kb ==RIGHT&& *Crx-1>=0)
{
map[*Cry][*Crx] = map[*Cry][*Crx-1];
map[*Cry][*Crx-=1] = ' ';
}
return;
}
//随机生成数###################
void RandMap(char map[][3])
{
int i,j,k,n = 0;
srand((unsigned)time(NULL));
for(i=0;i<8;i++)
{
map[0][i] = '1'+i;
}
while(n<99)//随机交换99次，这个算法不太好，容易出现死局
{
int tem;
j = rand()%8; 
k = rand()%8;
if (k-j == 1||j-k == 1||k-j == 3||j-k == 3)
{ continue;//减小死局出现的概率，相邻位置的数字不能交换
}
tem = map[0][k];
map[0][k]=map[0][j];
map[0][j] = tem;
n++; }//这个算法可以实现指定数组的乱序排列，但对本游戏不太合适，乱序不保证游戏有解
map[2][2] = ' ';
}
//定义游戏玩法##################
int Help(void)
{
system("cls");
printf("点击开始游戏,程序会随机生成一个数阵,例如:\n314\n286\n75\n点击wasd移动数字,直至\n123\n456\n78\n则胜出");
printf("返回菜单吗？\t   =====   y/n\n");
do
{
int ch = getchar();
if(ch == 'y')
{
return 1;
}
if(ch == 'n')
{
return 2;
}
}
while(1);
}
//关于游戏#####################
int About(void)
{
system("cls");
printf("#########################################\n\n\n");
printf("         !!!巩大利制作!!!\n\n\n");
printf("#########################################\n");
printf("返回菜单吗？\t ====== y/n\n");
do
{
int ch = getchar();
if(ch == 'y')
{
return 1;
}
if(ch == 'n')
{
return 3;
}
}
while(1);
}
//定义胜利条件##################
int IsWin(char map[][3])
{
int i;
int j = 0;
for(i = 0;i<8;i++)
{
if (map[0][i] == '1'+i)
j++;
}
if (j == 8)
{
return 1;
}
else
{
return 0;
}
}
//游戏运行主体##################
void Game(void)
{
unsigned int t1 = time(NULL);
char Map[3][3] = {0};
int Crx = 2;
int Cry = 2;
RandMap(Map);//先生成一个数阵
Show(Map);
printf("任意键开始游戏！！\n");
getch();
while(1)
{
unsigned int t2 = time(NULL);
MoveNumber(Map,&Crx,&Cry);//用户操作
Show(Map);
if(IsWin(Map))
{
printf("胜利~!用时%dS",t2-t1);
return;
}
}
}