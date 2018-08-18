#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
double p,q,r,s,t,u;
double get(double x){
	return (p*exp(x*-1) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
bool check(double a, double b){
	int x = a*100000000, y = b*100000000;
	if(x == y) return true;
	return false;
}
double solve(double l, double r){
	if(check(l,r)) return l;
	double a = get(l), b = get(r),c;
	double mid = (l+r)/2;
	c = get(mid);
	if( c == 0) return mid;
	if( c * a > 0) return solve(mid,r);
	return solve(l,mid);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(cin>>p>>q>>r>>s>>t>>u){
		double r = solve(0.0,1.0);
		if(r == 1 && get(1) != 0.00 ) printf("No solution\n");
		else printf("%.4lf\n", r);
	}
	return 0;
}