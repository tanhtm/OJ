#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, a[2005],lis[2005],lds[2005];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=n-1;i>=0;i--){
			lis[i] = 1;
			for(int j= i+1;j<n;j++){
				if(a[i] < a[j]){
					lis[i] = max(lis[j]+1,lis[i]);
				}
			}
		}
		for(int i=n-1;i>=0;i--){
			lds[i] = 1;
			for(int j= i+1;j<n;j++){
				if(a[i] > a[j]){
					lds[i] = max(lds[j]+1,lds[i]);
				}
			}
		}
		ll ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans, lis[i] + lds[i] -1);
		}
		cout<<ans<<endl;
	}
	return 0;
}