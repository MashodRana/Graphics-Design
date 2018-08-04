#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
using namespace std;
#define pf printf
#define sf scanf
#define pi 3.14159265358979323846

int x[] = { 100, 200, 300 };
int y[] = { 200, 100, 200 };
int Sx,Sy;
int tx,ty;
double ang;

void draw(){
    line(x[0],y[0],x[1],y[1]);
    line(x[0],y[0],x[2],y[2]);
    line(x[1],y[1],x[2],y[2]);
}
void translation(){
    for(int i=0;i<3;i++){
        x[i]+=tx;
        y[i]+=ty;
    }
    draw();

}

void scaling(){
    for(int i=0;i<3;i++){
        x[i]*=Sx;
        y[i]*=Sy;
    }

    draw();
}


void rotation(){
    int xx,yy;
    for(int i=0;i<3;i++){
        xx=(int)(x[i]*cos(ang)-y[i]*sin(ang));
        yy=(int)(x[i]*sin(ang)+y[i]*cos(ang));
        x[i]=abs(xx+1);
        y[i]=abs(yy+1);
        //cout<<xx<<" "<<yy<<endl;
    }

    draw();
}
int main()
{
    int n;
    pf("1> Translation\n2> Scaling\n3> Rotation\nEnter options number: ");
    sf("%d",&n);

    if(n==1){
        pf("Enter the translation co-ordinate(Tx,Ty): ");
        sf("%d%d",&tx,&ty);
        initwindow(800,600,"2D");
        draw();
        translation();
    }
    else if(n==2){
        pf("Enter the factor (Sx,Sy): ");
        sf("%d%d",&Sx,&Sy);
        initwindow(800,600,"2D");
        draw();
        scaling();
    }
    else{
        int aa;
        pf("Enter angle to rotate in degree(int): ");
        sf("%d",&aa);
        ang = ( aa * pi ) / 180 ;
        //ang=aa;
        initwindow(800,600,"2D");
        draw();
        rotation();
    }




    //scaling();
    getch();
    return 0;
}
