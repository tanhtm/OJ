#include <bits/stdc++.h>
using namespace std;
int memo[500][500];
int C(int n,int k){
	if(k == n || k == 0) return 1;
	if(memo[n][k] != -1) return memo[n][k];
	return memo[n][k] = C(n-1,k-1) + C(n-1,k);
}
int main(){
	memset(memo, -1, sizeof memo);
	cout<<C(6,2)<<endl;
	return 0;
}