#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < ll , ll > eCoin;
ll n,m,S;
eCoin eCoins[50];
ll dp[305][305]; // dp[i][x][y] la dap so voi x*x + y*y = S
ll toSquare(ll x){
	double xx = sqrt(x);
	if(xx == ll(xx)) return xx;
	return -1;
}
ll DP(ll x, ll y){
	if(x == 0 && y == 0) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	//cout<<x<<" "<<y<<endl;
	ll res = -2;
	for(ll i=1;i<=m;i++){
		ll a = eCoins[i].first;
		ll b = eCoins[i].second;
		if(a > x  || b > y) continue;
		ll r = DP(x - a, y - b);
		//cout<<r<<endl;
		if(r == -2) continue;
		r++;
		if(res == -2) res = r;
		else res = min(res,r);
	}
	//cout<<res<<endl;
	return dp[x][y] = res;
}
void solve(){	
	ll res = -2;
	for(ll x = 0;x<=S;x++){
		ll y = S*S - x*x;// tim x ,y
		y = toSquare(y);
		if(y != -1){
			ll r = DP(x,y);
			if(r == -2) continue;
			if(res == -2) res = r;
			else res = min(res,r);
		}
	}
	if(res == -2) cout<<"not possible\n";
	else cout<<res<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n;
	while(n--){
		cin>>m>>S;
		memset(dp,-1,sizeof dp);
		ll x,y;
		for(ll i=1;i<=m;i++){
			cin>>x>>y;
			eCoins[i] = eCoin
			(x,y);
			dp[x][y] = 1;
		}
		solve();
	}
	return 0;
}