#include <bits/stdc++.h>
using namespace std;
int l,n;
int c[55];
int memo[55][55];
int cut(int left, int right){
	if(left == right - 1) return 0;
	if(memo[left][right] != -1) return memo[left][right];
	int ans = -1;
	for(int i=left+1;i<right;i++){
		int r = c[right] - c[left] + cut(left,i) + cut(i,right);
		if(ans == -1) ans = r;
		else ans = min(ans,r);
	}
	return memo[left][right] = ans;
}
int main(){
	while(cin>>l && l!= 0){
		cin>>n;
		c[0] = 0;
		for(int i=1;i<=n;i++) cin>>c[i];
		c[n+1] = l;
		memset(memo,-1,sizeof memo);
		//cout<<cut(0,n+1)<<endl;
		printf("The minimum cutting is %d.\n", cut(0, n + 1));
	}
	return 0;
}