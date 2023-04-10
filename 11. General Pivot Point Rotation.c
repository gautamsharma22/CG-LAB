#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    double op1[3][3],op2[3][3],op3[3][3],op4[3][3],op5[3][3],ob[3][3],ob2[3][3];
    int x1,x2,x3,y1,y2,y3,tx,ty,i,j,k;
    double th;
    printf("Enter x1,y1  x2,y2  x3,y3  ->  ");
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("Enter tx ty and theta ->  ");
    scanf("%d %d %lf",&tx,&ty,&th);
    double t;
    t=th*0.01725;
    ob[0][0]=x1;
    ob[0][1]=x2;
    ob[0][2]=x3;
    ob[1][0]=y1;
    ob[1][1]=y2;
    ob[1][2]=y3;
    ob[2][0]=ob[2][1]=ob[2][2]=1;

    op1[0][2]=tx;
    op1[1][2]=ty;
    op1[0][0]=op1[1][1]=op1[2][2]=1;
    op1[0][1]=op1[1][0]=op1[2][0]=op1[2][1]=1;

    op2[0][0]=op2[1][1]=cos(t);
    op2[0][1]=-sin(t); op2[1][0]=sin(t);
    op2[2][2]=1;
    op2[0][2]=op2[1][2]=op2[2][0]=op2[2][1]=0;


    op3[0][2]=-tx;
    op3[1][2]=-ty;
    op3[0][0]=op3[1][1]=op3[2][2]=1;
    op3[0][1]=op3[1][0]=op3[2][0]=op3[2][1]=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            op4[i][j]=0;
            for(k=0;k<3;k++){
                op4[i][j]=op4[i][j]+op2[i][k]*op3[k][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            op5[i][j]=0;
            for(k=0;k<3;k++){
                op5[i][j]=op5[i][j]+op1[i][k]*op4[k][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            op2[i][j]=0;
            for(k=0;k<3;k++){
                ob2[i][j]=ob2[i][j]+op5[i][k]*ob[k][j];
            }
        }
    }
    line(ob2[0][0],ob2[1][0],ob2[0][1],ob2[1][1]);
    line(ob2[0][1],ob2[1][1],ob2[0][2],ob2[1][2]);
    line(ob2[0][0],ob2[1][0],ob2[0][2],ob2[1][2]);

    getch();

}
