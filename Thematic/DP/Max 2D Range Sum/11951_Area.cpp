#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAX = 105;
ll N,M,K,S,P;
static ll p[MAX][MAX];
void input(){
	cin>>N>>M>>K;
	for(ll i=1;i<=N;i++){
		for(ll j=1;j<=M;j++){
			cin>>p[i][j];
		}
	}
}
void solve(){
	for(ll i =1;i<=N;i++)
		for(ll j=1;j<=M;j++)
			p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
	/*for(ll i =1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}*/
	S = 0;
	P = 0;
	for(ll i =1;i<=N;i++){
		for(ll j=1;j<=M;j++){
			for(ll k=i;k<=N;k++){
				for(ll h=j;h<=M;h++){
					ll a = p[k][h] - p[i-1][h] - p[k][j-1] + p[i-1][j-1];
					ll b = (k - i + 1) * (h - j + 1);
					if(a <= K){
						if(S < b){
							S = b;
							P = a;
						}
						if(S == b) P = min(P,a);
					}
				}
			}
		}
	}
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int t,c= 1;
	cin>>t;
	while(c <= t){
		input();
		solve();
		printf("Case #%d: %d %d\n",c,(int)S,(int)P);
		c++;
	}
	return 0;
}