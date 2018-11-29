#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll base = 31; // 311
const ll mod = 1e9 + 3;
const ll maxN = 1e6 + 3;
string s;
ll m, Pow[maxN], hashS[maxN];

void init(){
	Pow[0] = 1;
	hashS[0] = 0;
	for(int i= 1;i<= m;i++){
		Pow[i] = (Pow[i-1]*base)%mod;
		hashS[i] = (hashS[i-1]*base + s[i] - 'a' + 1)%mod;
	}
}
ll getHash(int i, int j){
	return (hashS[j] - hashS[i-1] * Pow[j-i+1] + mod*mod) % mod;
}
int main(){
	cin>>s;
	m = s.size();
	s = " " + s;
	init();
	return 0;
}