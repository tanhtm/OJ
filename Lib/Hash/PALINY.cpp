#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n;
string s,t;
void in(){
	cin>>n;
	cin>>s;
	//n = 9;
	//s = "adscabacd";
	for(int i= n-1; i>=0;i--){
		t+=s[i];
	}
}
// hash
const ll MOD = 1e9+7,base = 311;
vector < ll > hashS, pow, hashT;
void init(){
	hashS.resize(n+1);
	pow.resize(n+1);
	hashT.resize(n+1);
	pow[0]= 1;
	hashT[0]= t[0] - 'a' + 1;
	hashS[0]= s[0] - 'a' + 1;
	for(int i= 1;i< n;i++){
		pow[i] = (pow[i-1]*base)%MOD;
		hashS[i] = (hashS[i-1]* base+ s[i]- 'a'+ 1)%MOD;
		hashT[i] = (hashT[i-1]* base+ t[i]- 'a'+ 1)%MOD;
		//cout<<pow[i]<<" "<<hashS[i]<<" "<<hashT[i]<<endl;
	}
}
ll getHashS(int i, int j){
	if(i==0) return hashS[j];
	return (hashS[j] - hashS[i-1]* pow[j-i+1] +MOD*MOD)%MOD;
}
ll getHashT(int i, int j){
	if(i==0) return hashT[j];
	return (hashT[j] - hashT[i-1]* pow[j-i+1] +MOD*MOD)%MOD;
}
bool checkHash(int i, int j){
	if(getHashS(i,j) == getHashT(n-j-1,n-i-1)) return 1;
	return 0;
}
int main() {
	in();
	init();
	/*cout<<t<<endl;
	cout<<getHashS(0,2)<<" "<<getHashT(5-2-1,5-0-1)<<endl;*/
	ll ans = 1;
	for(ll i=1; i< n; i++){
		ll l = 0, r = min(i, n - i);
        while (l <= r) {
            ll mid = (l + r)/2;
            if (checkHash(i - mid +1, i + mid-1))
                ans = max(ans, (mid-1)*2), l = mid + 1;
            else
                r = mid - 1;
        }
        // odd palindrome
        l = 0, r = min(i - 1, n - i);
        while (l <= r) {
            ll mid = (l + r ) /2;
            if (checkHash(i - mid +1, i + mid -1))
                ans = max(ans, (mid-1)*2+1), l = mid + 1;
            else
                r = mid - 1;
        }
		//

	}
	cout<<ans<<endl;
	return 0;
	
}