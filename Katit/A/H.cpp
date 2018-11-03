#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double b,p;
	cin>>n;
	while(n--){
		cin>>b>>p;
		double bpm, x;
		bpm = b*60/p;
		x = 60/p;
		printf("%.4lf %.4lf %.4lf\n",bpm-x, bpm, bpm + x);
	}
	return 0;
}