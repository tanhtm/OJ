#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
ll memo[2][55][55]; // memo[1/0][i][j] luu so luong so so bat dau 1/0 co i thanh co j vach
ll bc(bool b, int N, int K){
	if(N <= 0) return 0; 
	if(K == 1){
		if(N <= m) return 1;
		return 0;
	}
	if(memo[b][N][K]!= -1) return memo[b][N][K];
	//cout<<b<<" "<<N<<" "<<K<<endl;
	ll res = 0;
	for(int i=1;i<=m;i++){
		res+= bc(!b,N-i,K-1);
	}
	//cout<<res<<endl;
	return memo[b][N][K] = res;
}
void solve(){
	for(int i = 0;i<=n;i++){
		for(int j=0;j<=k;j++){
			memo[0][i][j] = -1;
			memo[1][i][j] = -1;
		}
	}
	cout<<bc(1,n,k)<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(cin>>n>>k>>m){
		solve();
	}
	return 0;
}