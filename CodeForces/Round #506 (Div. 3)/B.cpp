#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > a;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	int ans = 0;
	int d = 0;
	a.resize(n);
	cin>>a[0];
	d = 1;
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i-1]*2 >= a[i]) d++;
		else{
			ans = max(ans,d);
			d = 1;
		}
	}
	ans = max(ans,d);
	cout<<ans<<endl;
	return 0;
}