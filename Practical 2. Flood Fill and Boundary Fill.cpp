#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
   

void boundaryFill8(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
	boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
	boundaryFill8(x, y - 1, fill_color, boundary_color);
    }
}

void fldfill(int x, int y, int fill,int old)
{
    int current=getpixel(x,y);
    if(current==old)
    {
      putpixel(x, y, fill);
	fldfill(x+1, y, fill, old);
	fldfill(x, y+1, fill, old);
	fldfill(x, y-1, fill, old);
	fldfill(x-1, y, fill, old);
    }
}

void main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    arc(100,100,0,90,50);
    arc(100,100,180,270,50);
    line(50,100,150,100);
    line(100,50,100,150);
    boundaryFill8(110,60,4,15);
    fldfill(60,110,12,0);
    getch();

}
