#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main() {
    int gd = DETECT, gm;
    initgraph( & gd, & gm, "C:\\turboc3\\BGI");
    int op[3][3], ob[3][3], ob2[3][3], ob3[3][3];
    int x1, x2, x3, y1, y2, y3, i, j, k;
    printf("Enter values of x1,y1,x2,y2,x3,y3 : ");
    scanf("%d%d%d%d%d%d", & x1, & y1, & x2, & y2, & x3, & y3);

    int tx1,ty1,tx2,ty2;
    int sx1,sy1,sx2,sy2;
    double t1,t2;

    ob[0][0] = x1;
    ob[1][0] = y1;
    ob[0][1] = x2;
    ob[1][1] = y2;
    ob[0][2] = x3;
    ob[1][2] = y3;
    ob[2][0] = ob[2][1] = ob[2][2] = 1;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);


    int choice=-1;

    printf("Enter Your choice: \n");
    printf("1. 2D Succesive Translation \n");
    printf("2. 2D Succesive Scaling \n");
    printf("3. 2D Succesive Roation \n");
    scanf("%d", &choice);

    switch(choice){
        case 1:{
            printf("Enter TX1 and TY1 : ");
            scanf("%d%d",&tx1,&ty1);
            printf("Enter TX2 and TY2 : ");
            scanf("%d%d",&tx2,&ty2);
            op[0][0]= op[1][1]= op[2][2]=1;
            op[0][1]=op[1][0]=op[2][0]=op[2][1]=0;
            op[0][2]=tx1;
            op[1][2]=ty1;
            break;
        }
        case 2:{
            printf("Enter SX1 and SY1 : ");
            scanf("%d%d",&sx1,&sy1);
            printf("Enter SX2 and SY2 : ");
            scanf("%d%d",&sx2,&sy2);
            op[0][0]=sx1;
            op[1][1]=sy1;
            op[2][2]=1;
            op[0][1]=op[1][0]=op[2][0]=op[2][1]=0;
            op[0][2]=op[1][2]=0;
            break;
        }
        case 3:{
              printf("Enter Theta-1 : \n");
              scanf("%lf",&t1);
              printf("Enter Theta-2 : \n");
              scanf("%lf",&t2);
              t1=t1*0.01725;
              t2=t2*0.01725;
              op[0][0]=cos(t1);
              op[1][1]=cos(t1);
              op[2][2]=1;
              op[0][1]=-sin(t1);
              op[1][0]= sin(t1);
              op[2][0]=op[2][1]=0;
              op[0][2]=op[1][2]=0;
            break;
        }
        default:{
            break;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            ob2[i][j] = 0;
            for (k = 0; k < 3; k++) {
                ob2[i][j] = ob2[i][j] + op[i][k] * ob[k][j];
            }
        }
    }

    line(ob2[0][0], ob2[1][0], ob2[0][1], ob2[1][1]);
    line(ob2[0][1], ob2[1][1], ob2[0][2], ob2[1][2]);
    line(ob2[0][0], ob2[1][0], ob2[0][2], ob2[1][2]);

    switch(choice){
        case 1:{
            op[0][2]=tx2;
            op[1][2]=ty2;
            break;
        }
        case 2:{
            op[0][0]=sx2;
            op[1][1]=sy2;
            break;
        }
        case 3:{
            op[0][0]=cos(t2);
            op[1][1]=cos(t2);
            op[0][1]=-sin(t2);
            op[1][0]= sin(t2);
            break;
        }
        default:{
            break;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            ob3[i][j] = 0;
            for (k = 0; k < 3; k++) {
                ob3[i][j] = ob3[i][j] + op[i][k] * ob2[k][j];
            }
        }
    }
    line(ob3[0][0], ob3[1][0], ob3[0][1], ob3[1][1]);
    line(ob3[0][1], ob3[1][1], ob3[0][2], ob3[1][2]);
    line(ob3[0][0], ob3[1][0], ob3[0][2], ob3[1][2]);
    getch();
}
