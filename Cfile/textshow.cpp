#include"./include/common.h"
#include"./include/user.h"
#include"./include/paint.h"
#include"./include/textshow.h"

/*-----------------------------------------------------------------------------------------------------------
函数名:int textshow(int xmin,int ymin,int xmax,int ymax,int maxlen,int num,int interval,char *s,int judge,int page);
函数功能：实现字符的输入;实现对于输入字符数量的统计
形参：输入框的坐标xmin,ymin,xmax,ymax;输入字符数量限额maxlen;以形参num实现函数间对于输入字符数量的传递;
	 字符间的间距interval;*s;judge为0则显示输入，为1则隐式输入(*);
返回值：对于输入字符数量的统计num;
-----------------------------------------------------------------------------------------------------------*/
int textshow(int xmin,int ymin,int xmax,int ymax,int maxlen,int num,int interval,char *s,int judge)
{
    int letter;
    while(bioskey(1))
    {
        getch(); //如缓存区中有按键返回值则清除
    }
    while(1)
    {
		blink(xmin+num*interval,ymin+3,xmin+num*interval,ymax-3,xmin,ymin,xmax,ymax,DARKGRAY,WHITE);
        /*if(mouse_press(xmin,ymin,xmax,ymax) ==4)
        {
            setcolor(WHITE);
            line(xmin+num*interval,ymin+3,xmin+num*interval,ymax-3);
            return num;
        }*/
        if(bioskey(1))
        {
            letter = bioskey(0);
            if(letter==0x0e08&&num>0)//如果按下删除键且存在字符
			{
				setfillstyle(1,WHITE);
				bar(xmin+(num-1)*interval,ymin+1,xmin+num*interval,ymax-1);//以白色实填矩形覆盖实现删去一个字符
				num-=1;
				s[num]='\0';
			}
			else if(letter==0x1c0d)//回车退出
				return num;
			else if(num>=maxlen)//如果输入字符数量已超限额，退出
				return num;
			else
			{
					switch(letter)
					{
						case 0x0231://主键盘键值
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"1",9);
						s[num] = '1';
							break;
						case 0x0332:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"2",9);
						s[num] = '2';
							break;
						case 0x0433:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"3",9);
						s[num] = '3';
							break;
						case 0x0534:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"4",9);
						s[num] = '4';
							break;
						case 0x0635:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"5",9);
						s[num] = '5';
							break;
						case 0x0736:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"6",9);
						s[num] = '6';
							break;
						case 0x0837:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"7",9);
						s[num] = '7';
							break;
						case 0x0938:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"8",9);		
						s[num] = '8';
							break;
						case 0x0a39:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"9",9);		
						s[num] = '9';
							break;
						case 0x0b30:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"0",9);		
						s[num] = '0';
							break;
						case 0x1071:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"q",9);		
						s[num] = 'q';
							break;
						case 0x1051:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"Q",9);
                        s[num]='Q';
                            break;
						case 0x1177:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"w",9);		
						s[num] = 'w';
							break;
						case 0x1157:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"W",9);
                        s[num]='W';
                            break;
						case 0x1265:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"e",9);	
						s[num] = 'e';
							break;
						case 0x1245:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"E",9);
                        s[num]='E';
                            break;
						case 0x1372:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"r",9);		
						s[num] = 'r';
							break;
						case 0x1352:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"R",9);
                        s[num]='R';
                            break;
						case 0x1474:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"t",9);		
						s[num] = 't';
							break;
						case 0x1454:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"T",9);
                        s[num]='T';
                            break;
						case 0x1579:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"y",9);		
						s[num] = 'y';
							break;
						case 0x1559:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"Y",9);
                        s[num]='Y';
                            break;
						case 0x1675:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"u",9);		
						s[num] = 'u';
							break;
						case 0x1655:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"U",9);
                        s[num]='U';
                            break;
						case 0x1769:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"i",9);		
						s[num] = 'i';
							break;
						case 0x1749:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"I",9);
                        s[num]='I';
                            break;
						case 0x186f:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"o",9);		
						s[num] = 'o';
							break;
						case 0x184f:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"O",9);
                        s[num]='O';
                            break;
						case 0x1970:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"p",9);		
						s[num] = 'p';
							break;
						case 0x1950:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"P",9);
                        s[num]='P';
                            break;
						case 0x1e61:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"a",9);		
						s[num] = 'a';
							break;
						case 0x1e41:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"A",9);
                        s[num]='A';
                            break;
						case 0x1f73:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"s",9);		
						s[num] = 's';
							break;
						case 0x1f53:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"S",9);
                        s[num]='S';
                            break;
						case 0x2064:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"d",9);		
						s[num] = 'd';
							break;
						case 0x2044:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"D",9);
                        s[num]='D';
                            break;
						case 0x2166:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"f",9);		
						s[num] = 'f';
							break;
						case 0x2146:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"F",9);
                        s[num]='F';
                            break;
						case 0x2267:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"g",9);		
						s[num] = 'g';
							break;
						case 0x2247:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"G",9);
                        s[num]='G';
                            break;
						case 0x2368:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"h",9);		
						s[num] = 'h';
							break;
						case 0x2348:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"H",9);
                        s[num]='H';
                            break; 
						case 0x246a:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"j",9);		
						s[num] = 'j';
							break;
						case 0x244a:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"J",9);
                        s[num]='J';
                            break;
						case 0x256b:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"k",9);		
						s[num] = 'k';
							break;
						case 0x254b:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"K",9);
                        s[num]='K';
                            break;
						case 0x266c:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"l",9);		
						s[num] = 'l';
							break;
						case 0x264c:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"L",9);
                        s[num]='L';
                            break;
						case 0x2c7a:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"z",9);		
						s[num] = 'z';
							break;
							case 0x2c5a:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"Z",9);
                        s[num]='Z';
                            break;
						case 0x2d78:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"x",9);		
						s[num] = 'x';
							break;
						case 0x2d58:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"X",9);
                        s[num]='X';
                            break;
						case 0x2e63:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"c",9);		
						s[num] = 'c';
							break;
						case 0x2e43:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"C",9);
                        s[num]='C';
                            break;
						case 0x2f76:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"v",9);		
						s[num] = 'v';
							break;
						case 0x2f56:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"V",9);
                        s[num]='V';
                            break;
						case 0x3062:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"b",9);		
						s[num] = 'b';
							break;
						case 0x3042:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"B",9);
                        s[num]='B';
                            break;
						case 0x316e:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"n",9);		
						s[num] = 'n';
							break;
						case 0x314e:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"N",9);
                        s[num]='N';
                            break;
						case 0x326d:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"m",9);		
						s[num] = 'm';
							break;
						case 0x324d:
                        ShowNumberAndLetter(xmin+num*interval,ymax,"M",9);
                        s[num]='M';
                            break;
						case 0x0c2d:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"-",9);		
						s[num] = '-';
							break;
						case 0x342e:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,".",9);
						s[num]='.';
							break;
						case 0x4f31://机械键盘右边小键盘
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"1",9);		
						s[num] = '1';
							break;
						case 0x5032:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"2",9);		
						s[num] = '2';
							break;
						case 0x5133:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"3",9);		
						s[num] = '3';
							break;
						case 0x4b34:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"4",9);		
						s[num] = '4';
							break;
						case 0x4c35:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"5",9);		
						s[num] = '5';
							break;
						case 0x4d36:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"6",9);		
						s[num] = '6';
							break;
						case 0x4737:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"7",9);
						s[num] = '7';
							break;
						case 0x4838:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"8",9);		
						s[num] = '8';
							break;
						case 0x4939:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"9",9);		
						s[num] = '9';
							break;
						case 0x5230:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"0",9);		
						s[num] = '0';
							break;
						case 0x4a2d:
						ShowNumberAndLetter(xmin+num*interval,ymax-5,"-",9);		
						s[num] = '-';
							break;
						default :
						num--;
							break;
					}
					num++;
			}
		}
	}
}

