#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
void main()
{
    int gd = DETECT, gm;
    double op[3][3], ob[3][3], ob2[3][3];
    double x1, y1, x2, y2, x3, y3, i, j, k, sx, t;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    scanf("%lf", &t);
    op[2][0] = op[2][1] = op[0][2] = op[1][2] = 0;
    op[2][2] = 1;
    op[0][0] = cos(t * 0.01725);
    op[1][1] = cos(t * 0.01725);
    op[0][1] = -sin(t * 0.01725);
    op[1][0] = sin(t * 0.01725);

    ob[0][0] = x1;
    ob[1][0] = y1;
    ob[0][1] = x2;
    ob[0][2] = x3;
    ob[1][2] = y3;
    ob[2][0] = ob[2][1] = ob[2][2] = 1;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ob2[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                ob2[i][j] = ob2[i][j] + op[i][k] * ob[k][j];
            }
        }
    }
    line(ob2[0][0], ob2[1][0], ob2[0][1], ob2[1][1]);
    line(ob2[0][1], ob2[1][1], ob2[0][2], ob2[1][2]);
    line(ob2[0][0], ob2[1][0], ob2[0][2], ob2[1][2]);
    getch();
}
