#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//图像数据压缩代码，读取文件类型为BMP文件，保存文件类型为.bin文件，bin文件只能以二进制打开，压缩标志位为424d之后跟的是重复数，跟着为重复数量，配套使用还有一个解码程序，配合使用可以将图片存储容量压缩
//五个字节为一个压缩单位。同时字节重复数大于5才才会执行压缩
//读5个字节，确认全部一致后进入压缩代码内容，之后再一次次判断读到的字节是否一致，直到不同的时候就退出并写入新的bin文件
void main()
{
	// int Sign = 0x424d;//标志量
	int repeatNum = 0;//重复数记录变量
	char R1=0,R2=0,R3=0;//读取暂存变量
	char RN = 0;
	FILE *fS;
	FILE *fF;
	fF = fopen("C:\\Test3.bmp","rb");
	fS = fopen("C:\\T2.BIN","wb");
	fseek(fF,118,SEEK_SET);//删除文件头
	while(feof(fF)==0)
	{
		fread(&R1,1,1,fF);
		if(feof(fF)!=0)	break;
		fread(&R2,1,1,fF);
		if(feof(fF)!=0)	break;
		fread(&R3,1,1,fF);
		if(R1==R2&&R1==R3&&R2==R3)//先判断读到的3个bit是不是一致的
		{
			repeatNum=3;
			while(1)
			{
				fread(&RN,1,1,fF);
				if(RN==R1)
				{
					repeatNum++;
				}
				else break;
			}//最后repeat就是最终重复次数
			//下面的代码是Break结束即已经完成计数的执行内容
			putw(repeatNum,fS);//重复量----->2byte
			putc(R1,fS);//重复元素
			putw(1,fS);
			putc(RN,fS);
			continue;
		}
		if(R1!=R2&&R1!=R3&&R2!=R3)
		{
			repeatNum=1;
			putw(repeatNum,fS);//重复量
			putc(R1,fS);//重复数

			putw(repeatNum,fS);//重复量
			putc(R2,fS);//重复数

			putw(repeatNum,fS);//重复量
			putc(R3,fS);//重复数
			//注意写入的顺序和读到的顺序是一样的
			continue;
		}
		if(R1==R2&&R1!=R3)
		{
			repeatNum=2;
			putw(repeatNum,fS);//重复量
			putc(R1,fS);//重复数
			repeatNum=1;
			putw(repeatNum,fS);//重复量
			putc(R3,fS);//重复数
			continue;
		}
		if(R1!=R2&&R2==R3)
		{
			repeatNum=1;
			putw(repeatNum,fS);//重复量
			putc(R1,fS);//重复数
			repeatNum=2;
			putw(repeatNum,fS);//重复量
			putc(R2,fS);//重复数
			continue;
		}
		if(R1==R3&&R1!=R2)
		{
			repeatNum=1;
			putw(repeatNum,fS);
			putc(R1,fS);

			repeatNum=1;
			putw(repeatNum,fS);
			putc(R2,fS);

			repeatNum=1;
			putw(repeatNum,fS);
			putc(R3,fS);
			continue;
		}
	}
	fclose(fF);
	fclose(fS);
}