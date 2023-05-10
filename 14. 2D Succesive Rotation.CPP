#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main()
{
 int gd=DETECT,gm;
        initgraph(&gd,&gm,"c:\\turboc3\\BGI");
 double op[3][3],ob[3][3],ob2[3][3],ob3[3][3];
 int x1,y1,x2,y2,x3,y3,i,j,k;
 double t1,t2,t3,th1,th2;
 
 printf("Enter x1,y1,x2,y2,x3,y3 :- \n");
 scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
 printf("Enter values for Theta-1 and Theta-2 :- \n");
 scanf("%lf%lf",&th1,&th2);
 t1=th1*0.01725;
              t2=th2*0.01725;
 op[0][0]=cos(t1);
 op[1][1]=cos(t1);
 op[2][2]=1;
 op[0][1]=-sin(t1);
 op[1][0]= sin(t1);
 op[2][0]=op[2][1]=0;
 op[0][2]=op[1][2]=0;

 ob[0][0]=x1; ob[1][0]=y1;
 ob[0][1]=x2; ob[1][1]=y2;
 ob[0][2]=x3; ob[1][2]=y3;
 ob[2][0]=ob[2][1]=ob[2][2]=1;
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x1,y1,x3,y3);
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   ob2[i][j]=0;
   for(k=0;k<3;k++)
   {
    ob2[i][j]=ob2[i][j]+op[i][k]*ob[k][j];
   }
  }
 }
 line(ob2[0][0],ob2[1][0],ob2[0][1],ob2[1][1]);
 line(ob2[0][1],ob2[1][1],ob2[0][2],ob2[1][2]);
 line(ob2[0][0],ob2[1][0],ob2[0][2],ob2[1][2]);

              op[0][0]=cos(t2);
  op[1][1]=cos(t2);
  op[0][1]=-sin(t2);
  op[1][0]= sin(t2);

        for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   ob3[i][j]=0;
   for(k=0;k<3;k++)
   {
    ob3[i][j]=ob3[i][j]+op[i][k]*ob2[k][j];
   }
  }
 }
      line(ob3[0][0],ob3[1][0],ob3[0][1],ob3[1][1]);
      line(ob3[0][1],ob3[1][1],ob3[0][2],ob3[1][2]);
      line(ob3[0][0],ob3[1][0],ob3[0][2],ob3[1][2]);

 getch();
}