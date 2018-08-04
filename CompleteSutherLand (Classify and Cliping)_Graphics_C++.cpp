#include<bits/stdc++.h>
#include<graphics.h>


using namespace std;

#define pf printf
#define sf scanf


double cx=500,cy=350;
static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
static double Xmx,Xmn,Ymx,Ymn;
double lin[20][4];
bool bit[20];

double cox(double);
double coy(double);
void draw_window();
void draw_line(double);

double coy(double n){
    return (n*30.0*(-1)+cy);

}

double cox(double n){
    return (n*40.0+cx);
}


void draw_window(){
    //draw axis
    line(0,cy,1000,cy);
    line(cx,0,cx,700);
     outtextxy(5,300, "-X");
    outtextxy(950,300, "X");
    outtextxy(450,5, "Y");
    outtextxy(450,650, "-Y");

    //=======draw window=========
    line(Xmn,Ymn,Xmx,Ymn);
    line(Xmn,Ymn,Xmn,Ymx);
    line(Xmx,Ymn,Xmx,Ymx);
    line(Xmn,Ymx,Xmx,Ymx);
}

void draw_line(int n){
    for(int i=0;i<n;i++){
        if(bit[i]){
            line(lin[i][0],lin[i][1],lin[i][2],lin[i][3]);

        }

    }
}

int regionCode(double x,double y){
	int code = 0;
	//Perform Bitwise OR to get outcode
	if(y < Ymx) code |=TOP;
	if(y > Ymn) code |=BOTTOM;
	if(x < Xmn) code |=LEFT;
	if(x > Xmx) code |=RIGHT;
	return code;
}


void classification(double x1,double y1,double x2,double y2, int po)
{


	int Epoint1=regionCode(x1,y1), Epoint2=regionCode(x2,y2);
	int accept = 0; 	//decides if line is to be drawn

    if(Epoint1==0 && Epoint2==0){
        pf("Visible\n");
        bit[po]=1;
        return;
    }
    else if((Epoint1 & Epoint2)!=0){
        pf("Not Visible\n");
        bit[po]=0;
        return;
    }
    else{
        pf("Clipping Candidate\n");
    }

	while(1){
		double m =(double)(y2-y1)/(x2-x1);
		//Both points inside. Accept line
		if(Epoint1==0 && Epoint2==0){
			accept = 1;
			break;
		}
		//AND of both codes != 0.Line is outside. Reject line
		else if((Epoint1 & Epoint2)!=0){
			break;
		}else{
			int x,y;
			int temp;
			//Decide if point1 is inside, if not, calculate intersection
			if(Epoint1==0)
				temp = Epoint2;
			else
				temp = Epoint1;
			//Line clips TOP edge
			if(temp & TOP){
				x = x1+ (Ymx-y1)/m;
				y = Ymx;
			}
			else if(temp & BOTTOM){ 	//Line clips BOTTOM edge
				x = x1+ (Ymn-y1)/m;
				y = Ymn;
			}else if(temp & LEFT){ 	//Line clips LEFT edge
				x = Xmn;
				y = y1+ m*(Xmn-x1);
			}else if(temp & RIGHT){ 	//Line clips RIGHT edge
				x = Xmx;
				y = y1+ m*(Xmx-x1);
			}
			//Check which point we had selected earlier as temp, and replace its co-ordinates
			if(temp == Epoint1){
				x1 = x;
				y1 = y;
				Epoint1 = regionCode(x1,y1);
			}else{
				x2 = x;
				y2 = y;
				Epoint2 = regionCode(x2,y2);
			}
		}
	}

	pf("After Line Clipping: ");
	if(accept){

        pf("Visible\n");
        lin[po][0]=x1;
        lin[po][1]=y1;
        lin[po][2]=x2;
        lin[po][3]=y2;
        bit[po]=1;
	}
	else{
        pf("Not Visible\n");
        bit[po]=0;
	}
}

int main(){


    initwindow(1000,700,"Mashod");


    //line(0,50,100,50);
    pf("Enter Window LEFT BOTTOM corner point(X1,Y1): ");
    sf("%lf%lf",&Xmn,&Ymn);
    pf("Enter Window RIGHT TOP corner point (X2,Y2): ");
    sf("%lf%lf",&Xmx,&Ymx);

    Xmn=cox(Xmn);   Xmx=cox(Xmx);
    Ymn=coy(Ymn);   Ymx=coy(Ymx);
    cout<<Xmn<<" "<<Ymn<<" "<<Xmx<<" "<<Ymx<<endl;
    draw_window();

    int n;
    pf("Enter line number: ");
    sf("%d",&n);
    pf("Enter line end points (X1,Y1) & (X2,Y2): ");
    double a;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            sf("%lf",&a);
            if(j&1)
                lin[i][j]=coy(a);
            else
                lin[i][j]=cox(a);

        }
    }

    memset(bit,1,sizeof(bit));//set region code to all one

    draw_line(n);


    cin.ignore();
    pf("Enter to start line classification:");
    getchar();

    for(int i=0;i<n;i++){
        classification(lin[i][0], lin[i][1], lin[i][2], lin[i][3],i);
        cleardevice();
        draw_window();
        draw_line(n);
        pf("Press enter to classify Line %d.",i+2);
        getchar();
    }
    getchar();
    return 0;
}
