#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k;
vector< ll > a;
map < ll , ll > M;
ll memo[1001][1001];
const ll MOD = 998244353;
ll dp(ll x, ll y){
	if(x == n && y == 0) return 1;
	if(x == n) return 0;
	if(y == 0) return 1;
	if(memo[x][y] != -1) return memo[x][y];
	ll r = ((M[a[x]]%MOD)*dp(x+1,y-1))%MOD;
	ll rr = dp(x+1,y);
	r = (r+rr)%MOD;
	return memo[x][y] = r;
}	
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>k;
	for(ll i=0;i< n;i++){
		ll x;
		cin>>x;
		if(M[x] == 0)
			a.push_back(x);
		M[x]++;
	}
	n = a.size();
	memset(memo, -1, sizeof memo);
	cout<<dp(0,k)<<endl;
	return 0;
}