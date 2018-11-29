#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int n, s;
	cin>>n>>s;
	int m = 0;
	for(int i= 0;i<n;i++){
		int x;
		cin>>x;
		m = max(m, x);
	}
	m*= s;
	int mod = m % 1000;
	m/= 1000;
	if(mod != 0) m++;
	cout<<m<<endl;
	return 0;
}