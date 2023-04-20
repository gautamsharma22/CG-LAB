#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void bfill(int x, int y, int fill, int bound)
{
 int current=getpixel(x,y);
 if(current!=bound && current!=fill)
 {
  putpixel(x,y,fill);
  bfill(x,y+1,fill,bound);
  bfill(x+1,y,fill,bound);
  bfill(x,y-1,fill,bound);
  bfill(x-1,y,fill,bound);

  bfill(x-1,y-1,fill,bound);
  bfill(x+1,y+1,fill,bound);
  bfill(x+1,y-1,fill,bound);
  bfill(x-1,y+1,fill,bound);
 }
}

void ffill(int x, int y, int fill, int old)
{
 int current=getpixel(x,y);
 if(current==old)
 {
  putpixel(x,y,fill);
  ffill(x,y+1,fill,old);
  ffill(x+1,y,fill,old);
  ffill(x,y-1,fill,old);
  ffill(x-1,y,fill,old);

  ffill(x-1,y-1,fill,old);
  ffill(x+1,y+1,fill,old);
  ffill(x+1,y-1,fill,old);
  ffill(x-1,y+1,fill,old);
 }
}

void main()
{
 int gd=DETECT, gm;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");

 rectangle(10,10,90,90);
 line(10,50,90,50);
 bfill(30,30,15,15);
 ffill(70,70,2,0);
 getch();
}
