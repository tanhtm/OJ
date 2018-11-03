#include <bits/stdc++.h>
using namespace std;
double X,Y,a,b,h;
double getA(double H){
	return X - 2*H;
}
double getB(double H){
	return Y - 2*H;
}
int getDelta(){
	return 4*(X*X + Y*Y - X*Y);
}
double getX1(){
	double r = sqrt(getDelta());
	return (double(2*(X+Y)) - r) / 12;
}
double getX2(){
	double r = sqrt(getDelta());
	return (double(2*(X+Y)) + r) / 12;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>X>>Y;
		double h;
		double Max = 0;
		h = getX1();
		a = getA(h);
		b = getB(h);
		Max = max(h*a*b,Max);
		h = getX2();
		a = getA(h);
		b = getB(h);
		Max = max(h*a*b,Max);
		printf("%.11lf\n",Max);
	}
	return 0;
}