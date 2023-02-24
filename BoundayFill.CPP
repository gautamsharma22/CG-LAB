#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void bfill(int x, int y, int fill, int boundary)
{
int current=getpixel(x,y);
if(current!=boundary && current!=fill){
putpixel(x,y,fill);

bfill(x,y,fill,boundary);
bfill(x+1,y,fill,boundary);
bfill(x,y+1,fill,boundary);
bfill(x+1,y+1,fill,boundary);
bfill(x-1,y,fill,boundary);
bfill(x,y-1,fill,boundary);
bfill(x-1,y-1,fill,boundary);
bfill(x,y-1,fill,boundary);

}
}
void main(){
int gm,gd=DETECT;
initgraph(&gd,&gd,"C:\\turboc3\\bgi");
rectangle(50,50,100,100);
int boundary=15;
int fill=3;
bfill(55,55,fill,boundary);
getch();
}