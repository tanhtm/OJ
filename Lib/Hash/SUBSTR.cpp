#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string t,p;
const ll base = 311;
const ll MOD = 1e9 + 3;
const ll MAXN = 1e6+ 3;
ll POW[MAXN], hashT[MAXN], hashP;
ll getHash(int i, int j){
	return (hashT[j] - hashT[i-1]*POW[j-i+1] + MOD*MOD)%MOD;
}
int main(){
	//freopen("data.in","r",stdin);
	cin>>t>>p;
	t = " " + t;
	p = " " + p;
	// POW[i] = base^i
	POW[0] = 1;
	for(int i= 1; i< t.size(); i++)
		POW[i] = (POW[i-1]*base)%MOD;
	//hashP 
	hashP = 0;
	for(int i= 1; i< p.size();i++)
		hashP = (hashP*base + p[i] - 'a' + 1)% MOD;

	//hashT
	hashT[0] = 0;
	for(int i= 1; i< t.size();i++)
		hashT[i] = (hashT[i-1]*base + t[i] - 'a' + 1) %MOD;
	for(int i= 1; i< t.size(); i++){
		if(i+ p.size() - 2 > t.size() - 1) break;
		ll h = getHash(i, i+ p.size() - 2);
		if(h == hashP) cout<<i<<" ";
	}
	return 0;
}