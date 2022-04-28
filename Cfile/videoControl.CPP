#include <stdio.h>
#include <IMAGE.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <pages.h>
#include <bios.h>
/*
********************************************
*功能:控制视频播放与源文件读取
*参数:
*filename:视频文件夹路径，源文件夹内部文件命名需要是序号形式，如(1).bmp
*******************************************
*/
int videoControl(char *filename,int n,int *xy,int *button)
{
	//char filename[50]="C:\\images\\(1).bmp";
	char multipy[10]="\\(1).bmp";
	strcat(filename,multipy);
	int l=strlen(filename),i;
	char no[20];
	setfillstyle(1,RED);

	setactivepage(0);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,1,3);
	line(0,320,639,320);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,1);
	bar(0,330,40,350);
	circle(320,340,10);
	line(315,337,315,343);//暂停线
	line(325,337,325,343);
	hz16(4,332,0xCDCB,BLACK);hz16(20,332,0xB3F6,BLACK);

	setactivepage(1);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,1,3);
	line(0,320,639,320);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,1);
	bar(0,330,40,350);
	circle(320,340,10);
	line(315,337,315,343);//暂停线
	line(325,337,325,343);
	hz16(4,332,0xCDCB,BLACK);hz16(20,332,0xB3F6,BLACK);

	asm push dx
	asm push ds
	asm push ax
	asm mov dx,0x3ce
	asm mov ax,0x0205//切换为写模式2
	asm out dx,ax
	asm mov al,8
	asm out dx,al
	asm inc dx
	asm mov al,0xFF
	asm out dx,al
	asm pop dx
	asm pop ds
	asm pop ax
for(i=0;i<n;i+=2)
	{
		itoa(i,no,10);
		strcpy(filename+l-6,"");
		strcat(filename,no);
		strcat(filename+l-6+strlen(no),").bmp");
		setactivepage(0);
		// bar((i*640L)/n,318,(i*640L)/n+5,324);
		// line(0,320,(i*640L)/n,320);
		if(letterChoose()==0)	
		{	
			while(1)
			{
				if(letterChoose()==0)
				{
					break;
				}
				if(letterChoose()==2)	
				{
					fflush(stdin);
					return 1;
				}
			}
		}
		if(letterChoose()==2)	
		{
			fflush(stdin);
			return 1;
		}
		if(letterChoose()==1)	
		{
			while(1)
			{
				if(letterChoose()==1)	
				i++;
				else	
				break;
			}
		}
		videoPutTo0(0,0,filename);
		setvisualpage(0);
		itoa(i+1,no,10);
		strcpy(filename+l-6,"");
		strcat(filename,no);
		strcat(filename+l-6+strlen(no),").bmp");
		if(letterChoose()==2)	
		{
			return 1;
		}
		// setactivepage(1);
		// bar((i*640L)/n,318,(i*640L)/n+5,322);
		// line(0,320,(i*640L)/n,320);
		videoPutTo1(0,0,filename);
		setvisualpage(1);
		if(letterChoose()==0)	
		{	
			while(1)
			{
				if(letterChoose()==0)
				{
					break;
				}
				if(letterChoose()==2)	
				{
					fflush(stdin);
					return 1;
				}
			}
		}
		if(letterChoose()==2)	
		{
			fflush(stdin);
			return 1;
		}
		if(letterChoose()==1)	
		{
			while(1)
			{
				if(letterChoose()==1)	
				i++;
				else	
				break;
			}
		}
	}
	return 0;
}
void videoControlSVGA(char *filename,int n,int *xy,int *button)
{
	SVGAinit();
	//char filename[40]="C:\\TYXX\\IMAGES\\B";
	char multipy[10]="\\(1).bmp";
	strcat(filename,multipy);
	int l=strlen(filename),i;
	char no[20];
	for(i=0;i<n;i+=2)
	{
		itoa(i,no,10);
		delay(40);
		strcpy(filename+l-6,"");
		strcat(filename,no);
		strcat(filename+l-6+strlen(no),").bmp");
		SVGA640(filename,20,50);
		delay(40);
	}
}
int letterChoose()
{
	int letter=0;
	{
	if(bioskey(1))
	{
		letter = bioskey(0);
		if(letter == 0x011b)    return 2;//ESC
		if(letter == 0x3920)    return 0;//space
		if(letter == 0x4d00)    return 1;//箭头
	}
	}
return -1;
}