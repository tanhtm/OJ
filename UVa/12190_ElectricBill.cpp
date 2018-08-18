#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int A,B;
int sumCWh;
int getCWh(int x){
	int r= 0;
	if(x >= 4979900){
		r = 100 + 9900 + 990000 + (x-4979900)/7;
		return r;
	}
	if(x >= 29900){
		r = 100 + 9900 + (x - 29900)/5;
		return r; 
	}
	if(x >= 200){
		r = 100 + (x - 200)/3;
		return r; 
	}
	return x/2;

}
int getBill( int cwh){
	int r = 0;
	if(cwh > 100) r+= 2*100;
	else{r+= cwh*2; return r;};
	if(cwh > 10000) r+= 3*9900;
	else {r+= 3*(cwh - 100);return r;};
	if(cwh > 1000000) r+= 5*990000 + 7*(cwh - 1000000);
	else {r+= 5*(cwh - 10000); return r;};
	return r;
}
int check(int x){
	int cwhX = getCWh(x);
	int cwhY = sumCWh - cwhX;
	int y = getBill(cwhY);
	if(y-x == B) return 0;
	if(y - x > B) return 1;
	return -1;
}
int findResult(int Min, int Max){
	if(Min == Max ) return Min;
	int mid = (Min + Max) /2;
	int b = check(mid);
	if(b == 0) return mid;
	if(b == -1) return findResult(Min, mid);
	return findResult(mid+1,Max);
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>A>>B && A!= 0){
		sumCWh = getCWh(A);
		cout<<findResult(0,A)<<endl;
	}
	return 0;
}