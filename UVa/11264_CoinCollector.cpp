#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int t,n;
int coins[1000];
long long int sum;
void solve(){
	int d= 0;
	sum = 0;
	for(int i = 0;i < n -1;i++){
		if(coins[i+1] > sum+coins[i]) {
			sum+= coins[i];
			d++;
		}
	}
	d++; // luon lay cai cuoi cung
	cout<<d<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>n;
		sum = 0;
		for(int i=0; i<n;i++)cin>>coins[i];
		solve();
	}
	return 0;
}