#include <bits/stdc++.h>
using namespace std;
long long int powMod(long long int b, long long int p, long long int m){
	if(p == 1) return b%m;
	if(p == 0) return 1;
	long long int r = powMod(b,p>>1,m);
	r*= r;
	r %= m;
	if(p % 2 != 0) r*= b;
	r %= m;
	return r;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	long long int b,p,m;
	while(cin>>b>>p>>m){
		cout<<powMod(b,p,m)<<endl;
	}
	return 0;
}