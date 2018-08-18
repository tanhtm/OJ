#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int vessels[1001]; 
int n, m, Max;
int s[1001]; // s[i] la tong tu vi tri 0 den vi tri i cua vessels
bool check(int x){
	int sum = 0;
	int d = 0;
	for(int i = 0 ;i < n; i++){
		if(sum + vessels[i] > x){
			d++;
			sum = 0;
		} 
		sum += vessels[i];
	}
	if(sum != 0) d++;
	if(d > m) return false;
	return true;
}
int findResult(int Min, int Max){
	if( Min == Max) return Min;
	int mid = (Min+Max)/2;
	bool c = check(mid);
	if(c) return findResult(Min,mid);
	return findResult(mid+1, Max);
}
void solve(){
	s[0]= vessels[0];
	for(int i = 1; i< n; i++) s[i] = s[i-1] + vessels[i];
	cout<<findResult(Max, s[n-1])<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(cin>>n>>m){
		Max = 0;
		for(int i=0;i<n;i++){cin>>vessels[i];Max = max(Max,vessels[i]);}
		if(m >= n) cout<<Max<<endl;
		else solve();
	}
	return 0;
}