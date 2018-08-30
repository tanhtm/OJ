#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N,K, S[20];
ll f[20][1<<17];// f[i][mask] la so cach xep con bo i vao trang thai mask ( trang thai chua xep i)
ll dp(ll si, ll mask){
	if(f[si][mask] != -1) return f[si][mask];
	mask += 1<<si;
	if(mask == (1<<N)-1) return 1; // 1 cah xem duy nhat
	ll ans = 0;
	for(ll i = 0;i<N;i++){
		if(mask & (1<<i)) continue;
		if(abs(S[si] - S[i]) <= K ) continue;
		ans+= dp(i,mask);
	}
	return f[si][mask-(1<<si)] = ans;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);*/
	cin>>N>>K;
	for(ll i=0;i<N;i++) cin>>S[i];
	// solve
	memset(f,-1,sizeof f);
	ll ans = 0;
	for(ll i=0;i<N;i++){
		ans+=dp(i,0);
	}
	cout<<ans<<endl;
	return 0;
}