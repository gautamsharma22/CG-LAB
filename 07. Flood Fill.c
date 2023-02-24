#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void flood(int x, int y, int n, int old)
{
getpixel(x,y);
if(getpixel(x,y)==old){
putpixel(x,y,n);
flood(x,y,n,old);
flood(x+1,y,n,old);
flood(x,y+1,n,old);
flood(x+1,y+1,n,old);
flood(x-1,y,n,old);
flood(x,y-1,n,old);
flood(x-1,y-1,n,old);
flood(x,y-1,n,old);

}
}
int main(){
int gm,gd=DETECT;
initgraph(&gd,&gd,"C:\\turboc3\\bgi");
rectangle(100,100,200,200);
flood(101,101,10,0);
getch();
return 0;
}
