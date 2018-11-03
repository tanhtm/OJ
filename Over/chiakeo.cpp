#include <bits/stdc++.h>
using namespace std;
int n,sum,s = 0;
int a[202];
int f[20002][202];
int dp(int w, int i){ 
	if(f[w][i] != -1) return f[w][i];
	if(i == 0) return 0;
	if(w == 0) return 0;
	if(w < a[i]) return f[w][i] = dp(w,i-1);
	int x1 = a[i]+ dp(w-a[i],i-1);
	int x2 = dp(w,i-1);
	return f[w][i] = max(x1,x2);
}
int main(){
	freopen("x/test/input.07","r",stdin);
	memset(f,-1,sizeof f);
	cin>>n;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	s+=a[i];
	}
	sum = s;
	s/=2;
	s = dp(s,n);
	cout<<s<<" "<<sum - s<<endl;	
	cout<< abs(s- sum + s)<<endl;
	return 0;
}