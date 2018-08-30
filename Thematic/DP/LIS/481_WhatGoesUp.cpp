#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
vector < ll > a;
vector < ll > h; // h[i] la so lon nhat trong day tang voi do dai la i
vector < ll > id,d; // d[i] luu vet
ll findBS(ll l, ll r, ll v){
	if(l == r) return l;
	ll mid = (l+r)/2;
	if(h[mid] >= v) return findBS(l,mid,v);
	else return findBS(mid+1,r,v);
}
void out(ll end){
	if(end < 0) return;
	out(d[end]);
	cout<<a[end]<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	ll x;
	while(cin>>x)
		a.push_back(x);
	n = a.size();
	h.resize(n+1,1e18);
	h[0] = -1e18;
	id.resize(n+1,-1);
	d.resize(n+1,-1);
	ll ans =0;
	for(ll i = 0;i<n;i++){
		ll p = findBS(1,n,a[i]);
		ans = max(ans,p);
		h[p] = a[i];
		id[p] = i;
		d[i] = id[p-1];
	}
	cout<<ans<<endl<<'-'<<endl;
	out(id[ans]);
	return 0;
}