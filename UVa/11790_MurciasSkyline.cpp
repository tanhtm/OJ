#include <bits/stdc++.h>
using namespace std;
int t,n,c;
vector < int > h,w;
void in(){
	cin>>n;
	h.resize(n);
	w.resize(n);
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>w[i];
}
int lis(){
	int res = 0;
	vector < int > lis(n);
	for(int i=0;i<n;i++){
		lis[i] = w[i];
		for(int j=i-1;j>=0;j--){
			if(h[i] > h[j])
				lis[i] = max(lis[j] + w[i],lis[i]);
		}
		res = max(res,lis[i]);
	}
	return res;
}
void solve(int c){
	int LIS = lis();
	reverse(h.begin(),h.end());
	reverse(w.begin(),w.end());
	int LDS = lis();
	if(LIS >= LDS){
		printf("Case %d. Increasing (%d). Decreasing (%d).\n",c,LIS,LDS);
	}
	else printf("Case %d. Decreasing (%d). Increasing (%d).\n",c,LDS,LIS);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	c= 0;
	while(c < t){
		c++;
		in();
		solve(c);
	}
	return 0;
}