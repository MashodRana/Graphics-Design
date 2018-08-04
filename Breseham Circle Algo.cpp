#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;

#define sf scanf
#define pf printf

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}

void circleBres(int x, int y, int r)
{
    int p = 0, q = r;
    int d = 3-2*r;
    while (p <= q)
    {

        drawCircle(x,y, p,q);
        p++;


        if(d<0)
            d+=4*p+6;
        else{
            q--;
            d=d+4*(p-q)+10;
        }
        drawCircle(x, y, p, q);
        delay(10);
    }
    getche();
}



int main()
{
    int x, y, r;
    pf("Enter the Center of the Circle X,Y: ");
    sf("%d%d",&x,&y);
    pf("Enter Radius of the Circle: ");
    sf("%d",&r);
    initwindow(500,600,"Circle");
    circleBres(x, y, r);

    return 0;
}
