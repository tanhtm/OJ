#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
typedef long long int ll;
const ll MAXN = 50003;
ll n; // do dai xau
string s,t;
ll base = 311;
ll MOD = 1e9+11;
ll Pow[MAXN];
ll hashS[MAXN], hashT[MAXN];
void init(){
	Pow[0] = 1;
	for(int i = 1;i<= n;i++)
		Pow[i] = (Pow[i-1]*base)%MOD;
	for(int i = n-1; i>=0;i--) t+=s[i];
	/// hashS
	hashS[0] = s[0];
	hashT[0] = t[0];
	for(int i =1;i<n;i++){
		hashS[i] = (hashS[i-1]*base + s[i])%MOD;
		hashT[i] = (hashT[i-1]*base + t[i])%MOD;
	}
}
ll getHashS(int i, int j){
	if(i == 0) return hashS[j];
	return (hashS[j] - hashS[i-1]*Pow[j-i+1] +MOD*MOD) % MOD;
}
ll getHashT(int i, int j){
	if(i == 0) return hashT[j];
	return (hashT[j] - hashT[i-1]*Pow[j-i+1] +MOD*MOD) % MOD;
}
bool KiemTraDoDai(int doDai){
	for(int i = 0 ; i<=n-doDai;i++){
		int j = i + doDai -1;
		ll x = getHashS(i,j);
		ll y = getHashT(n-j-1,n-i-1);
		if(x == y){
			//cout<<doDai<<endl;
			return true;
		}
	}
	return false;
}
int TimDoDaiXauLe(int l, int r){
	if(l >= r) return l;
	if(r - l == 1){
		if(KiemTraDoDai((r-1)*2+1)) return r;
		return l;
	}
	int mid = (l+r)/2;
	if(KiemTraDoDai((mid-1)*2+1)) return TimDoDaiXauLe(mid, r);
	return TimDoDaiXauLe(l,mid-1);
}
int TimDoDaiXauChan(int l, int r){
	//cout<<l<<" "<<r<<endl;
	if(l >= r) return l;
	if(r - l == 1){
		if(KiemTraDoDai(r*2)) return r;
		return l;
	}
	int mid = (l+r)/2;
	//cout<<mid<<endl;
	if(KiemTraDoDai(mid*2)) return TimDoDaiXauChan(mid, r);
	return TimDoDaiXauChan(l,mid-1);
}
void solve(){
	init();
	/// tim voi xau do dai le
	int x =TimDoDaiXauLe(1,n/2+1);
	//cout<<endl;
	int y =TimDoDaiXauChan(0,n/2);
	//cout<<x<<endl;
	//cout<<y<<endl;
	cout<<max((x-1)*2+1,y*2)<<endl;
}
int main(){
	cin>>n>>s;
	if(n <= 0) {
		cout<<0<<endl;
	}
	else solve();
	return 0;
}