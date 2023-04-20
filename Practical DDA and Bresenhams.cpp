#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	float x, y, x1, y1, x2, y2, dx, dy, xi, yi, p;
	int i, steps;

	printf("Enter coordinates (x1,y1) and (x2,y2)\n");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

	clrscr();
	x=x1;
	y=y1;

	dx=x2-x1;
	dy=y2-y1;

	steps=(abs(dx)>abs(dy))?abs(dx):abs(dy);

	xi=dx/steps;
	yi=dy/steps;

	for(i=0; i<steps/2; i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel(x,y,4);
	}

	p=(2*dy)-dx;

	for(i; i<dx; i++)
	{
		if(p<0)
		{
			p=p+(2*dy);
			x++;
		}
		else
		{
			p=p+(2*dy)-(2*dx);
			x++;
			y++;
		}
		putpixel(x,y,4);
	}
	getch();
}
