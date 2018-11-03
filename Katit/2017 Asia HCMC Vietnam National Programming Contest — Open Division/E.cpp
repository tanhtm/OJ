#include <bits/stdc++.h>
using namespace std;
const double Max = 1e3;
double x[4],y[4];
double F(double X, double Y){
	double a = sqrt((X-x[1])*(X-x[1]) + (Y-y[1])*(Y-y[1]));
	double b = sqrt((X-x[2])*(X-x[2]) + (Y-y[2])*(Y-y[2]));
	double c = sqrt((X-x[3])*(X-x[3]) + (Y-y[3])*(Y-y[3]));
	return a+b+c;
}
double TernarySearch_Y(double x,double &y){ // tim Y khi co X
	double m1,m2;
	double l = -Max,r= Max;
	for(int i=0;i<100;i++){
		m1 = l + (r - l)/3.0;
		m2 = r - (r - l)/3.0;
		if(F(x,m1) < F(x,m2)) r = m2;
		else l = m1;
	}
	y = l;
	return F(x,l);
}
double X,Y;
void TernarySearch_X(){
	double x1,x2,f1,f2,y1,y2;
	double l = -Max,r= Max;
	for(int i=0;i<100;i++){
		x1 = l + (r - l)/3.0;
		x2 = r - (r - l)/3.0;
		f1 = TernarySearch_Y(x1,y1);
		f2 = TernarySearch_Y(x2,y2);
		if(f1 < f2) r = x2;
		else l = x1;
		if(f1 > f2){
			X = x2;
			Y = y2;
		}else{
			X = x1;
			Y = y1;
		}
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	for(int i=1;i<=3;i++) cin>>x[i]>>y[i];
	TernarySearch_X();
	printf("%.9lf %.9lf\n",X,Y);
	return 0;
}