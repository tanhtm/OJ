#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	long long int n,x,f;
	cin>>n;
	vector < long long int > a;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	cin>>x>>f;
	long long int r = 0;
	for(int i=0;i<n;i++){
		if(a[i] <= x) continue;
		long long int y = a[i] / (x+f);
		long long int z = a[i] - y*(x+f);
		if(z > x) y++;
		if(y == 0) y = 1;
		r+= y; 
		
	}
	cout<<r*f<<endl;
	return 0;
}