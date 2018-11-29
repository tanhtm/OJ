#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("PALIN.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	int t,n,x,y,d;
	cin>>t;
	while(t--){
		cin>>n>>x>>y>>d;
		int ans;
		if(abs(x-y)%d == 0){
			cout<<abs(x-y)/d<<endl;
			continue;
		}
		ans = 1e9;
		int c = (x-1)/d;
		if((x-1)%d != 0) c++;
		int y_ = (y-1)%d;
		if(y_ == 0){
			c+= (y-1)/d;
			ans = min(ans,c);
		}
		c = (n-x+d-1)/d;
		y_ = (n-y)%d;
		if(y_ == 0){
			c+= (n-y)/d;
			ans = min(ans,c);
		}
		if(ans == 1e9) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}