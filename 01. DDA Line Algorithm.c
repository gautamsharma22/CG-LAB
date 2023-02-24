#include<graphics.h>  
#include<conio.h>  
#include<stdio.h>  
int main()  
{  
    float x, y,x1,y1,x2,y2,dx,dy,x_inc,y_inc;  
    int gd,i,steps;
    gd = DETECT ,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    printf("Enter the values of X1 and Y1 : ");
    scanf("%f %f",&x1,&y1);
    printf("Enter the values of X2 and Y2 : ");
    scanf("%f %f",&x2,&y2);
    dx=x2-x1;
    dy=y2-y1;
    x=x1;
    y=y1;
    putpixel(x, y,4); 
    if(dx>=dy){  
        steps = dx;  
    }  
    else{  
        steps = dy;  
    }  
    x_inc = dx/steps;  
    y_inc = dy/steps;
    for(i=1;i<=steps;i++){  
        putpixel(x, y, RED);  
        x += x_inc;  
        y += y_inc;  
    }  
    getch();
    return 0;
}
