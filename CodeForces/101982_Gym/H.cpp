#include <bits/stdc++.h>
using namespace std;
int x;
bool isPrime[1000001];
vector < int > Primes;
void sanNguyenTo(){
	memset(isPrime, 1, sizeof isPrime);
	isPrime[1] = 0;
	isPrime[0] = 0;
	for(long long int i=2;i<1000000;i++){
		if(isPrime[i] == false) continue;
		Primes.push_back(i);
		//cout<<i<<endl;
		if(i*i > 1e6) continue;
		for(int j = i*i; j<=1e6;j+= i){
			isPrime[j] = 0;
			//cout<<j<<" ";
		}
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>x;
	int d =0;
	sanNguyenTo();
	while(x >= 4){
		int p, q;
		p = q = 0;
		for(int i = 0;i< Primes.size();i++){
			if(i > x) break;
			if(isPrime[x- Primes[i]]){
				p = Primes[i];
				q = x - Primes[i];
				break;
			}
		}
		if(p == 0) break;
		//cout<<p<<" "<<q<<endl;
		d++;
		x = abs(p- q);
	}
	cout<<d<<endl;
	return 0;
}