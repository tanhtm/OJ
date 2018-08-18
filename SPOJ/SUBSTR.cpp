#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e6+7;
typedef long long int ll;
ll Pow[MAXN];
ll hashA[MAXN];
ll hashB;
int base = 311;
const ll MOD = 1e9+3;
string a,b;
int n,m;
ll getHash(int i, int j){
	if(i == 0) return hashA[j];
	return (hashA[j] - hashA[i-1]*Pow[j-i+1] + MOD*MOD)%MOD;
}
int main(){
	cin>>a>>b;
	n = a.size(); m= b.size();
	Pow[0] = 1;
	for(int i = 1; i<n; i++) Pow[i] = (Pow[i-1]*base)%MOD;
	hashB = b[0];
	for(int i = 1; i<m;i++)
		hashB = (hashB * base + b[i])%MOD;
	hashA[0] = a[0];
	for(int i = 1;i<n;i++)
		hashA[i] = (hashA[i-1]*base + a[i])%MOD;
	for(int i = 0; i<= n-m;i++){
		if(hashB == getHash(i,i+m-1)) cout<<i+1<<" ";
	}
	return 0;
}