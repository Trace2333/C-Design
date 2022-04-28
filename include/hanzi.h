#ifndef _HANZI_H_
#define _HANZI_H_

#include<stdio.h>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>

void showHanZiBySize(int x0,int y0,char *incode,int color,int size,int d);//显示汉字函数
void ShowNumberAndLetter(int x,int ymax,char *s,int color);//显示数字和字母
void ShowNumberAndLetter1(int x,int ymax,char *s,int color);//显示数字和字母（字号不同）
void ShowNumberAndLetter2(int x,int ymax,char *s,int color);
void ShowNumberAndLetter3(int x,int ymax,char *s,int color);
void ShowNumberAndLetter4(int x,int ymax,char *s,int color);
void ShowNumberAndLetter5(int x,int ymax,char *s,int color);
void ShowCharacter(int x,int ymax,char *s);//显示*
void showword(int x,int ymax,char *s);//显示倒计时
void show3dhanzi(int x,int y,char *incode,int color1,int color2,int size,int d);//显示3D汉字
void showInputnumber(int xmin,int ymin,int xmax,int ymax,int n,int d,char *s,int eyesmark);
#endif