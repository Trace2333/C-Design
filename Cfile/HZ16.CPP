#include <dos.h>
#include <stdio.h>
#include <graphics.h>
#include<string.h>
/*********************************************************
函数：void hz16(int x,int y,unsigned long int decode,int color)
作用：显示汉字函数
输入：坐标x,y,含有汉字的区位码，颜色
返回：无
*********************************************************/
void hz16(int x,int y,unsigned long int decode,int color)
{   //unsigned int h=0xB0A2;
	unsigned long int offset=0;
	unsigned int up=(decode&0xFF)-161;
	offset=(((decode&0xFF00)/256-1-160)*94+up)*32;
	unsigned char hanzi[32]={0};
	short int masks[8]={128,64,32,16,8,4,2,1};
	FILE *f1;
	f1=fopen(".\\ZK\\HZ16","rb");
	fseek(f1,offset,SEEK_SET);
	int i=0,j=0,k=0;
	fread(hanzi,1,32,f1);
	for(i=0;i<16;i++)//lie
	{
		for(j=0;j<2;j++)//hang
		{
			for(k=0;k<8;k++)
			{
				if(hanzi[i*2+j]&masks[k]){
					putpixel(x+j*8+k,y+i,color);}
			}
		}
	}
	fclose(f1);
}
void hz16s(int x,int y,char *hzs,int color,int n)
{
	int i=0;
	unsigned long int decode=0;
	for(i=0;i<n*2;i+=2)
	{
		decode = ((hzs[i]+256)*256+hzs[i+1]+256)+65536;
		hz16(x,y,decode,color);
		x+=16;
	}
}

void hz16sChanged(int x,int y,char *hzs,int color)
{
	int i=0;
	unsigned long int decode=0;
	for(i=0;i<strlen(hzs);i+=2)
	{
		decode = ((hzs[i]+256)*256+hzs[i+1]+256)+65536;
		hz16(x,y,decode,color);
		x+=16;
	}
}
