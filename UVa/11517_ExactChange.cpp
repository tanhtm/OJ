
//////////// Phai xem lai
#include <bits/stdc++.h>
using namespace std;
const int MAX = 400;
int t,n,m;
int b[105];
int f[50005]; // f[m] la so luong to tien de quy doi ra m cent
void solve(){
	for(int i= 0;i<=5*m;i++) f[i] = MAX;
	f[0] = 0;
	for(int i=1;i<=n;i++){
		int C = b[i];
		for (int v = 30000 - C - 1; v >= 0; v--)
        	if (f[v] < MAX)
            	f[v+C] = min(f[v+C], f[v]+1);
	}
	for(int i=m;;i++){
		if(f[i] != MAX){
			cout<<i<<" "<<f[i]<<endl;
			return;
		}
	}
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i =1;i<=n;i++) cin>>b[i];
		solve();
	}
	return 0;
}