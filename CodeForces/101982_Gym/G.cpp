#include <bits/stdc++.h>
using namespace std;
double X,Y,X1,Y1,X2,Y2;
double getDis(double a, double b, double a1, double b1){
	return sqrt(pow((a-a1),2)+pow((b-b1),2));
}
int main(){
	//freopen("data.tXt","r",stdin);
	//freopen("dataOut.tXt","w",stdout);
	cin>>X>>Y>>X1>>Y1>>X2>>Y2;
	double r = 0;
	X+= 1000;
	Y+= 1000;
	X1+= 1000;
	Y1+= 1000;
	X2+= 1000;
	Y2+= 1000;
	if(X >= X1 && X <= X2){
		r = max(Y1- Y, Y - Y2);
	}else if(Y >= Y1 && Y <= Y2){
		r = max(X1 - X, X - X2);
	}else{
		r = min(getDis(X,Y,X1,Y1), getDis(X,Y,X2,Y2));
		r = min(r, min(getDis(X,Y,X1,Y2), getDis(X,Y,X2,Y1)));
	}
	printf("%.3lf\n",r);
	return 0;
}