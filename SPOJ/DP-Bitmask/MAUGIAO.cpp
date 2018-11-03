#include <bits/stdc++.h>
using namespace std;
int n;
int c[22][22];
int memo[1<<20];
/*
dp(i): la dap so 
voi i co k bit 1 tai vi tri x0, x1, x2, x3.. xk
dp(i) la cach ghep tot nhat co gai x0, x1, x2, x3 .. xk voi cac chang trai tu 0 -> k
*/
int dp(int i, int k){ 
	if(i == 0) return 0;
	if(memo[i] != -1) return memo[i];
	int res = 0;
	for(int j = 0;j < n; j++){
		if((i & (1<<j)) == 0) continue;
		res = max(res, dp(i - (1<<j), k-1) + c[j][k]);
	}
	int d = 0;
	for(int j = 0;j < n; j++){
		if((i & (1<<j)) == 0) continue;
		if(dp(i - (1<<j), k-1) + c[j][k] == res) d++;
	}

	return memo[i] = res;
}
int main(){
	cin>>n;
	for(int i= 0;i< n;i++){
		for(int j= 0;j< n;j++){
			cin>>c[i][j];
		}
	}
	memset(memo,-1,sizeof memo);
	cout<<dp((1<<n)-1,n-1)<<" "<<1<<endl;
	return 0;
}