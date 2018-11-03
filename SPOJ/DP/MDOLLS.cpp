#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int m;
ii doll[20002];
int dp(){
	vector < ii > H(m,ii(1e9,1e9));
	H[0] = ii(0,0);
	int r = 0;
	for(int i=0;i<m;i++){
		int p = lower_bound(H.begin(), H.end(), doll[i]) - H.begin();
		H[p] = min(H[p],doll[i]);
		r = max(r,p);
	}
	return r;
}
int main(){
	freopen("data.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>m;
		for(int i=0;i<m;i++){
			int w,h;
			cin>>w>>h;
			doll[i] = ii(w,h);
		}
		sort(doll,doll+m);
		cout<<dp()<<endl;
	}
	return 0;
}