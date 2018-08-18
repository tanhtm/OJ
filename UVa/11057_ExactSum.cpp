#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector < int > a;
int m;
int findId(int l, int r, int val){ 
	if(l == r) return l;
	int mid = (l+r)/2;
	if(a[mid] == val) return mid;
	if(a[mid] > val) return findId(l,mid,val);
	return findId(mid+1,r,val);
}
void solve(){
	sort(a.begin(),a.end());
	int M = m/2;
	int i = findId(0,n-1,M),j=findId(0,n-1,m - a[i]);
	while(a[j] != m - a[i]){
		i--;
		j=findId(0,n-1,m - a[i]);
	}
	int x = a[i], y= a[j];
	if(x>y)swap(x,y);
	cout<<"Peter should buy books whose prices are "<<x<<" and "<<y<<"."<<endl;
}
int main(){
	while(cin>>n){ 
		a.resize(n);
		for(int i=0;i<n;i++) cin>>a[i];
		cin>>m;
		solve();
		cout<<endl;
	}
	return 0;
}