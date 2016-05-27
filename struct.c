#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct robo {
	double x;
	double y;
	double dvx;
	double dv;
	double dvy;
	double vx;
	double vy;
	double v;
	double th;
	double omg;
	double domg;
	double ramuda;
	double ramuda0;
	double dramuda;
	double zx;
	double zy;
	double z;
};

double integ(double v,double dv,double h,double sum){
        return sum+(v+dv)*h*0.5;
}

main(){
	short i,j,n;
	double h;
	n=8.5;
	h=0.01;
	struct robo drone1[2];

	drone1[0].x=1000.0;
	drone1[1].x=0.0;		
	drone1[0].y=1000.0;
	drone1[1].y=0.0;

	drone1[1].ramuda=0;
	drone1[1].ramuda0=0;

	drone1[0].omg=3.1415926535/2.0;
	drone1[1].omg=3.1415926535/2.0;
	drone1[1].th=0.0;

	drone1[0].dv=drone1[0].v;
	drone1[0].dvx=drone1[0].vx;
	drone1[0].dvy=drone1[0].vy;
	drone1[0].domg=drone1[0].omg;

	for(i=0; i<500; i++){
		
		printf("%f %f %f %f\n", drone1[0].x,drone1[0].y,drone1[1].x,drone1[1].y);
		drone1[0].v=200.0;
		drone1[1].v=600.0;

		drone1[0].omg=3.1415926535/2.0;
		drone1[0].th=drone1[0].th+(drone1[0].omg+drone1[0].domg)*h/2.0;
		drone1[0].vx=drone1[0].v*cos(drone1[0].th);
		drone1[0].vy=drone1[0].v*sin(drone1[0].th);
		drone1[0].x=drone1[0].x+(drone1[0].vx+drone1[0].dvx)*h/2.0;
		drone1[0].y=drone1[0].y+(drone1[0].vy+drone1[0].dvy)*h/2.0;
	

		drone1[1].ramuda=atan((drone1[0].y-drone1[1].y)/(drone1[0].x-drone1[1].x));
		drone1[1].omg=n*(drone1[1].ramuda-drone1[1].ramuda0)/h;
		drone1[1].th=drone1[1].th+(drone1[1].omg+drone1[1].domg)*h/2.0;
		drone1[1].vx=drone1[1].v*cos(drone1[1].th);
		drone1[1].vy=drone1[1].v*sin(drone1[1].th);

		drone1[1].zx=(drone1[0].x-drone1[1].x)*(drone1[0].x-drone1[1].x);
		drone1[1].zy=((drone1[0].y-drone1[1].y)*(drone1[0].y-drone1[1].y));
		drone1[1].z=sqrt(drone1[1].zx+drone1[1].zy);

		drone1[1].x=drone1[1].x+(drone1[1].vx+drone1[1].dvx)*h/2.0;
		drone1[1].y=drone1[1].y+(drone1[1].vy+drone1[1].dvy)*h/2.0;
		
			if(drone1[1].z <= 10) break;
				

		drone1[0].dv=drone1[0].v;
		drone1[1].dv=drone1[1].v;
		drone1[0].dvx=drone1[0].vx;
		drone1[1].dvx=drone1[1].vx;
		drone1[0].dvy=drone1[0].vy;
		drone1[1].dvy=drone1[1].vy;
		drone1[0].domg=drone1[0].omg;
		drone1[1].domg=drone1[1].omg;
		drone1[1].ramuda0=drone1[1].ramuda;

	}
}
		
	
	


