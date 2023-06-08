#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void flood(int x, int y, int n, int old) {
  getpixel(x, y);
  if (getpixel(x, y) == old) {
    putpixel(x, y, n);
    flood(x, y, n, old);
    flood(x + 1, y, n, old);
    flood(x, y + 1, n, old);
    flood(x + 1, y + 1, n, old);
    flood(x - 1, y, n, old);
    flood(x, y - 1, n, old);
    flood(x - 1, y - 1, n, old);
    flood(x, y - 1, n, old);

  }
}

void bfill(int x, int y, int fill, int boundary) {
  int current = getpixel(x, y);
  if (current != boundary && current != fill) {
    putpixel(x, y, fill);

    bfill(x, y, fill, boundary);
    bfill(x + 1, y, fill, boundary);
    bfill(x, y + 1, fill, boundary);
    bfill(x + 1, y + 1, fill, boundary);
    bfill(x - 1, y, fill, boundary);
    bfill(x, y - 1, fill, boundary);
    bfill(x - 1, y - 1, fill, boundary);
    bfill(x, y - 1, fill, boundary);

  }
}
void main() {
    int gm, gd = DETECT;
    initgraph( & gd, & gd, "C:\\turboc3\\bgi");
    int choice=-1;

    printf("Enter Your choice: \n");
    printf("1. Flood Fill \n");
    printf("2. Boundary Fill \n");
    scanf("%d", &choice);

    switch(choice){
        case 1:{
            int newCol = 10;
            int oldCol = 0;
            rectangle(100, 100, 200, 200);
            flood(101, 101, newCol, oldCol);
            break;
        }
        case 2:{
            rectangle(50, 50, 100, 100);
            int boundary = 15;
            int fill = 3;
            bfill(55, 55, fill, boundary);
            break;
        }
        default:{
            break;
        }
    }
    getch();
}
