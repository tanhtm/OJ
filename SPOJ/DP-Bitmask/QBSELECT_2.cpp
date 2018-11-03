#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
static ll a[4][10004];
const ll bit[]={0,1,2,4,5,8,9,10};
ll memo[10004][11];
ll dp(ll j, ll mask){

	if(j > n) return 0;
	if(memo[j][mask] != -1) return memo[j][mask];
	ll r = 0;
	for(ll i= 0;i<4;i++){
		if((mask & (1<<i)) == 0) continue;
		r+= a[i][j];
	}
	ll x = 0;
	for(ll i= 0;i< 8;i++){
		if((mask & bit[i]) != 0) continue;
		x= max(x, dp(j+1,bit[i]));
	}
	return memo[j][mask] = r + x;
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n;
	for(ll i=0;i < 4;i++){
		for(ll j = 1; j<= n;j++)
			cin>>a[i][j];
	}
	memset(memo, -1, sizeof memo);
	cout<<dp(0,0)<<endl;
	return 0;
}