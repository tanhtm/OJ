#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int p,q,s;
	cin>>p>>q>>s;
	int ucln = gcd(p,q);
	int bcnn = p*q/ucln;
	if(bcnn<=s) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
 	return 0;
}