#include <bits/stdc++.h>
using namespace std;
int t, n, k;
//int A[100005];
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
int main(){
	freopen("looking.in","r",stdin);
	//bitset<20> ans;
	int x;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int ans = 0;
		for(int i=0;i< n;i++){
			x = read();
			ans |= x;
		}
		//int res = (int)ans.to_ulong();
		cout<<ans<<endl;
	}
	return 0;
}