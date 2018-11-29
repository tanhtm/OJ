#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll l, k;
ll memo[101][101];
ll dp(ll i, ll L){
	if(i == L) return 1;
	if(i - 2 == L) return 1;
	if(i > L) return 0;
	if(memo[i][L] != -1) return memo[i][L];
	ll r = 0;
	r+= dp(i+2,L);
	r+= dp(i+k+1,L);
	return memo[i][L]= r;
}
int main(){
	cin>>l>>k;
	//l = 100; k = 2;
	memset(memo, -1, sizeof memo);
	ll res = 0;
	for(ll i=1;i<=l;i++){
		res+= dp(1,i);
		//cout<<dp(1,i)<<endl;
	}
	cout<<res<<endl;
	return 0;
}