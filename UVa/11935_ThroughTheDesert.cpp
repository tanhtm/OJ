#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
int disFirst = 0, disSecond;
int fuel = 0, leak= 0;
char event[20];
int n;
double lit = 0;
double res = 0;
void reset(){
	fuel = leak= 0;
	disFirst = 0;
	lit = 0;
	res = 0;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	string s;
	while(true){
		getline(cin,s);
		if(s == string("0 Fuel consumption 0")) break;
		sscanf(s.c_str(),"%d %s",&disSecond,event);
		lit += (disSecond - disFirst)*fuel/100.0;
		lit += (disSecond - disFirst)*leak;
		disFirst = disSecond;
		if(event[0] == 'F'){
			sscanf(s.c_str(), "%d Fuel consumption %d", &disSecond, &n);
			fuel = n;
		}
		if(event[0] == 'G' && event[1] =='o'){
			res = max(lit,res);
			printf("%.3lf\n", res);
			reset();
			continue;
		}
		if(event[0] == 'L') leak++;
		if(event[0] == 'G' && event[1] =='a'){
			res = max(res,lit);
			lit = 0;
		}
		if(event[0] == 'M'){
			leak = 0;
		}
	}
	return 0;
}