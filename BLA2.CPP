#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main() {
float x=0,y=0,x1=0,y1=0,x2=0,y2=0,p=0,dx=0,dy=0,i=0;
int gd,gm;
gd=DETECT,gm;
initgraph(&gd,&gm,"C://TURBOC3//BGI");
printf("Enter X1 and Y1 : ");
scanf("%f %f",&x1,&y1);
printf("Enter X2 and Y2 : ");
scanf("%f %f",&x2,&y2);
dx=x2-x1;
dy=y2-y1;
p=(2*dy)-dx;
x=x1;
y=y1;
putpixel(x,y,4);
for(i=0;i<=dy;i++){
if(p<0){
p=p+2*dy;
y++;
}
else{
p=p+(2*dx)-dy;
x++;
y++;
}
putpixel(x,y,4);
}
getch();
}