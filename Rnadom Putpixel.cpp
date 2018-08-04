#include <iostream>
#include <conio.h>
#include<graphics.h>

using namespace std;
int main()
{


    initwindow(500,600,"Mashod");
    //putpixel(200,200,WHITE);
    while(!kbhit())
    {
        int x=rand()%500,y=rand()%600,z=rand()%8;
        //cout<<x<<" "<<y;
        putpixel(x,y,z);
    }

    return 0;
}
