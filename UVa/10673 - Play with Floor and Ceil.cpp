#include <bits/stdc++.h>
using namespace std;
long long int gcd_extended(long long int a, long long int b, long long int &x, long long int &y){
	long long int u1,u2,u3,v1,v2,v3,t1,t2,t3;
	u1 = 1; u2 = 0; u3 = a;
	v1 = 0; v2 = 1; v3 = b;
	while(v3 != 0){
		long long int q = u3/v3;
		t1 = u1 - q*v1;
		t2 = u2 - q*v2;
		t3 = u3 - q*v3;
		u1 = v1; u2 = v2; u3 = v3;
		v1 = t1; v2 = t2; v3 = t3;
	}
	x = u1; y= u2;
	return u3;
}
int main(){
	int t;
	cin>>t;
	long long int x,k;
	while(t--){
		cin>>x>>k;
		long long int a = x/k;
		long long int b = a;
		if(x % k != 0) b++;
		long long int p,q;
		long long int ucln = gcd_extended(a,b,p,q);
		x/= ucln;
		p*= x; q*= x;
		cout<<p<<" "<<q<<endl; 
	}
	return 0;
}