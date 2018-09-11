#include <bits/stdc++.h>
using namespace std;
int n,k;
int f[1005]; // f[i] la so lan lat min de 0->i la turn over
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n>>k;
	for(int i=1;i<=n;i++) f[i] = 1e9;
	f[0] = 0;
	for(int i=1;i<=n;i++){
		if(i-k<1) continue;
		// neu lat i;
		f[i] = min(f[i],f[i-k-1]+1);
	}
	cout<<f[n]<<endl;
	return 0;
}