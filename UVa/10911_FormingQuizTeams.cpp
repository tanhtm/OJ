#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n,N;
ii listS[17];
double D[17][17],memo[1<<16];
void input(){
	string s;
	int x, y;
	N = 2*n;
	for(int i=0;i<N;i++){
		cin>>s>>x>>y;
		listS[i] = ii(x,y);
	}
}
double getDistance(ii a, ii b){
	int x = a.first - b.first;
	int y = a.second - b.second;
	x = x*x;
	y = y*y;
	return double(sqrt(x+y));
}
double dp(int mask){
	if(mask == ((1<<N)-1)) return 0;
	if(memo[mask] != -1) return memo[mask];
	double ans = -1;
	for(int i=0;i<N;i++){
		if(mask & (1<<i)) continue;
		for(int j= 0;j<N;j++){
			if(mask & (1<<j)) continue;
			if(i == j) continue;
			int m = mask + (1<<i) + (1<<j);
			double r = D[i][j] + dp(m);
			if(ans == -1) ans = r;
			ans = min(ans,r);
		}
	}
	return memo[mask] = ans;
}
double solve(){
	for(int i=0;i<N;i++){
		for(int j = 0;j<N;j++){
			D[i][j] = getDistance(listS[i],listS[j]);
			//cout<<D[i][j]<<" ";	
		}
		//cout<<endl;
	}
	for(int i=0;i<(1<<N);i++) memo[i] = -1;
	return dp(0);
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);*/
	int c = 0;
	while(cin>>n && n != 0){
		c++;
		input();
		printf("Case %d: %.2lf\n",c,solve());
	}
	return 0;
}