#include <stdio.h>
#include <dos.h>
#include <pages.h>
#include <graphics.h>
#include <IMAGE.h>
#include <stdlib.h>
int scrollBar(int *xy,int *button)
{
    //先给定一个指定的滑动范围，之后再把滑动栏范围改成函数参数
    //初始点定位(152,112)   (616,479)
	int yBlock = 142;
	int blockMove = 0;
    //控制量声明
    int TEMP=0,TEMP2;
	int linesU = 0,linesD = 0;
    //mouseCreate();
	union REGS InU,OutU,InD,OutD;
	InU.h.ah = 0x6;InU.h.bh = WHITE;
	InU.h.ch = 7;InU.h.cl = 19;//左上角相对系坐标
	InU.h.dh = 29;InU.h.dl = 76;//右下角相对系坐标
	InU.h.al = 1;
	InD.h.ah = 0x7;InD.h.bh = WHITE;
	InD.h.ch = 7;InD.h.cl = 19;
	InD.h.dh = 29;InD.h.dl = 76;
	InD.h.al = 1;
    int polyU[8]={616,112,639,112,639,141,616,141};
    int polyD[8]={616,449,639,449,639,479,616,479};
    //注意，上面的右下角拖动栏x坐标和滑动拖动栏左边缘x的关系为(x+1)*8=dx
    setfillstyle(1,CYAN);
    fillpoly(4,polyU);
    fillpoly(4,polyD);
    setcolor(BLACK);
    line(616,142,616,449);
    line(639,449,639,142);
    arrows();
    image16(152,112,".\\Study.bmp");
    drawBlock(yBlock);//初始块
	while(1)
	{
	    mousexy(xy,button);
        newmouse(&MouseX,&MouseY,&press);
        if(xy[0]<616&&xy[1]<112)
        {
            if(xy[0]<=580&&xy[0]>=639&&xy[1]<=0&&xy[1]>=40)
            continue;
        }
		if(xy[0]>616&&xy[0]<639&&xy[1]>449&&xy[1]<479&&button[0]==1)//UP 点上面图片图片要向上移动一个单位xy[0]>616&&xy[0]<639&&xy[1]>112&&xy[1]<141&&button[0]==1
		{
            if(linesU==21)  continue;
			clrmous(MouseX,MouseY);
			int86(0x10,&InU,&OutU);
			//mousevisiual();
            setfillstyle(1,WHITE);
            putpiece(".\\Study.bmp",0,linesU);//显示下面的内容
            bar(617,yBlock,638,yBlock+14);
            yBlock+=14;
			drawBlock(yBlock);
            delay(50);
            linesU++;
            linesD--;
		}
		if(xy[0]>616&&xy[0]<639&&xy[1]>112&&xy[1]<141&&button[0]==1)//DOWN 点下面图要向下移动一个单位xy[0]>616&&xy[0]<639&&xy[1]>449&&xy[1]<479&&button[0]==1
		{
            if(linesU==0)   continue;
			clrmous(MouseX,MouseY);
			int86(0x10,&InD,&OutD);
			//mousevisiual();
            setfillstyle(1,WHITE);
            putpiece(".\\Study.bmp",1,linesD);//显示上面的内容
            bar(617,yBlock,638,yBlock+14);
            yBlock-=14;
			drawBlock(yBlock);
            delay(50);
            linesD++;
            linesU--;
		}
            if(mousex()>617&&mousex()<639&&mousey()>yBlock&&mousey()<(yBlock+12)&&button[0]==1&&yBlock>=142&&yBlock<=450)//滑块的下滑控制
            {
            while(mouseLeftStatus()==1)//使滑块总是跟随数遍指针
            {
            if(blockMove==0)    clrmous(MouseX,MouseY);
            blockMove=1;
            TEMP2=mousey();
            if(TEMP2<=142||TEMP2>=449)  continue;
            setfillstyle(1,WHITE);
            delay(20);
            TEMP = mousey();
            if(TEMP==TEMP2) continue;
            if(TEMP>TEMP2)
            {
            if((TEMP-yBlock)<14)    continue;
            if(linesU==21)  continue;
            clrmous(MouseX,MouseY);
            bar(617,yBlock,638,yBlock+14);
			//yBlock = TEMP-4;
            yBlock+=14;
			drawBlock(yBlock);
            //mousevisiual();
            clrmous(MouseX,MouseY);;
            int86(0x10,&InU,&OutU);
            //mousevisiual();
            putpiece(".\\Study.bmp",0,linesU);
            linesU++;
            linesD--;
            delay(20);
            }
            if(TEMP<TEMP2)
            {
            if((TEMP-yBlock)<0)    continue;
            if(linesU==0)  continue;
            clrmous(MouseX,MouseY);;
            bar(617,yBlock,638,yBlock+14);
			//yBlock = TEMP-4;
            yBlock-=14;
			drawBlock(yBlock);
            //mousevisiual();
            //if(linesU==0)  continue;
            clrmous(MouseX,MouseY);;
            int86(0x10,&InD,&OutD);
            //mousevisiual();
            putpiece(".\\Study.bmp",1,linesD);
            linesU--;
            linesD++;
            delay(20);
            }
            }
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+linesD*16)&&(xy[1]<211+linesD*16)&&button[0]==1&&linesU>=0&&linesU<7)//Video0
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\lanqiu";
		 videoControl(filename,397,xy,button);
         closegraph();
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112+linesD*16)&&(xy[1]<211+112+linesD*16)&&button[0]==1&&linesU>=0&&linesU<14)//Video1
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\yunqiu";
		 videoControl(filename,333,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*2+linesD*16)&&(xy[1]<211+112*2+linesD*16)&&button[0]==1&&linesU>=0&&linesU<18)//Video2
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\Yujia";
		 videoControl(filename,1257,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*3+linesD*16)&&(xy[1]<211+112*3+linesD*16)&&button[0]==1)//Video4
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\Pingpong";
		 videoControl(filename,675,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*4+linesD*16)&&(xy[1]<211+112*4+linesD*16)&&button[0]==1)//Video5
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\Bad";
		 videoControl(filename,566,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*5+linesD*16)&&(xy[1]<211+112*5+linesD*16)&&button[0]==1)//Video6
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\football";
		 videoControl(filename,481,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(MY||EXPLORE||MISSION)//不要判断sign
        {
            setfillstyle(1,CYAN);
            clrmous(MouseX,MouseY);
            //mousehide();
            bar(38,242,102,274);
            hz32(38,242,0xCABE,WHITE);
	        hz32(70,242,0xBDCC,WHITE);
            //mousevisiual();
            return 0;
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40)
        {
			exit(0);
        }
	}
}
void arrows()
{
    //Arrow UP
    setcolor(WHITE);
    putpixel(627,121,WHITE);
    line(626,122,628,122);
    line(625,123,629,123);
    line(624,124,630,124);
    line(623,125,631,125);
    line(622,126,632,126);
    line(621,127,633,127);
    line(620,128,634,128);
    //Arrow DOWN
    putpixel(627,471,WHITE);
    line(626,470,628,470);
    line(625,469,629,469);
    line(624,468,630,468);
    line(623,467,631,467);
    line(622,466,632,466);
    line(621,465,633,465);
    line(620,464,634,464);
}
void drawBlock(int yU)
{
    //注意，这里画的是滑动块，由于X轴是不会变化的，所以只要变化Y轴即可，输入参数也是两个y的参数，分别是上方和下方
    //yU和yD之间相差12个像素
    int yD = yU+12;
    setfillstyle(1,LIGHTCYAN);
    int poly[8]={0};
    poly[0]=617;poly[2]=638;poly[4]=638;poly[6]=617;
    poly[1]=yU;poly[3]=yU;poly[5]=yD;poly[7]=yD;
    fillpoly(4,poly);
}
int scrollBarForExplore(int *xy,int *button)
{
    //先给定一个指定的滑动范围，之后再把滑动栏范围改成函数参数
    //初始点定位(152,112)   (616,479)
	int yBlock = 142;
	int blockMove = 0;
    //控制量声明
    int TEMP=0,TEMP2;
	int linesU = 0,linesD = 0;
    //mouseCreate();
	union REGS InU,OutU,InD,OutD;
	InU.h.ah = 0x6;InU.h.bh = WHITE;
	InU.h.ch = 7;InU.h.cl = 19;//左上角相对系坐标
	InU.h.dh = 29;InU.h.dl = 76;//右下角相对系坐标
	InU.h.al = 1;
	InD.h.ah = 0x7;InD.h.bh = WHITE;
	InD.h.ch = 7;InD.h.cl = 19;
	InD.h.dh = 29;InD.h.dl = 76;
	InD.h.al = 1;
    int polyU[8]={616,112,639,112,639,141,616,141};
    int polyD[8]={616,449,639,449,639,479,616,479};
    //注意，上面的右下角拖动栏x坐标和滑动拖动栏左边缘x的关系为(x+1)*8=dx
    setfillstyle(1,CYAN);
    fillpoly(4,polyU);
    fillpoly(4,polyD);
    setcolor(BLACK);
    line(616,142,616,449);
    line(639,449,639,142);
    arrows();
    image16(152,112,".\\Explore.bmp");
    drawBlock(yBlock);//初始块
	while(1)
	{
	    mousexy(xy,button);
        newmouse(&MouseX,&MouseY,&press);
        if(xy[0]<616&&xy[1]<112)
        {
            if(xy[0]<=580&&xy[0]>=639&&xy[1]<=0&&xy[1]>=40)
            continue;
        }
		if(xy[0]>616&&xy[0]<639&&xy[1]>449&&xy[1]<479&&button[0]==1)//UP 点上面图片图片要向上移动一个单位xy[0]>616&&xy[0]<639&&xy[1]>112&&xy[1]<141&&button[0]==1
		{
            if(linesU==21)  continue;
			clrmous(MouseX,MouseY);
			int86(0x10,&InU,&OutU);
			//mousevisiual();
            setfillstyle(1,WHITE);
            putpiece(".\\Explore.bmp",0,linesU);//显示下面的内容
            bar(617,yBlock,638,yBlock+14);
            yBlock+=14;
			drawBlock(yBlock);
            delay(50);
            linesU++;
            linesD--;
		}
		if(xy[0]>616&&xy[0]<639&&xy[1]>112&&xy[1]<141&&button[0]==1)//DOWN 点下面图要向下移动一个单位xy[0]>616&&xy[0]<639&&xy[1]>449&&xy[1]<479&&button[0]==1
		{
            if(linesU==0)   continue;
			clrmous(MouseX,MouseY);
			int86(0x10,&InD,&OutD);
			//mousevisiual();
            setfillstyle(1,WHITE);
            putpiece(".\\Explore.bmp",1,linesD);//显示上面的内容
            bar(617,yBlock,638,yBlock+14);
            yBlock-=14;
			drawBlock(yBlock);
            delay(50);
            linesD++;
            linesU--;
		}
            if(mousex()>617&&mousex()<639&&mousey()>yBlock&&mousey()<(yBlock+12)&&button[0]==1&&yBlock>=142&&yBlock<=450)//滑块的下滑控制
            {
            while(mouseLeftStatus()==1)//使滑块总是跟随数遍指针
            {
            if(blockMove==0)    clrmous(MouseX,MouseY);
            blockMove=1;
            TEMP2=mousey();
            if(TEMP2<=142||TEMP2>=449)  continue;
            setfillstyle(1,WHITE);
            delay(20);
            TEMP = mousey();
            if(TEMP==TEMP2) continue;
            if(TEMP>TEMP2)
            {
            if((TEMP-yBlock)<14)    continue;
            if(linesU==21)  continue;
            clrmous(MouseX,MouseY);
            bar(617,yBlock,638,yBlock+14);
			//yBlock = TEMP-4;
            yBlock+=14;
			drawBlock(yBlock);
            //mousevisiual();
            clrmous(MouseX,MouseY);;
            int86(0x10,&InU,&OutU);
            //mousevisiual();
            putpiece(".\\Explore.bmp",0,linesU);
            linesU++;
            linesD--;
            delay(20);
            }
            if(TEMP<TEMP2)
            {
            if((TEMP-yBlock)<0)    continue;
            if(linesU==0)  continue;
            clrmous(MouseX,MouseY);;
            bar(617,yBlock,638,yBlock+14);
			//yBlock = TEMP-4;
            yBlock-=14;
			drawBlock(yBlock);
            //mousevisiual();
            //if(linesU==0)  continue;
            clrmous(MouseX,MouseY);;
            int86(0x10,&InD,&OutD);
            //mousevisiual();
            putpiece(".\\Study.bmp",1,linesD);
            linesU--;
            linesD++;
            delay(20);
            }
            }
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+linesD*16)&&(xy[1]<211+linesD*16)&&button[0]==1&&linesU>=0&&linesU<7)//Video0
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\Footshow";
		 videoControl(filename,1328,xy,button);
         closegraph();
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112+linesD*16)&&(xy[1]<211+112+linesD*16)&&button[0]==1&&linesU>=0&&linesU<14)//Video1
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\Cobi";
		 videoControl(filename,2027,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*2+linesD*16)&&(xy[1]<211+112*2+linesD*16)&&button[0]==1&&linesU>=0&&linesU<18)//Video2
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\longrun";
		 videoControl(filename,1889,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*3+linesD*16)&&(xy[1]<211+112*3+linesD*16)&&button[0]==1)//Video4
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\jingdu";
		 videoControl(filename,1044,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*4+linesD*16)&&(xy[1]<211+112*4+linesD*16)&&button[0]==1)//Video5
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\WSceens";
		 videoControl(filename,1044,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
        if(xy[0]>151&&xy[0]<608&&(xy[1]>112+112*5+linesD*16)&&(xy[1]<211+112*5+linesD*16)&&button[0]==1)//Video6
        {
         EGAinit();
         mouseinit();
		 char filename[40]=".\\IMAGES\\food";
		 videoControl(filename,500,xy,button);
		 graphinit();
         pageOrigin(xy,button);
         mouseinit();
         xy[0]=0;xy[1]=0;
         return 1;
        }
		if(MY||STUDY||MISSION)//不要判断sign
        {
            setfillstyle(1,CYAN);
            clrmous(MouseX,MouseY);
            //mousehide();
            bar(38,310,102,342);
            hz32(38,310,0xCCBD,WHITE);
            hz32(70,310,0xCBF7,WHITE);
            //mousevisiual();
            return 0;
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40)
        {
			exit(0);
        }
	}
}