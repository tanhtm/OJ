#include <bits/stdc++.h>
using namespace std;
int n,m;
int t[200002], l[200002];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>t[i];
	for(int i=0;i<m;i++) cin>>l[i];
	sort(t,t+n);
	sort(l,l+m);
	int top = m-1, r= 0;
	for(int i=n-1;i>=0;i--){
		if(l[top] >= t[i]){
			r++;
			top--;
		}
		if(top == -1) break;
	}
	cout<<r<<endl;
	return 0;
}