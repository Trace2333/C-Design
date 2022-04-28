#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <IMAGE.h>
/*用于图形模式的初始化*/
void graphinit()
{
    int i=VGA,j=VGAHI;
    initgraph(&i,&j,"C:\\BORLANDC\\BGI");
	outportb(0x3c8,1);
	outportb(0x3c9,0);
	outportb(0x3c9,0);
	outportb(0x3c9,0);
}
