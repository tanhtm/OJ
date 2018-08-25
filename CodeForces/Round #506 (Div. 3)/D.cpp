#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k;
ll a[11][200000],leng[200000];
map < ll , ll > c[11];
int getLength(ll x){
	int r = 0;
	while(x != 0){
		x/=10;
		r++;
	}
	return r;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[0][i];
		leng[i] = getLength(a[0][i]);
		a[0][i]%=k;
		c[leng[i]][a[0][i]]++;
	}
	for(int i=1;i<=10;i++){
		for(int j=0;j<n;j++){
			a[i][j] = a[i-1][j] * 10;
			a[i][j] %= k;
		}
	}
	ll ans = 0,x,y,z;
	for(int i=1;i<=10;i++){
		for(int j = 0;j<n;j++){
			x = a[i][j];
			y = k - x;
			if(y == k) y = 0;
			z = c[i][y];
			if(z == 0) continue;
			ans += z;
			if(leng[j] == i && y == a[0][j]) ans--;
		}
	}
	cout<<ans;
	return 0;
}