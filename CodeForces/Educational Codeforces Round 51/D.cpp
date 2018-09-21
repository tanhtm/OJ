#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n,k;
int memo[4][1001][2002]; // 
int dp(int mask, int N, int K){ // dp(mask,n,k) : so cach lay (n , k) khi bat dau voi trang thai mask
	long long int r = 0;
	if(memo[mask][N][K] != -1) return memo[mask][N][K];
	if(N == 1){
		if(mask == 0 || mask == 3){
			if(K == 1) return 1;
			else return 0;
		}
		if(mask == 1 || mask == 2){
			if(K == 2) return 1;
			return 0;
		}
	}
	if (mask == 0){
		r+= dp(0,N-1,K);
		r+= dp(1,N-1,K);
		r+= dp(2,N-1,K);
		r+= dp(3,N-1,K-1);
	}
	if (mask == 1){
		r+= dp(0,N-1,K-1);
		r+= dp(1,N-1,K);
		r+= dp(2,N-1,K-2);
		r+= dp(3,N-1,K-1);
	}
	if (mask == 2){
		r+= dp(0,N-1,K-1);
		r+= dp(1,N-1,K-2);
		r+= dp(2,N-1,K);
		r+= dp(3,N-1,K-1);
	}
	if (mask == 3){
		r+= dp(0,N-1,K-1);
		r+= dp(1,N-1,K);
		r+= dp(2,N-1,K);
		r+= dp(3,N-1,K);
	}
	return memo[mask][N][K] = r % Mod;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n>>k;
	memset(memo,-1,sizeof memo);
	long long int r = 0;
	r += dp(0,n,k);
	r += dp(1,n,k);
	r += dp(2,n,k);
	r += dp(3,n,k);
	cout<<r<<endl;
	return 0;
}