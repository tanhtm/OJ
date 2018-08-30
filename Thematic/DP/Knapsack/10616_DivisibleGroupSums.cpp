#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,q,d,m,r;
ll a[205],f[205][25][15]; // f[i][j][m] la so cach chon m so de tong cua m so do chia cho base du j khi xet tu 1 - i
ll dp(ll i, ll j, ll k){
	if(j < 0) j+=d;
	if(k == m && j == 0) return 1;
	if(k == m && j != 0) return 0;
	if(i == n) return 0;
	if(f[i][j][k] != -1) return f[i][j][k];
	f[i][j][k] = dp(i+1,j%d,k) + dp(i+1,(a[i]+j)%d,k+1);
	return f[i][j][k];
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int c = 1;
	while(cin>>n>>q && n != 0){
		printf("SET %d:\n",c);c++;
		for(ll i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<q;i++){
			cin>>d>>m;
			memset(f,-1,sizeof f);
			int r = dp(0,0,0);
			printf("QUERY %d: %d\n",i+1,r);
		}

	}
	return 0;
}