#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
vector < ll > v;
ll gcd(ll x, ll y){
	if(y == 0) return x;
	return gcd(y,x%y);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);
*/	cin>>n;
	string s;
	cin.ignore();
	while(n--){		
		v.clear();
		getline(cin,s);
		s+=' ';
		ll x = 0;
		for(ll i=0;i<s.size();i++){
			if(s[i] == ' '){
				if(x != 0) v.push_back(x);
				//cout<<x<<" ";
				x= 0;
			}else{
				x*= 10;
				x+= s[i] - '0';
			}
		}
		ll r = 0;
		for(ll i = 0 ;i< v.size();i++){
			for(ll j = i+ 1; j< v.size(); j++){
				r = max(r, gcd(v[i],v[j]));
			}
		}
		cout<<r<<endl;
	}
	return 0;
}