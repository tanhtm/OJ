#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int t,n;
int ladder[100001];
// bat dau tu mat dat !!!!!!!!!!!!!

bool check(int x){
	int k = x;
	for(int i= 1;i<= n;i++){
		if(ladder[i] - ladder[i-1] > k) return false;
		if(ladder[i] - ladder[i-1] == k) k--;
	}
	return true;
}
int findResult(int Min, int Max){
	if(Min == Max) return Min;
	int mid = (Min + Max)/2;
	bool b = check(mid);
	if(b) return findResult(Min,mid);
	return findResult(mid+1,Max);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	int c = 0;
	while(c != t){
		c++;
		cin>>n;
		ladder[0] = 0; // mat dat
		for(int i = 1;i<=n;i++) cin>>ladder[i];
		cout<<"Case "<<c<<": "<<findResult(1,1e7)<<endl;
	}
	return 0;
}