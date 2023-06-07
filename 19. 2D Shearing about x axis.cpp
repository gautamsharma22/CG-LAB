/*
    19. Write a program to implement 2-D shearing about x-axis on a square object.
*/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main() {
  int gd = DETECT, gm;
  double op[3][3], ob[3][4], ob2[3][4];
  int x1, y1, x2, y2, x3, y3, x4, y4, sf, i, j, k, xc, yc;
  initgraph( & gd, & gm, "c://turboc3//bgi");
  printf(" enter x,y,x1,y1,x2,y2,x3,y3,xc,yc and shearing factor:");
  scanf("%d%d%d%d%d%d%d%d%d%d%d", & x1, & y1, & x2, & y2, & x3, & y3, & x4, & y4, & xc, & yc, & sf);

  op[0][0] = op[2][2] = op[1][1] = 1;
  op[0][1] = sf;
  op[1][0] = op[2][0] = op[2][1] = op[0][2] = op[1][2] = 0;

  ob[0][0] = x1;
  ob[1][0] = y1;
  ob[0][1] = x2;
  ob[1][1] = y2;
  ob[0][2] = x3;
  ob[1][2] = y3;
  ob[0][3] = x4;
  ob[1][3] = y4;
  ob[2][0] = ob[2][1] = ob[2][2] = ob[2][3] = 1;
  line(xc, 0, xc, 2 * yc);
  line(0, yc, 2 * xc, yc);
  line(x1 + xc, y1 + yc, x2 + xc, y2 + yc);
  line(x2 + xc, y2 + yc, x3 + xc, y3 + yc);
  line(x3 + xc, y3 + yc, x4 + xc, y4 + yc);
  line(x4 + xc, y4 + yc, x1 + xc, y1 + yc);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      ob2[i][j] = 0;
      for (k = 0; k < 4; k++) {
        ob2[i][j] = ob2[i][j] + op[i][k] * ob[k][j];
      }
    }
  }

  line(ob2[0][0] + xc, ob2[1][0] + yc, ob2[0][1] + xc, ob2[1][1] + yc);
  line(ob2[0][1] + xc, ob2[1][1] + yc, ob2[0][2] + xc, ob2[1][2] + yc);
  line(ob2[0][2] + xc, ob2[1][2] + yc, ob2[0][3] + xc, ob2[1][3] + yc);
  line(ob[0][3] + xc, ob2[1][3] + yc, ob2[0][0] + xc, ob[1][0] + yc);
  getch();
}
