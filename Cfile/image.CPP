/*BY    TRACE-2022      imageput.cpp*/
//the file is used to put a small image(no larger than 640x480 C=16,  .BMP),it should contains image.h.Once the image is put,it wont be removed...
/*
********************************************
*画图函数									*
*可以将尺寸小于640x480的图像投射到X，Y坐标处  *
*颜色位数为4位								*
********************************************
*/
#include <stdio.h>
#include <dos.h>
#include <IMAGE.h>
#include <time.h>
#include <graphics.h>
void image16(int X,int Y,char *filename)
{
	int x=0,y=0,i=0;
	//switch to Mode EGA.
	FILE *f1=NULL;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	int TEMP,n,color_numbers=1;
	unsigned long int segment = 0;
	f1 = fopen(filename,"rb");
	//fseek(f1,118,1);
	struct BitMapFileHeader BitMapFileHeader1;
	struct BitMapInfoHeader BitMapInfoHeader1;
	char far *page0 = (char far *)0xA0000000;//Page 0 start far adress
	char far *page=NULL;
	struct RGBTABLE PLATTLE[16]={{0,0,0},{0,0,42},{0,42,0},{0,42,42},{42,0,0},{42,0,42},{42,42,0},{42,42,42},{21,0,0},{21,21,63},{21,63,21},{21,63,63},{63,21,21},{63,21,63},{63,63,21},{63,63,63}};
	//Pattle reminds to be used.This Plattle can be used to adjust colors.
	TEMP=fread(&BitMapFileHeader1.head,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.size,4,1,f1);
	TEMP=fread(&BitMapFileHeader1.n1,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.n2,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.start,4,1,f1);//START BYTES
	//INFO
	TEMP=fread(&BitMapInfoHeader1.DIB,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.length,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.height,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.color_plane,2,1,f1);
	TEMP=fread(&BitMapInfoHeader1.biBytes,2,1,f1);
	TEMP=fread(&BitMapInfoHeader1.BI_RGB,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n1,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.pixel_length,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.pixel_height,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n2,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n3,4,1,f1);
	//PLATTLT
	for(n=0;n<BitMapInfoHeader1.biBytes;n++)    color_numbers*=2;
	for(n=0;n<color_numbers;n++)
	{
		//RGB TABLE
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
	}
	for(i=0;i<352;i++)	fseek(f1,228,SEEK_CUR);
	outportb(0x3ce,5);
	outportb(0x3cf,2);
	outportb(0x3ce,8);
	for(y=Y+352;y>=Y;y--)
	{
		segment = y*80L+19;
		for(x=0;x<456;x+=8)
		{
			page = (char far *)(page0+segment);
	   		read0 = fgetc(f1);read1 = fgetc(f1);
			read2 = fgetc(f1);read3 = fgetc(f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			outportb(0x3cf,0x80);
			pokeb(0xA000,segment,p1);
			TEMP = *page;
			outportb(0x3cf,0x40);
			pokeb(0xA000,segment,p2);
			TEMP = *page;
			outportb(0x3cf,0x20);
			pokeb(0xA000,segment,p3);
			TEMP = *page;
			outportb(0x3cf,0x10);
			pokeb(0xA000,segment,p4);
			TEMP = *page;
			outportb(0x3cf,0x8);
			pokeb(0xA000,segment,p5);
			TEMP = *page;
			outportb(0x3cf,0x4);
			pokeb(0xA000,segment,p6);
			TEMP = *page;
			outportb(0x3cf,0x2);
			pokeb(0xA000,segment,p7);
			TEMP = *page;
			outportb(0x3cf,0x1);
			pokeb(0xA000,segment,p8);
			TEMP = *page;
			segment++;
		}
	}
	fclose(f1);
	//moveData(0xA800,0xA500,300);
}
void putpiece(char *filename, int Direct, int lines)
{
	//前一个图片首碎块的大小为456x16，偏移量为0，读取字节数为：228*lines
	//图片末碎块的大小也为456x16，偏移量为：lines*228
	//0表示向下偏移，1表示向上偏移
	FILE *f1;
	char far *page0 = (char far *)0xA0000000;//Page 0 start far adress
	char far *page=NULL;
	f1 = fopen(filename,"rb");
	fseek(f1,118,SEEK_SET);//读掉头信息
	int i=0;
	int x=0,y=0;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	int TEMP,n,color_numbers=1;
	unsigned int segment=0;
	unsigned long int offsets = 0;
	//for(i=0;i<352;i++)	fseek(f1,228,1);//读掉原图片
	if(Direct==0)//显示下面的图片内容，即下面的空白小框里面显示的内容
	{
	for(i=0;i<352;i++)	fseek(f1,228,1);//读掉原图片
	offsets = 3648L*lines;
	fseek(f1,-offsets,SEEK_CUR);
	outportb(0x3ce,5);
	outportb(0x3cf,2);
	outportb(0x3ce,8);
	for(y=464;y>=448;y--)
	{
		segment = y*80+19;
		for(x=0;x<456;x+=8)
		{
			page = (char far *)(page0+segment);
	   		read0 = fgetc(f1);read1 = fgetc(f1);
			read2 = fgetc(f1);read3 = fgetc(f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			outportb(0x3cf,0x80);
			pokeb(0xA000,segment,p1);
			TEMP = *page;
			outportb(0x3cf,0x40);
			pokeb(0xA000,segment,p2);
			TEMP = *page;
			outportb(0x3cf,0x20);
			pokeb(0xA000,segment,p3);
			TEMP = *page;
			outportb(0x3cf,0x10);
			pokeb(0xA000,segment,p4);
			TEMP = *page;
			outportb(0x3cf,0x8);
			pokeb(0xA000,segment,p5);
			TEMP = *page;
			outportb(0x3cf,0x4);
			pokeb(0xA000,segment,p6);
			TEMP = *page;
			outportb(0x3cf,0x2);
			pokeb(0xA000,segment,p7);
			TEMP = *page;
			outportb(0x3cf,0x1);
			pokeb(0xA000,segment,p8);
			TEMP = *page;
			segment++;
		}
	}
	}
	if(Direct==1)//显示上面的图片内容,即上面的空白小框里面显示的内容
	{
	for(i=0;i<704;i++)	fseek(f1,228,SEEK_CUR);//读掉原图片,指针走到了图片的右上角，要重新读到当前lines的左下角
	offsets = 3648L * lines;
	fseek(f1,offsets,SEEK_CUR);
	outportb(0x3ce,5);
	outportb(0x3cf,2);
	outportb(0x3ce,8);
	for(y=128;y>=112;y--)
	{
		segment = y*80+152/8;
		for(x=0;x<456;x+=8)
		{
			page = (char far *)(page0+segment);
	   		read0 = fgetc(f1);read1 = fgetc(f1);
			read2 = fgetc(f1);read3 = fgetc(f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			outportb(0x3cf,0x80);
			TEMP = *page;
			pokeb(0xA000,segment,p1);
			TEMP = *page;
			outportb(0x3cf,0x40);
			pokeb(0xA000,segment,p2);
			TEMP = *page;
			outportb(0x3cf,0x20);
			pokeb(0xA000,segment,p3);
			TEMP = *page;
			outportb(0x3cf,0x10);
			pokeb(0xA000,segment,p4);
			TEMP = *page;
			outportb(0x3cf,0x8);
			pokeb(0xA000,segment,p5);
			TEMP = *page;
			outportb(0x3cf,0x4);
			pokeb(0xA000,segment,p6);
			TEMP = *page;
			outportb(0x3cf,0x2);
			pokeb(0xA000,segment,p7);
			TEMP = *page;
			outportb(0x3cf,0x1);
			pokeb(0xA000,segment,p8);
			TEMP = *page;
			segment++;
		}
	}
	}
	fclose(f1);
}
void moveData(int START, int END, int SIZE)
{
	asm push ds
	asm push es
	asm push di
	asm push si
	asm push ax
	asm push cx
	asm push dx
	asm mov ax,0xA000//第二页这里表示0XA00:START
	asm mov es,ax
	asm mov ax,START
	asm mov si,ax
	asm mov ax,0xA800//第一页表示0xA800:END
	asm mov es,ax
	asm mov ax,END
	asm mov di,ax
	asm mov cx,SIZE
	asm rep movsb
	asm pop dx
	asm pop cx
	asm pop ax
	asm pop si
	asm pop di
	asm pop ds
	asm pop es
}
void imagePut16(int X,int Y,char *filename)
{
	int x=0,y=0;
	//switch to Mode EGA.
	FILE *f1=NULL;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	int TEMP,n,color_numbers=1;
	unsigned int segment = 0;
	f1 = fopen(filename,"rb");
	//fseek(f1,118,1);
	struct BitMapFileHeader BitMapFileHeader1;
	struct BitMapInfoHeader BitMapInfoHeader1;
	char far *page0 = (char far *)0xA0000000;//Page 0 start far adress
	char far *page=NULL;
	struct RGBTABLE PLATTLE[16]={{0,0,0},{0,0,42},{0,42,0},{0,42,42},{42,0,0},{42,0,42},{42,42,0},{42,42,42},{21,0,0},{21,21,63},{21,63,21},{21,63,63},{63,21,21},{63,21,63},{63,63,21},{63,63,63}};
	//Pattle reminds to be used.This Plattle can be used to adjust colors.
	TEMP=fread(&BitMapFileHeader1.head,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.size,4,1,f1);
	TEMP=fread(&BitMapFileHeader1.n1,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.n2,2,1,f1);
	TEMP=fread(&BitMapFileHeader1.start,4,1,f1);//START BYTES
	//INFO
	TEMP=fread(&BitMapInfoHeader1.DIB,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.length,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.height,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.color_plane,2,1,f1);
	TEMP=fread(&BitMapInfoHeader1.biBytes,2,1,f1);
	TEMP=fread(&BitMapInfoHeader1.BI_RGB,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n1,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.pixel_length,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.pixel_height,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n2,4,1,f1);
	TEMP=fread(&BitMapInfoHeader1.n3,4,1,f1);
	//PLATTLT
	for(n=0;n<BitMapInfoHeader1.biBytes;n++)    color_numbers*=2;
	for(n=0;n<color_numbers;n++)
	{
		//RGB TABLE
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
		TEMP=fgetc(f1);
	}
	outportb(0x3ce,5);
	outportb(0x3cf,2);
	outportb(0x3ce,8);
	for(y=Y+BitMapInfoHeader1.height;y>=Y;y--)
	{
		segment = y*80+X/8L;
		for(x=0;x<BitMapInfoHeader1.length;x+=8)
		{
			page = (char far *)(page0+segment);
	   		read0 = fgetc(f1);read1 = fgetc(f1);
			read2 = fgetc(f1);read3 = fgetc(f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			outportb(0x3cf,0x80);
			pokeb(0xA000,segment,p1);
			TEMP = *page;
			outportb(0x3cf,0x40);
			pokeb(0xA000,segment,p2);
			TEMP = *page;
			outportb(0x3cf,0x20);
			pokeb(0xA000,segment,p3);
			TEMP = *page;
			outportb(0x3cf,0x10);
			pokeb(0xA000,segment,p4);
			TEMP = *page;
			outportb(0x3cf,0x8);
			pokeb(0xA000,segment,p5);
			TEMP = *page;
			outportb(0x3cf,0x4);
			pokeb(0xA000,segment,p6);
			TEMP = *page;
			outportb(0x3cf,0x2);
			pokeb(0xA000,segment,p7);
			TEMP = *page;
			outportb(0x3cf,0x1);
			pokeb(0xA000,segment,p8);
			TEMP = *page;
			segment++;
		}
	}
	fclose(f1);
	//moveData(0xA800,0xA500,300);
}