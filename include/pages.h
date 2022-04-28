//鼠标函数
//void mouseinit();
void mousehide();
void mousevisiual();
void mouseCreate();
int mousey();
int mousex();
int mouseLeftStatus();
void mousexy(int *xy,int *button);
void mouseVisiblePage(int n);
//图像初始化
void graphinit();
//汉字显示
#include"./include/user.h"
void hz16(int x,int y,unsigned long int decode,int color);
void hz32(int x,int y,unsigned long int decode,int color);
void hz16s(int x,int y,char *hzs,int color,int n);
void hz16sChanged(int x,int y,char *hzs,int color);
void hz32s(int x,int y,char *hzs,int color,int n);
void hz32sChanged(int x,int y,char *hzs,int color);
//页面的绘制，跳转
void pageOrigin(int *xy,int *button);
int pageMy(int *xy,int *button,User *loginuser);
int pageStu(int *xy,int *button);
int pageExplore(int *xy,int *button);
int pageMission(int *xy,int *button,User *loginuser,char *hz_in_ex1);
void pageIn();
//绘制小图案，如图标，LOGO，滑动条
void pageSign(int x, int y, int sign);
int scrollBar(int *xy,int *button);
int scrollBarForExplore(int *xy,int *button);
void arrows();
void drawBlock(int yU);
//#define BLACK 1
//页面跳转宏定义
#define MY xy[0]>11&&xy[0]<102&&xy[1]<206&&xy[1]>174&&button[0]==1
#define STUDY xy[0]>11&&xy[0]<102&&xy[1]>242&&xy[1]<274&&button[0]==1
#define EXPLORE xy[0]>11&&xy[0]<102&&xy[1]>310&&xy[1]<342&&button[0]==1
#define MISSION xy[0]>11&&xy[0]<102&&xy[1]>378&&xy[1]<410&&button[0]==1