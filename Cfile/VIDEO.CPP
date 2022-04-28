#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <IMAGE.h>
#include <pages.h>
#include <mem.h>
#include <SVGA256.H>
#include <SVGAUTIL.h>
#include <bios.h>
/*
**********************************************************
*BY TRACE-2022  Video.CPP                                *
*函数作用：播放十六色图片集构成的视频                       *
*参数:x,y,filename,frequency                            *
**********************************************************
*/
void EGAinit()
{
	int x=EGA,y=EGAHI;
	initgraph(&x,&y,"C:\\BORLANDC\\BGI");
	int errorCode = graphresult();
	if(errorCode != grOk)
	{
		printf("EGA WRONG!");
		exit(1);
	}
}
/*void memoryToVRAM()
{
	asm push dx
	asm push si
	asm push ds
	asm push ax
	asm push cx
	asm ax,0xA000
	asm dx,ax
	asm
}*/
void videoPut(int x,int y,char *filename, int page)
{
	//switch to Mode EGA.
	FILE *f1=NULL;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	int TEMP,n,color_numbers=1,segment;
	f1 = fopen(filename,"rb");
	fseek(f1,118,1);
	char far *page0 = (char far *)0xA0000000;//Page 0 start far adress
	char far *page1 = (char far *)0xA8000000;//Page 1 start far adress
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
	for(y=330;y>=20;y--)
	{
		segment = y*80;
		segment-=80*20;
		//if(y>340||y<20)	fseek(f1,320,SEEK_CUR);
		for(x=0;x<80;x++)
		{
			//read0 = fgetc(f1);read1 = fgetc(f1);read2 = fgetc(f1);read3 = fgetc(f1);
			fread(&read0,1,1,f1);
			fread(&read1,1,1,f1);
			fread(&read2,1,1,f1);
			fread(&read3,1,1,f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x80
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p1
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si


			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x40
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p2
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x20
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p3
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x10
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p4
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x8
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p5
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x4
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p6
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x2
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p7
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x1
			asm out dx,al
			if(page==0)	asm mov dx,0xA000
			if(page==1) asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p8
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si
			segment++;
		}
	}
	fclose(f1);
}
/*void videoMove()
{
	int num1 = 0,num2 = 0;
	int addr[350] = {0};
	for(num1=0;num1<350;num1++)
	{
		addr[num1] = num1*80;
	}
	for(num1=349;num1>=0;num1--)
	{
			moveData(addr[num1],addr[num1],160);
	}
} */
void videoPutTo0(int x,int y,char *filename)
{
	//switch to Mode EGA.
	FILE *f1=NULL;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	int TEMP,n,color_numbers=1,segment;
	f1 = fopen(filename,"rb");
	fseek(f1,118,1);
	char far *page0 = (char far *)0xA0000000;//Page 0 start far adress
	for(y=330;y>=20;y--)
	{
		segment = y*80;
		segment-=80*20;
		//if(y>340||y<20)	fseek(f1,320,SEEK_CUR);
		for(x=0;x<80;x++)
		{
			//read0 = fgetc(f1);read1 = fgetc(f1);read2 = fgetc(f1);read3 = fgetc(f1);
			fread(&read0,1,1,f1);
			fread(&read1,1,1,f1);
			fread(&read2,1,1,f1);
			fread(&read3,1,1,f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x80
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p1
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si


			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x40
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p2
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x20
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p3
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x10
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p4
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x8
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p5
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x4
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p6
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x2
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p7
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x1
			asm out dx,al
			asm mov dx,0xA000
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p8
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si
			segment++;
		}
	}
	fclose(f1);
}
void videoPutTo1(int x,int y,char *filename)
{
	//switch to Mode EGA.
	FILE *f1=NULL;
	int p1,p2,p3,p4,p5,p6,p7,p8,read0,read1,read2,read3;
	unsigned int TEMP,n,color_numbers=1,segment=0;
	f1 = fopen(filename,"rb");
	fseek(f1,118,1);
	char far *page1 = (char far *)0xA8000000;//Page 1 start far adress
	for(y=330;y>=20;y--)
	{
		segment = y*80;
		segment-=80*20;
		//if(y>340||y<20)	fseek(f1,320,SEEK_CUR);
		for(x=0;x<80;x++)
		{
			//read0 = fgetc(f1);read1 = fgetc(f1);read2 = fgetc(f1);read3 = fgetc(f1);
			fread(&read0,1,1,f1);
			fread(&read1,1,1,f1);
			fread(&read2,1,1,f1);
			fread(&read3,1,1,f1);
			p1=read0>>4;p2=read0&0xF;
			p3=read1>>4;p4=read1&0xF;
			p5=read2>>4;p6=read2&0xF;
			p7=read3>>4;p8=read3&0xF;
			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x80
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p1
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si


			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x40
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p2
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x20
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p3
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x10
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p4
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x8
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p5
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x4
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p6
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x2
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p7
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si

			asm push dx
			asm push ds
			asm push si
			asm mov dx,0x3cf
			asm mov al,0x1
			asm out dx,al
			asm mov dx,0xA800
			asm mov ds,dx
			asm mov si,segment
			asm mov bx,p8
			asm cli
			asm mov ah,ds:[si]
			asm mov ds:[si],bl
			asm sti
			asm pop dx
			asm pop ds
			asm pop si
			segment++;
		}
	}
	fclose(f1);
}
int bmp_fast(int y1,int y2,char* path)
{
	long int bfoffbits;
	unsigned int far* head = (unsigned int far*)0xa0000000L;
	unsigned int* buffer;
	int i, j, k;
	int top, end;
	unsigned int width, height;
	FILE* fpbmp;
	fpbmp = fopen(path, "rb");
	if (fpbmp == NULL)
	{
		return 1;
	}
	if ((buffer = (unsigned int*)malloc(1024 * 2)) == 0)
	{
		return 1;
	}
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	fseek(fpbmp, 0x0a, SEEK_SET);
	fread(&bfoffbits, sizeof(long), 1, fpbmp);
	fseek(fpbmp, bfoffbits, SEEK_SET);
	top = y1 / 32 + (y1 % 32)/16;
	end = y2 / 32 + (y2 % 32) / 16;
	for (i = 12; i > 0; i--)
	{
		//Selectpage(i - 1);
		SVGAPlanefind(i-1);
		for (j = 32; j > 0; j--)
		{
			fread(buffer, 1024, 2, fpbmp);
			//if (i < end && i>top)
			{
				_fmemcpy(head + ((i - 1) * 32 + j - 1) * 1024, buffer, 1024 * 2);                  //1024*2表示一行像素内存,buffer储存 
			}
		}
	}
	free(buffer);
	fclose(fpbmp);
	return 0;
}
void Selectpage(char page)
{
	union REGS regs;
	static unsigned char old_page = 0;     //上一次的页面号,用于减少切换次数 
	static int flag = 0;                   //标志数，用于判断是否是第一次换页
	regs.x.ax = 0x4f05;                   //设置窗口页面控制功能号
	regs.x.bx = 0;
	if (flag == 0)                      //如果是第一次换页
	{
		old_page = page;
		regs.x.dx = page;
		int86(0x10, &regs, &regs);
		flag++;
	}
	else if (page != old_page)    //如果和上次页面号不同，则进行换页
	{
		old_page = page;
		regs.x.dx = page;
		int86(0x10, &regs, &regs);
	}
}
int huge Return_SVGA256()
{
	return 2;
}
void SVGAinit()
{
	// union REGS In,Out;
	// In.x.ax = 0x4f02;
	// In.x.bx = 0x101;
	// int86(0x10,&In,&Out);
	int i=DETECT,j=0;
	installuserdriver("Svga256",Return_SVGA256);
	initgraph(&i,&j,"");

}
void SVGAPlanefind(int plane)
{
		asm mov ax,0x4f05
		asm mov bx,0
		asm mov dx,plane
		asm int 10h
		// union REGS regs;
		// regs.x.ax = 0x4f05;                   //设置窗口页面控制功能号
		// regs.x.bx = 0;
		// regs.x.dx = plane;
		// int86(0x10, &regs, &regs);
}
void SVGA640(char *filename,int videoTop,int videoButtom)
{
	//SVGAinit();
	char far* pRM = (char far *)0xA0000000L;//内存段的初始地址
	FILE *f1;
	f1 = fopen(filename, "rb");
	unsigned int *pictureBuffer=NULL;
	unsigned int *Buffer1=NULL;
	unsigned int *Buffer2=NULL;
	pictureBuffer = (unsigned int *)malloc(640);//每次读4行进去
	Buffer1 = (unsigned int *)malloc(384);//存跳变量
	Buffer2 = (unsigned int *)malloc(256);//存另外一块跳变量
	int plane=0;//待选平面
	int lines=0;//遍历行数
	
	fseek(f1,1078,SEEK_SET);
//640*480的写入方式和之前的不一样，因为640不是1024的倍数，因此会在一个位面里面出现空余点，这个时候一定要单独写，根据计算
//每102行256个byte的内容，切换一次位面，因此采取手动切换页面，循环写入的方法
//PLANE 0
SVGAPlanefind(4);
for(lines=70-videoButtom;lines>0;lines--)
	{
		fread(pictureBuffer,640, 1, f1);
		_fmemcpy(pRM+640*lines-384, pictureBuffer, 640);
	}
//这里要做一次变换，要填入到一块缓冲区内部
fread(Buffer1, 384, 1, f1);//这里存一块跳变区域
fread(Buffer2, 256, 1, f1);
_fmemcpy(pRM, Buffer2, 256);
//跳变区域1已经存入相应位置
SVGAPlanefind(3);//显存页变换
_fmemcpy(pRM+65152, Buffer1, 384);
//存跳变区域2
for(lines=101;lines>0;lines--)
	{
		fread(pictureBuffer,640, 1, f1);
		_fmemcpy(pRM+640*lines-128, pictureBuffer, 640);
	}
//区域二已经完成跳转,显存剩余512bytes
fread(Buffer2, 128, 1, f1);//128bytes的跳变区域
fread(pictureBuffer, 512, 1, f1);
_fmemcpy(pRM, pictureBuffer, 512);
//显存已经用完
SVGAPlanefind(2);
//切换到下一页显示
_fmemcpy(pRM+65408, Buffer2, 128);//完成跳变区传送
//进入下一行绘制扫描
for(lines=101;lines>0;lines--)
	{
		fread(pictureBuffer,640, 1, f1);
		_fmemcpy(pRM+640*lines+128, pictureBuffer, 640);//加128的含义是因为2号区域x坐标是512，加128可以换到下一行最左侧
	}
// //显存剩余768
fread(pictureBuffer,640, 1, f1);
_fmemcpy(pRM+128, pictureBuffer, 640);//重建一行
// //显存剩余128bytes
// //下面是一块128bytes的跳变区域
fread(pictureBuffer,512, 1, f1);//跳变区
fread(Buffer2,128, 1, f1);//跳变区域
_fmemcpy(pRM, Buffer2, 128);//跳变区存储
SVGAPlanefind(1);//切换页
_fmemcpy(pRM+65024, pictureBuffer, 512);
//开始循环写入
for(lines=100;lines>0;lines--)
	{
		fread(pictureBuffer,640, 1, f1);
		_fmemcpy(pRM+640*lines+384L, pictureBuffer, 640);//加384的含义和上面一致
	}
	fread(pictureBuffer,640,1,f1);
	_fmemcpy(pRM+384, pictureBuffer, 640);

 	fread(Buffer2,256, 1, f1);
	fread(pictureBuffer,384, 1, f1);
 	_fmemcpy(pRM, pictureBuffer, 384);//重建一行
	SVGAPlanefind(0);
	_fmemcpy(pRM+65280, Buffer2, 256);

for(lines=102;lines>=videoTop;lines--)
	{
		fread(pictureBuffer,640, 1, f1);
		_fmemcpy(pRM+640*lines, pictureBuffer, 640);
	}
	free(Buffer1);
	free(Buffer2);
	free(pictureBuffer);
	fclose(f1);
}
void plattleChange()
{
	int n=0;
	unsigned long int COLORTABLE[256] = {
		0x000000,
		0x800000,
		0x008000,
		0x808000,
		0x000080,
		0x800080,
		0x008080,
		0x808080,
		0xc0dcc0,
		0xa6caf0,
		0x2a3faa,
		0x2a3fff,
		0x2a5f00,
		0x2a5f55,
		0x2a5faa,
		0x2a5fff,
		0x2a7f00,
		0x2a7f55,
		0x2a7faa,
		0x2a7fff,
		0x2a9f00,
		0x2a9f55,
		0x2a9faa,
		0x2a9fff,
		0x2abf00,
		0x2abf55,
		0x2abfaa,
		0x2abfff,
		0x2adf00,
		0x2adf55,
		0x2adfaa,
		0x2adfff,
		0x2aff00,
		0x2aff55,
		0x2affaa,
		0x2affff,
		0x550000,
		0x550055,
		0x5500aa,
		0x5500ff,
		0x551f00,
		0x551f55,
		0x551faa,
		0x551fff,
		0x553f00,
		0x553f55,
		0x553faa,
		0x553fff,
		0x555f00,
		0x555f55,
		0x555faa,
		0x555fff,
		0x557f00,
		0x557f55,
		0x557faa,
		0x557fff,
		0x559f00,
		0x559f55,
		0x559faa,
		0x559fff,
		0x55bf00,
		0x55bf55,
		0x55bfaa,
		0x55bfff,
		0x55df00,
		0x55df55,
		0x55dfaa,
		0x55dfff,
		0x55ff00,
		0x55ff55,
		0x55ffaa,
		0x55ffff,
		0x7f0000,
		0x7f0055,
		0x7f00aa,
		0x7f00ff,
		0x7f1f00,
		0x7f1f55,
		0x7f1faa,
		0x7f1fff,
		0x7f3f00,
		0x7f3f55,
		0x7f3faa,
		0x7f3fff,
		0x7f5f00,
		0x7f5f55,
		0x7f5faa,
		0x7f5fff,
		0x7f7f00,
		0x7f7f55,
		0x7f7faa,
		0x7f7fff,
		0x7f9f00,
		0x7f9f55,
		0x7f9faa,
		0x7f9fff,
		0x7fbf00,
		0x7fbf55,
		0x7fbfaa,
		0x7fbfff,
		0x7fdf00,
		0x7fdf55,
		0x7fdfaa,
		0x7fdfff,
		0x7fff00,
		0x7fff55,
		0x7fffaa,
		0x7fffff,
		0xaa0000,
		0xaa0055,
		0xaa00aa,
		0xaa00ff,
		0xaa1f00,
		0xaa1f55,
		0xaa1faa,
		0xaa1fff,
		0xaa3f00,
		0xaa3f55,
		0xaa3faa,
		0xaa3fff,
		0xaa5f00,
		0xaa5f55,
		0xaa5faa,
		0xaa5fff,
		0xaa7f00,
		0xaa7f55,
		0xaa7faa,
		0xaa7fff,
		0xaa9f00,
		0xaa9f55,
		0xaa9faa,
		0xaa9fff,
		0xaabf00,
		0xaabf55,
		0xaabfaa,
		0xaabfff,
		0xaadf00,
		0xaadf55,
		0xaadfaa,
		0xaadfff,
		0xaaff00,
		0xaaff55,
		0xaaffaa,
		0xaaffff,
		0xd40000,
		0xd40055,
		0xd400aa,
		0xd400ff,
		0xd41f00,
		0xd41f55,
		0xd41faa,
		0xd41fff,
		0xd43f00,
		0xd43f55,
		0xd43faa,
		0xd43fff,
		0xd45f00,
		0xd45f55,
		0xd45faa,
		0xd45fff,
		0xd47f00,
		0xd47f55,
		0xd47faa,
		0xd47fff,
		0xd49f00,
		0xd49f55,
		0xd49faa,
		0xd49fff,
		0xd4bf00,
		0xd4bf55,
		0xd4bfaa,
		0xd4bfff,
		0xd4df00,
		0xd4df55,
		0xd4dfaa,
		0xd4dfff,
		0xd4ff00,
		0xd4ff55,
		0xd4ffaa,
		0xd4ffff,
		0xff0055,
		0xff00aa,
		0xff1f00,
		0xff1f55,
		0xff1faa,
		0xff1fff,
		0xff3f00,
		0xff3f55,
		0xff3faa,
		0xff3fff,
		0xff5f00,
		0xff5f55,
		0xff5faa,
		0xff5fff,
		0xff7f00,
		0xff7f55,
		0xff7faa,
		0xff7fff,
		0xff9f00,
		0xff9f55,
		0xff9faa,
		0xff9fff,
		0xffbf00,
		0xffbf55,
		0xffbfaa,
		0xffbfff,
		0xffdf00,
		0xffdf55,
		0xffdfaa,
		0xffdfff,
		0xffff55,
		0xffffaa,
		0xccccff,
		0xffccff,
		0x33ffff,
		0x66ffff,
		0x99ffff,
		0xccffff,
		0x007f00,
		0x007f55,
		0x007faa,
		0x007fff,
		0x009f00,
		0x009f55,
		0x009faa,
		0x009fff,
		0x00bf00,
		0x00bf55,
		0x00bfaa,
		0x00bfff,
		0x00df00,
		0x00df55,
		0x00dfaa,
		0x00dfff,
		0x00ff55,
		0x00ffaa,
		0x2a0000,
		0x2a0055,
		0x2a00aa,
		0x2a00ff,
		0x2a1f00,
		0x2a1f55,
		0x2a1faa,
		0x2a1fff,
		0x2a3f00,
		0x2a3f55,
		0xfffbf0,
		0xa0a0a4,
		0x808080,
		0xff0000,
		0x00ff00,
		0xffff00,
		0x0000ff,
		0xff00ff,
		0x00ffff,
		0xffffff,
	}; // windows系统配色
	DacPalette256 RGBTABLE={0};
	for(n=0;n<256;n++)
	{
		RGBTABLE[n][0]=COLORTABLE[n]>>18;//R
		RGBTABLE[n][1]=((COLORTABLE[n]>>8)&0xFF)>>2;//R
		RGBTABLE[n][2]=(COLORTABLE[n]&0xFF)>>2;//R
	}
	setvgapalette256(&RGBTABLE);
}