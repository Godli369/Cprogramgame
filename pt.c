#include <stdio.h> //�����������
#include <conio.h>//�ַ��������
#include <stdlib.h>//��������
#include <time.h> //��ʱ
int MenuReturn;
void RandMap(char map[][3]);//���������
void Game(void);//��Ϸ��ѭ��
int Help(void);//��Ϸ�淨����
int About(void);//������Ϸ
int Menu(void);//��Ϸ����
void DealWithMenu(intMenuReturn); //����˵�
void Show(char map[][3]);
int IsWin(char map[][3]);//�ж��Ƿ���ʤ������
//������ ######################
int main(void)
{
system("color 9f");//���ñ���Ϊ����ɫ����Ϊ����ɫ
MenuReturn = Menu();//���ز˵�
DealWithMenu(MenuReturn);
return 0;
} 
//��Ϸ����#####################
int Menu(void)
{
int sel = 1; 
int tem = 0;
char kb;
system("cls");//����
printf("  ����ƴͼ\n\n\n");
printf("->��ʼ��Ϸ<-\n  �淨����  \n  ����\n  �˳���Ϸ  \n");
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
printf("  ����ƴͼ\n\n\n");
switch (sel)
{
case 1 : printf("->��ʼ��Ϸ<-\n  �淨����  \n  ����  \n  �˳���Ϸ  \n");break;
case 2 : printf("  ��ʼ��Ϸ  \n->�淨����<-\n  ����  \n  �˳���Ϸ  \n");break;
case 3 : printf("  ��ʼ��Ϸ  \n  �淨����  \n->����<-\n  �˳���Ϸ  \n");break;
case 4 : printf("  ��ʼ��Ϸ  \n  �淨����  \n  ����  \n->�˳���Ϸ-<\n");break;
default: return-1; break; 
}
}while(kb != '\r');
return sel;
}
//����˵�#####################
void DealWithMenu(intMenuReturn)
{
int retu;
switch(MenuReturn)
{
case 1 : Game();break;
case 2 : retu = Help();break;
case 3 : retu = About();break;
case 4 : exit(0);break;
case-1:printf("����δ֪����!\n"); 
}
}
//��������#####################
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
//�ƶ�����#####################
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
//���������###################
void RandMap(char map[][3])
{
int i,j,k,n = 0;
srand((unsigned)time(NULL));
for(i=0;i<8;i++)
{
map[0][i] = '1'+i;
}
while(n<99)//�������99�Σ�����㷨��̫�ã����׳�������
{
int tem;
j = rand()%8; 
k = rand()%8;
if (k-j == 1||j-k == 1||k-j == 3||j-k == 3)
{ continue;//��С���ֳ��ֵĸ��ʣ�����λ�õ����ֲ��ܽ���
}
tem = map[0][k];
map[0][k]=map[0][j];
map[0][j] = tem;
n++; }//����㷨����ʵ��ָ��������������У����Ա���Ϸ��̫���ʣ����򲻱�֤��Ϸ�н�
map[2][2] = ' ';
}
//������Ϸ�淨##################
int Help(void)
{
system("cls");
printf("�����ʼ��Ϸ,������������һ������,����:\n314\n286\n75\n���wasd�ƶ�����,ֱ��\n123\n456\n78\n��ʤ��");
printf("���ز˵���\t   =====   y/n\n");
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
//������Ϸ#####################
int About(void)
{
system("cls");
printf("#########################################\n\n\n");
printf("         !!!����������!!!\n\n\n");
printf("#########################################\n");
printf("���ز˵���\t ====== y/n\n");
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
//����ʤ������##################
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
//��Ϸ��������##################
void Game(void)
{
unsigned int t1 = time(NULL);
char Map[3][3] = {0};
int Crx = 2;
int Cry = 2;
RandMap(Map);//������һ������
Show(Map);
printf("�������ʼ��Ϸ����\n");
getch();
while(1)
{
unsigned int t2 = time(NULL);
MoveNumber(Map,&Crx,&Cry);//�û�����
Show(Map);
if(IsWin(Map))
{
printf("ʤ��~!��ʱ%dS",t2-t1);
return;
}
}
}