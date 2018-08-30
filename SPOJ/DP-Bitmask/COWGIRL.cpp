#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll T,M,N;
// M*N <= 30 => Se ton tai M <= 5 (M < N)
ll f[1<<6][36]; // loai bo truong hop M = 1 => Nmax = 15
// f[x][n] la so cach xep cac dong >= n voi x la trang thai cua dong n-1 
bool checkStt(ll s1, ll s2){
	for(ll i = 0;i<M-1;i++){
		if((s1 & (1<<i)) && (s2 & (1<<i)) && (s1 & (1<<(i+1))) && (s2 & (1<<(i+1))))
			return false;
		if(!(s1 & (1<<i)) && !(s2 & (1<<i)) && !(s1 & (1<<(i+1))) && !(s2 & (1<<(i+1))))
			return false;
	}
	return true;
}
ll dp(ll mask, ll n){
	if(n == N) return 1; // qua N dong => so cach xep dong n voi mask = 1
	if(f[mask][n] != -1) return f[mask][n];
	ll ans = 0;
	for(ll i=0;i< (1<<M);i++){
		if(!checkStt(mask,i)) continue;
		ans += dp(i,n+1);
	}
	return f[mask][n] = ans;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>T;
	while(T--){
		cin>>M>>N;
		if(M > 5) swap(M,N);
		memset(f,-1,sizeof f);
		ll ans = 0;
		for(ll i=0;i< (1<<M);i++){
			ans += dp(i,1); // trang thai i bat dau tu dong dau tien 0 => tinh dong 1
		}
		cout<<ans<<endl;
	}
	return 0;
}