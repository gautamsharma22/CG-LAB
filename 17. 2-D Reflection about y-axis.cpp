/*
    17. Write a program to implement 2-D reflection about y-axis when the center point of screen is work as origin.
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
  int x1, x2, x3, y1, y2, y3, i, j, k, xc, yc, op[3][3], ob[3][3], ob2[3][3];
  int gd = DETECT, gm;
  initgraph( & gd, & gm, "c://turboc3//bgi");
  printf("Enter x1,y1,x2,y2,x3,y3,xc,yc\n");
  scanf("%d%d%d%d%d%d%d%d", & x1, & y1, & x2, & y2, & x3, & y3, & xc, & yc);
  op[0][0] = op[2][2] = -1;
  op[1][1] = 1;
  op[0][1] = op[1][0] = op[2][0] = op[2][1] = op[0][2] = op[1][2] = 0;

  ob[0][0] = x1;
  ob[1][0] = y1;
  ob[0][1] = x2;
  ob[1][1] = y2;
  ob[0][2] = x3;
  ob[1][2] = y3;
  ob[2][0] = ob[2][1] = ob[2][2] = 1;
  line(xc, 0, xc, 2 * yc);
  line(0, yc, 2 * xc, yc);
  line(x1 + xc, y1 + yc, x2 + xc, y2 + yc);
  line(x2 + xc, y2 + yc, x3 + xc, y3 + yc);
  line(x1 + xc, y1 + yc, x3 + xc, y3 + yc);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ob2[i][j] = 0;
      for (k = 0; k < 3; k++) {
        ob2[i][j] = ob2[i][j] + op[i][k] * ob[k][j];
      }
    }
  }

  line(ob2[0][0] + xc, ob2[1][0] + yc, ob2[0][1] + xc, ob2[1][1] + yc);
  line(ob2[0][1] + xc, ob2[1][1] + yc, ob2[0][2] + xc, ob2[1][2] + yc);
  line(ob2[0][0] + xc, ob2[1][0] + yc, ob2[0][2] + xc, ob2[1][2] + yc);
  getch();

}
