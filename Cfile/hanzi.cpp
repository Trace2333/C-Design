#include"hanzi.h"

/*********************************************************
函数：showHanZiBySize
作用：显示汉字函数
输入：坐标x,y,含有汉字的字符串，颜色，大小，汉字间距
返回：无
*********************************************************/
void showHanZiBySize(int x0,int y0,char *incode,int color,int size,int d)
{
	unsigned char qh,wh;
	unsigned long offset;
	FILE *hzk_p;
	char mat[32];
	int i,j,x,y,pos,num=16*size;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	
	hzk_p=fopen(".\\hanziku\\ziku.txt","rb");
	
	if(hzk_p==NULL)
	{
		printf("The file ziku.txt not exit hh\n");
		getch();
		closegraph();
		exit(1);
		
	}
	while(*incode)
	{
		qh=*incode-0xa0;
		wh=*(incode+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*32L;
		fseek(hzk_p,offset,SEEK_SET);
		fread(mat,32,1,hzk_p);

		y=y0;
		for(i=0;i<num;i++)
		{
			x=x0;
			pos=2*(i/size);
			for(j=0;j<num;j++)
			{
				if((mask[(j/size)%8]&mat[pos+j/(8*size)])!=NULL)
					putpixel(x,y,color);
				x++;
			}
			y++;
		}
		x0+=d;
		incode+=2;
	}
	fclose(hzk_p);
}
/*********************************************************
函数：showNumberAndLetter
作用：显示数字和字母//输入法
输入：位置x,ymax，字符串，颜色
返回：0成功 -1文件打不开
*********************************************************/
void ShowNumberAndLetter(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
}
/*********************************************************
函数：ShowNumberAndLetter1
作用：显示数字和字母//超小
输入：位置x,ymax，字符串，颜色
返回：无
*********************************************************/
void ShowNumberAndLetter1(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax+12,s);
}
/*********************************************************
函数：ShowNumberAndLetter2
作用：显示数字和字母//超大艺术字
输入：位置x,ymax，字符串，颜色
返回：无
*********************************************************/
void ShowNumberAndLetter2(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(1,HORIZ_DIR,8);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
}
/*********************************************************
函数：showNumberAndLetter3
作用：显示数字和字母//大点的普通字
输入：位置x,ymax，字符串，颜色
返回：0成功 -1文件打不开
*********************************************************/
void ShowNumberAndLetter3(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(SMALL_FONT,HORIZ_DIR,10);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
}
/*********************************************************
函数：ShowNumberAndLetter4
作用：显示数字和字母//也挺大的艺术字
输入：位置x,ymax，字符串，颜色
返回：无
*********************************************************/
void ShowNumberAndLetter4(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(1,HORIZ_DIR,5);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
}
/*********************************************************
函数：showNumberAndLetter5
作用：显示数字和字母//大点的普通字
输入：位置x,ymax，字符串，颜色
返回：0成功 -1文件打不开
*********************************************************/
void ShowNumberAndLetter5(int x,int ymax,char *s,int color)
{
	setcolor(color);
	settextstyle(SMALL_FONT,HORIZ_DIR,8);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
}
/*********************************************************
函数：ShowCharacter
作用：显示*
输入：位置x,ymax,“*”
返回：无
*********************************************************/
void ShowCharacter(int x,int ymax,char *s)
{
	setcolor(DARKGRAY);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-5,s);
	setcolor(WHITE);
}
/*********************************************************
函数：showword
作用：显示汉字
输入：位置x,ymax,字符串
返回：无
*********************************************************/
void showword(int x,int ymax,char *s)
{
	setcolor(BLACK);
	settextstyle(0,0,11);
	settextjustify(LEFT_TEXT,BOTTOM_TEXT);
	outtextxy(x,ymax-4,s);
	setcolor(WHITE);
}
/*********************************************************
函数：show3dhanzi
作用：显示3D汉字
输入：坐标x,y,含有汉字的字符串，颜色，大小，汉字间距
返回：无
*********************************************************/
void show3dhanzi(int x,int y,char *incode,int color1,int color2,int size,int d)
{
	int k;
	for(k=1;k<2*size;k++)
	{
		showHanZiBySize(x+k,y+k,incode,color2,size,d);
	}
	showHanZiBySize(x,y,incode,color1,size,d);
}
/*********************************************************
函数：showInputnumber
作用：注册密码“*”和数字的转化
输入：输入位置xmin,ymin,xmax,ymax,个数，间距，字符串，判断符
返回：无
*********************************************************/
void showInputnumber(int xmin,int ymin,int xmax,int ymax,int n,int d,char *s,int eyesmark)
{
	int i;
	setfillstyle(1,WHITE);
	bar(xmin,ymin,xmin+n*d,ymax-1);
	if(eyesmark==1)
		for(i=0;i<n;i++)
		{
			setcolor(DARKGRAY);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			settextjustify(LEFT_TEXT,BOTTOM_TEXT);
			outtextxy(xmin+i*d,ymax-9,s+i);
		}
	else
		for(i=0;i<n;i++)
		{
			setcolor(DARKGRAY);
			settextstyle(SMALL_FONT,HORIZ_DIR,7);
			settextjustify(LEFT_TEXT,BOTTOM_TEXT);
			outtextxy(xmin+i*d,ymax-9,"*");
		}
	
}
