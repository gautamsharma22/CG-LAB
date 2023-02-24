#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main() {
float x,y,xc=100,yc=100,p=0,r=0;
int gd,gm;
gd=DETECT,gm;
initgraph(&gd,&gm,"C://TURBOC3//BGI");
printf("Enter Radius :");
scanf("%f",&r);
x=0;
y=r;
p=3-2*r;
do{
putpixel(x+xc,y+yc,4);
putpixel(-x+xc,y+yc,4);
putpixel(x+xc,-y+yc,4);
putpixel(-x+xc,-y+yc,4);
putpixel(y+xc,x+yc,4);
putpixel(y+xc,-x+yc,4);
putpixel(-y+xc,x+yc,4);
putpixel(-y+xc,-x+yc,4);
	if(p<0){
		x++;
		p=p+4*x+6;
	}else{
		x++;
		y--;
		p=p+4*x-4*y+10;
	}

}while(x<y);
getch();
}
