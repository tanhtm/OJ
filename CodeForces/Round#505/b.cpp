#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
int main(){
	ll n;
	cin>>n;
	ll res = 0;
	ll a,b;
	for(ll i=0;i<n;i++){
		cin>>a>>b;
		res = gcd(res,a*b);
	}
	res = max(gcd(res,a),gcd(res,b));
	if(res == 1) {
		cout<<-1<<endl;
		return 0;
	}
	for(int i=2;i<=sqrt(res);i++){
		if(res%i == 0){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<res<<endl;
	return 0;
}