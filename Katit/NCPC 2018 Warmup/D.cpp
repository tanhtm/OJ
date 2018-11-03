#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m;
ll a[1000005];
ll check(ll x){
	ll s = 0;
	for(ll i=1;i<=n;i++){
		if(a[i] > x) s+= a[i] - x; 
	}
	return s;
}
ll bs(ll l, ll r){
	//cout<< l <<" "<<r <<endl;
	if(l == r) return l;
	if(l == r - 1){
		ll x = check(l);
		ll y = check(r);
		pair < int , int > ix(x,l),iy(y,r);
		if(x > y) swap(ix,iy);
		if(ix.first < m) return iy.second;
		return ix.second;
	}
	ll mid = (l+r)/2;
	ll x = check(mid);
	/*ll y = check(mid + 1);
	if (x > m && y < m)
		return x;*/
	if(x > m) return bs(mid,r);
	return bs(l,mid); 
} 
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>m;
	ll Max = 0;
	for(ll i=1;i<=n;i++){
		 cin>>a[i];
		 Max = max(Max, a[i]);
	}
	//cout<<Max<<endl;
	cout<<bs(0,Max)<<endl;
	return 0;
}