/*输入字符的显隐,参数同上*/
int textshow_pro(int xmin,int ymin,int xmax,int ymax,int maxlen,int num,int interval,char *s)
{
	int letter;
    while(bioskey(1))
    {
        getch(); //如缓存区中有按键返回值则清除
    }
	while(1)
	{
		blink(xmin+num*interval,ymin+3,xmin+num*interval,ymax-3,xmin,ymin,xmax,ymax,DARKGRAY,WHITE);
		if(mouse_press(xmin,ymin,xmax,ymax) ==4)
		{
			setcolor(WHITE);
			line(xmin+num*interval,ymin+3,xmin+num*interval,ymax-3);
			return num;
		}
		if(bioskey(1))
		{
			letter = bioskey(0);
			if(letter==0x0e08&&num>0)//如果按下删除键且存在字符
			{
				setfillstyle(1,WHITE);
				bar(xmin+(num-1)*interval,ymin+1,xmin+num*interval,ymax-1);//以白色实填矩形覆盖实现删去一个字符
				num-=1;
				s[num]='\0';
			}
			else if(letter==0x1c0d)//回车退出
				return num;
			else if(num>=maxlen)//如果输入字符数量已超限额，退出
				return num;
			else
			{
				switch(letter)
				{
					case 0x0231://主键盘键值
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"1",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '1';
						break;
					case 0x0332:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"2",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '2';
						break;
					case 0x0433:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"3",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '3';
						break;
					case 0x0534:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"4",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '4';
						break;
					case 0x0635:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"5",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '5';
						break;
					case 0x0736:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"6",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '6';
						break;
					case 0x0837:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"7",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '7';
						break;
					case 0x0938:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"8",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '8';
						break;
					case 0x0a39:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"9",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '9';
						break;
					case 0x0b30:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"0",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '0';
						break;
					case 0x1071:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"q",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'q';
						break;
					case 0x1051:
					ShowNumberAndLetter(xmin+num*interval,ymax,"Q",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='Q';
						break;
					case 0x1177:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"w",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = 'w';
						break;
					case 0x1157:
					ShowNumberAndLetter(xmin+num*interval,ymax,"W",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='W';
						break;
					case 0x1265:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"e",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = 'e';
						break;
					case 0x1245:
					ShowNumberAndLetter(xmin+num*interval,ymax,"E",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='E';
						break;
					case 0x1372:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"r",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'r';
						break;
					case 0x1352:
					ShowNumberAndLetter(xmin+num*interval,ymax,"R",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='R';
						break;
					case 0x1474:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"t",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 't';
						break;
					case 0x1454:
					ShowNumberAndLetter(xmin+num*interval,ymax,"T",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='T';
						break;
					case 0x1579:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"y",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'y';
						break;
					case 0x1559:
					ShowNumberAndLetter(xmin+num*interval,ymax,"Y",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='Y';
						break;
					case 0x1675:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"u",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'u';
						break;
					case 0x1655:
					ShowNumberAndLetter(xmin+num*interval,ymax,"U",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='U';
						break;
					case 0x1769:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"i",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'i';
						break;
					case 0x1749:
					ShowNumberAndLetter(xmin+num*interval,ymax,"I",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='I';
						break;
					case 0x186f:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"o",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'o';
						break;
					case 0x184f:
					ShowNumberAndLetter(xmin+num*interval,ymax,"O",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='O';
						break;
					case 0x1970:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"p",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'p';
						break;
					case 0x1950:
					ShowNumberAndLetter(xmin+num*interval,ymax,"P",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='P';
						break;
					case 0x1e61:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"a",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'a';
						break;
					case 0x1e41:
					ShowNumberAndLetter(xmin+num*interval,ymax,"A",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='A';
						break;
					case 0x1f73:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"s",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 's';
						break;
					case 0x1f53:
					ShowNumberAndLetter(xmin+num*interval,ymax,"S",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='S';
						break;
					case 0x2064:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"d",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'd';
						break;
					case 0x2044:
					ShowNumberAndLetter(xmin+num*interval,ymax,"D",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='D';
						break;
					case 0x2166:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"f",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'f';
						break;
					case 0x2146:
					ShowNumberAndLetter(xmin+num*interval,ymax,"F",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='F';
						break;
					case 0x2267:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"g",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'g';
						break;
					case 0x2247:
					ShowNumberAndLetter(xmin+num*interval,ymax,"G",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='G';
						break;
					case 0x2368:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"h",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'h';
						break;
					case 0x2348:
					ShowNumberAndLetter(xmin+num*interval,ymax,"H",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='H';
						break; 
					case 0x246a:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"j",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'j';
						break;
					case 0x244a:
					ShowNumberAndLetter(xmin+num*interval,ymax,"J",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='J';
						break;
					case 0x256b:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"k",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'k';
						break;
					case 0x254b:
					ShowNumberAndLetter(xmin+num*interval,ymax,"K",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='K';
						break;
					case 0x266c:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"l",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = 'l';
						break;
					case 0x264c:
					ShowNumberAndLetter(xmin+num*interval,ymax,"L",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='L';
						break;
					case 0x2c7a:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"z",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'z';
						break;
						case 0x2c5a:
					ShowNumberAndLetter(xmin+num*interval,ymax,"Z",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='Z';
						break;
					case 0x2d78:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"x",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'x';
						break;
					case 0x2d58:
					ShowNumberAndLetter(xmin+num*interval,ymax,"X",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='X';
						break;
					case 0x2e63:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"c",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'c';
						break;
					case 0x2e43:
					ShowNumberAndLetter(xmin+num*interval,ymax,"C",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='C';
						break;
					case 0x2f76:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"v",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'v';
						break;
					case 0x2f56:
					ShowNumberAndLetter(xmin+num*interval,ymax,"V",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='V';
						break;
					case 0x3062:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"b",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'b';
						break;
					case 0x3042:
					ShowNumberAndLetter(xmin+num*interval,ymax,"B",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='B';
						break;
					case 0x316e:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"n",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'n';
						break;
					case 0x314e:
					ShowNumberAndLetter(xmin+num*interval,ymax,"N",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='N';
						break;
					case 0x326d:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"m",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = 'm';
						break;
					case 0x324d:
					ShowNumberAndLetter(xmin+num*interval,ymax,"M",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='M';
						break;
					case 0x0c2d:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"-",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '-';
						break;
					case 0x342e:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,".",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num]='.';
						break;
					case 0x4f31://机械键盘右边小键盘
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"1",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '1';
						break;
					case 0x5032:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"2",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '2';
						break;
					case 0x5133:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"3",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '3';
						break;
					case 0x4b34:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"4",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '4';
						break;
					case 0x4c35:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"5",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '5';
						break;
					case 0x4d36:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"6",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '6';
						break;
					case 0x4737:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"7",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");
					s[num] = '7';
						break;
					case 0x4838:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"8",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '8';
						break;
					case 0x4939:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"9",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '9';
						break;
					case 0x5230:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"0",9);	
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");	
					s[num] = '0';
						break;
					case 0x4a2d:
					ShowNumberAndLetter(xmin+num*interval,ymax-5,"-",9);
					delay(100);
					setcolor(DARKGRAY);
					setfillstyle(1,WHITE);
					bar(xmin+num*interval,ymin+1,xmin+(num+1)*interval,ymax-1);
					ShowCharacter(xmin+num*interval,ymax-5,"*");		
					s[num] = '-';
						break;
					default :
					num--;
						break;
				}
				num ++;
			}
        }
	}
}