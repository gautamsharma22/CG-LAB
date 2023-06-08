#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main() {
    float x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, p = 0, dx = 0, dy = 0, i = 0;
    int gd, gm;
    gd = DETECT, gm;
    initgraph( & gd, & gm, "C://TURBOC3//BGI");
    printf("Enter X1 and Y1 : ");
    scanf("%f %f", & x1, & y1);
    printf("Enter X2 and Y2 : ");
    scanf("%f %f", & x2, & y2);
    
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;

    int choice=-1;

    printf("Enter Your choice: \n");
    printf("1. DDA \n");
    printf("2. Breshenham's m<1 \n");
    printf("3. Breshenham's m>1 \n");
    scanf("%d", &choice);

    switch(choice){
        case 1:{
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
            break;
        }
        case 2:{
            p = (2 * dy) - dx;
            putpixel(x, y, 4);
            for (i = 0; i <= dx; i++) {
                if (p < 0) {
                    p = p + 2 * dy;
                    x++;
                } else {
                    p = p + (2 * dy) - (2 * dx);
                    x++;
                    y++;
                }
                putpixel(x, y, 4);
            }
            break;
        }
        case 3:{
            p=(2*dx)-dy;
            putpixel(x,y,4);
            for(i=0;i<=dy;i++){
                if(p<0){
                    p=p+2*dy;
                    y++;
                }
                else{
                    p=p+2(dx-dy);
                    x++;
                    y++;
                }
                putpixel(x,y,4);
            }
            break;
        }
        default:{
            break;
        }
    }
    closegraph();
    getch();
}
