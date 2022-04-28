#include <dos.h>
#include <stdio.h>
#include <graphics.h>
#include<string.h>
/*********************************************************
函数：void hz32(int x,int y,unsigned long int decode,int color)
作用：显示汉字函数
输入：坐标x,y,含有汉字的区位码，颜色
返回：无
*********************************************************/
void hz32(int x,int y,unsigned long int decode,int color)
{   //unsigned int h=0xB0A2;
	unsigned long int offset=0;
	unsigned long int up=(decode&0xFF)-161;
	//unsigned int up=60;
	offset=(((decode&0xFF00)/256-1-160)*94+up)*32;
	offset*=4;
	unsigned char hanzi[128]={0};
	short int masks[8]={128,64,32,16,8,4,2,1};
	FILE *f1=NULL;
	f1=fopen(".\\ZK\\HZ32","rb");
	fseek(f1,offset,SEEK_SET);
	int i=0,j=0,k=0;
	fread(hanzi,1,128,f1);
	for(i=0;i<32;i++)//lie		32涓瓧鑺傚垎鎴?16缁勶紝姣忎竴涓瓧鑺傞兘鎺у埗鍏釜鍍忕礌锛屽啀鍜屽叓涓儚绱犻亶鍘?
	{
		for(j=0;j<4;j++)//hang
		{
			for(k=0;k<8;k++)
			{
				if(hanzi[i*4+j]&masks[k]){
					putpixel(x+j*8+k,y+i,color);}
			}
		}
	}
fclose(f1);
}
void hz32s(int x,int y,char *hzs,int color,int n)
{
	int i=0;
	unsigned long int decode=0;
	for(i=0;i<n*2;i+=2)
	{
		decode = ((hzs[i]+256)*256+hzs[i+1]+256)+65536;
		hz32(x,y,decode,color);
		x+=32;
	}
}

void hz32sChanged(int x,int y,char *hzs,int color)
{
	int i=0;
	unsigned long int decode=0;
	for(i=0;i<strlen(hzs);i+=2)
	{
		decode = ((hzs[i]+256)*256+hzs[i+1]+256)+65536;
		hz32(x,y,decode,color);
		x+=32;
	}
}
