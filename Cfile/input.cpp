#include "./include/common.h"
#include "./include/input.h"
/*-----------------------------------------------------------------------------------------------------------
函数名:int py_input_main(int x1,int y1,int x2,int y2,char hz_in[][3],int num_len)
函数功能：实现汉字的输入;汉字拼音输入法
形参：输入框的坐标x,y,x,y;输入字符hz_in;以形参num_len实现函数间对于输入字符数量的传递;
返回值：对于输入字符数量的统计num_len;
-----------------------------------------------------------------------------------------------------------*/
int py_input_main(int x1,int y1,int x2,int y2,char hz_in[][3],int num_len)
{
	FILE *fp_py = NULL;
	void *buffer = NULL;
	int position = 0;
	unsigned s;
    int xy[2]={0},button[3]={0};
	char readTry[3] = "\0";
	char py1[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char *py = py1;
	char py_temp[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char hz[5][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
	int num1 = 0,letter_t = 0x0;
	int num2 = 0;
	int *num = &num1;
	int letter1,hznum = 0,distance = 46;
	int *letter_temp = &letter_t;
	int i = 0;
	char title[60] = "\0";
	char number_temp[3] = {'\0','\0','\0'};
	s = imagesize(x1-1,y2+5,x1+240+3,y2+49);
	buffer =(void *)malloc(s);
	mousehide();
	getimage(x1-1,y2+5,x1+240+3,y2+49,buffer);
	pyFrm(x1,y2+6,x1+240,y2+48);
	mousevisiual();
	delay(90);
	while(1) 
	{
		hznum = 0;
		textshow_py(x1+10,y2+12,x1+240-9,y2+26,12,num,12,py,letter_temp);
		if(strcmp(py,py_temp) != 0)
		{
			position = 0;
			fclose(fp_py);
		}
		if(num2 != *num)
		{
			setcolor(WHITE);
	        line(x1+10+(num2)*12-1,y2+12+3,x1+10+(num2)*12-1,y2+26-3);
		}
		py[*num] = '\0';
		num2 = *num;
		strcpy(py_temp,py);
		strcpy(title,".\\HZK\\pinyin\\");
		strcat(title,py);
		strcat(title,".txt");
		if((fp_py=fopen(title,"rt")) == NULL)
		{
			setfillstyle(1,WHITE);
			bar(x1+3,y2+27,x1+240+1-3,y2+45);
			for(i=0;i<5;i++)
			{
				strcpy(hz[i],"\0");
			}
			hznum = 0; 
		}
		if((*letter_temp)==0x0d3d)
		{
			while(i<=5)
			{
				fseek(fp_py,position,SEEK_SET);
				fread(readTry,2,1,fp_py);
				if(strcmp(readTry,"\0")==0)
				{
					strcpy(readTry,"\0");
					break;
				}
				i++;
				position += 2;
			}
			for(i=0;i<5;i++)
			{
				strcpy(hz[i],"\0");
			}
		}
		if((*letter_temp)==0x0c2d&&position >= 10)
		{
			position -= 10;
			for(i=0;i<5;i++)
			{
				strcpy(hz[i],"\0");
			}
		}
		if((*letter_temp)==0x0c2d&&position < 10)
		{
			position = 0;
		}
		fseek(fp_py,position,SEEK_SET);
		if(ferror(fp_py)==0)
		{
			for(i=0;i<5;i++)
			{
				fread(hz[i],2,1,fp_py);//读入一个汉字
				if(feof(fp_py))//读到文件尾
				{
					hznum=i+1;//按道理此处文件尾多读一次 需要减一  然而此处不减一的效果更好
				}
			
				if(!feof(fp_py))//未读到文件尾 全显汉字
				{
					hznum=5;
				}
			}
		}
		for(i=0;i<hznum;i++)
		{
			itoa(i+1,number_temp,10);
			strcat(number_temp,".");
			setfillstyle(1,WHITE);
			bar(x1+3+i*distance,y2+27,x1+240+1-3,y2+47);
			ShowNumberAndLetter(x1+3+distance*i,y2+47,number_temp,DARKGRAY);
			hz16sChanged(x1+3+distance*i+25,y2+48-18,hz[i],DARKGRAY);
		}
		if(((*letter_temp)==0x0231||(*letter_temp)==0x4f31)&&hz[0]!="\0")
		{
			putimage(x1-1,y2+5,buffer,0);
			hz16sChanged(x1+3+num_len*18,y1+3,hz[0],DARKGRAY);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len++;
			strcpy(hz_in[num_len-1],hz[0]);
			break;
		}
		if(((*letter_temp)==0x0332||(*letter_temp)==0x5032)&&hz[1]!="\0")
		{
			putimage(x1-1,y2+5,buffer,0);
			hz16sChanged(x1+3+num_len*18,y1+3,hz[1],DARKGRAY);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len++;
			strcpy(hz_in[num_len-1],hz[1]);
			break;
		}
		if(((*letter_temp)==0x0433||(*letter_temp)==0x5133)&&hz[2]!="\0")
		{
			putimage(x1-1,y2+5,buffer,0);
			hz16sChanged(x1+3+num_len*18,y1+3,hz[2],DARKGRAY);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len++;
			strcpy(hz_in[num_len-1],hz[2]);
			break;
		}
		if(((*letter_temp)==0x0534||(*letter_temp)==0x4b34)&&hz[3]!="\0")
		{
			putimage(x1-1,y2+5,buffer,0);
			hz16sChanged(x1+3+num_len*18,y1+3,hz[3],DARKGRAY);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len++;
			strcpy(hz_in[num_len-1],hz[3]);
			break;
		}
		if(((*letter_temp)==0x0635||(*letter_temp)==0x4c35)&&hz[4]!="\0")
		{
			putimage(x1-1,y2+5,buffer,0);
			hz16sChanged(x1+3+num_len*18,y1+3,hz[4],DARKGRAY);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len++;
			strcpy(hz_in[num_len-1],hz[4]);
			break;
		}
		if((*letter_temp)==0x1c0d)//回车退出
		{
			ShowNumberAndLetter(x1+3+num_len*18,y2-3,py,DARKGRAY);
			putimage(x1-1,y2+5,buffer,0);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			num_len+=strlen(py);
			break;
		}
		if((*letter_temp)==0x0e08&&*num<=0&&num_len>=1) //删除到没有字符再点击删除
		{
			setfillstyle(1,WHITE);
			bar(x1+3+(num_len - 1)*18,y1+2,x1+3+num_len*18,y2-2);
			*num = 0;
			num_len--;
			strcpy(hz_in[num_len+1],"\0");
			fclose(fp_py);
		}
		
		if((*num)>=12)//如果输入字符数量已超限额，退出
		{
			putimage(x1-1,y2+5,buffer,0);
			*num = 0;
			fclose(fp_py);
			free(buffer);
			break;
		}
	}
	return num_len;
}

/*-----------------------------------------------------------------------------------------------------------
函数名:int textshow_2(int xmin,int ymin,int xmax,int ymax,int maxlen,int *num,int interval,char *s,int judge,int page);
函数功能：实现字符的输入;实现对于输入字符数量的统计
形参：输入框的坐标xmin,ymin,xmax,ymax;输入字符数量限额maxlen;以形参num实现函数间对于输入字符数量的传递;
	 字符间的间距interval;*s;
返回值：无
-----------------------------------------------------------------------------------------------------------*/
void textshow_py(int xmin,int ymin,int xmax,int ymax,int maxlen,int *num,int interval,char *s,int *letter_temp)
{
    int letter;
    fflush(stdin);
	blink(xmin+(*num)*interval-1,ymin+3,xmin+(*num)*interval-1,ymax-3,xmin,ymin,xmax,ymax,DARKGRAY,WHITE);
	if(bioskey(1))
	{
		letter = bioskey(0);
		if(letter==0x0e08&&*num>0)//如果按下删除键且存在字符
		{
			setfillstyle(1,WHITE);
			bar(xmin+((*num)-1)*interval,ymin-3,xmin+(*num)*interval,ymax-1);//以白色实填矩形覆盖实现删去一个字符
			(*num)-=1;
			s[*num]='\0';
		}

		else
		{
			switch(letter)
			{
				case 0x1071:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"q",9);		
				s[*num] = 'q';
					break;

				case 0x1177:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"w",9);		
				s[*num] = 'w';
					break;

				case 0x1265:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"e",9);
				s[*num] = 'e';
					break;

				case 0x1372:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"r",9);
				s[*num] = 'r';
					break;
				
				case 0x1474:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"t",9);		
				s[*num] = 't';
					break;
				
				case 0x1579:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"y",9);		
				s[*num] = 'y';
					break;
				
				case 0x1675:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"u",9);		
				s[*num] = 'u';
					break;
				
				case 0x1769:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"i",9);		
				s[*num] = 'i';
					break;
				
				case 0x186f:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"o",9);		
				s[*num] = 'o';
					break;
				
				case 0x1970:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"p",9);		
				s[*num] = 'p';
					break;
				
				case 0x1e61:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"a",9);		
				s[*num] = 'a';
					break;
				
				case 0x1f73:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"s",9);		
				s[*num] = 's';
					break;
				
				case 0x2064:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"d",9);		
				s[*num] = 'd';
					break;
				
				case 0x2166:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"f",9);		
				s[*num] = 'f';
					break;
				
				case 0x2267:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"g",9);		
				s[*num] = 'g';
					break;
				
				case 0x2368:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"h",9);		
				s[*num] = 'h';
					break;
				
				case 0x246a:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"j",9);		
				s[*num] = 'j';
					break;
				
				case 0x256b:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"k",9);		
				s[*num] = 'k';
					break;
				
				case 0x266c:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"l",9);		
				s[*num] = 'l';
					break;
				
				case 0x2c7a:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"z",9);		
				s[*num] = 'z';
					break;
				
				case 0x2d78:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"x",9);		
				s[*num] = 'x';
					break;
				
				case 0x2e63:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"c",9);		
				s[*num] = 'c';
					break;
				
				case 0x2f76:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"v",9);		
				s[*num] = 'v';
					break;
				
				case 0x3062:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"b",9);		
				s[*num] = 'b';
					break;
				
				case 0x316e:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"n",9);		
				s[*num] = 'n';
					break;
				
				case 0x326d:
				ShowNumberAndLetter(xmin+(*num)*interval,ymax-1,"m",9);		
				s[*num] = 'm';
					break;
				
				default :
				(*letter_temp) = letter;
				(*num)--;
					break;
			}
			(*num)++;
		}
	}
}

/************************************************************************
FUNCTION:pyFrm
DESCRIPTION: 输入法小框
INPUT:x1,y1,x2,y2
RETURN:无
************************************************************************/
void pyFrm(int x1,int y1,int x2,int y2)
{
	circle_bar(x1,y1,x2,y2,DARKGRAY);
	circle_bar_2(x1,y1,x2,y2,WHITE);
	setcolor(LIGHTBLUE);
	setlinestyle(0,0,1);
	line(x1+5,y1+20,x2-5,y1+20);
}

