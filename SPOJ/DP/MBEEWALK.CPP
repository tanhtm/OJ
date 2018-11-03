#include <bits/stdc++.h>
using namespace std;
const double c3 = sqrt(3.0);
const int M = 50;
int memo[100][5000][15];
int dp(int x, double y, int n){
	//cout<<x<<" "<<y<<" "<<n<<endl;
	if(x == M && (int)(y*100) == M*100 && n == 0)
		return 1;
	if(n == 0) return 0;
	if(memo[x][int(y*100)][n] != -1) return memo[x][int(y*100)][n];
	int r = 0;
	r += dp(x+2,y,n-1);
	r += dp(x-2,y,n-1);
	r += dp(x-1,y-c3,n-1);
	r += dp(x-1,y+c3,n-1);
	r += dp(x+1,y-c3,n-1);
	r += dp(x+1,y+c3,n-1);
	return memo[x][int(y*100)][n] = r;
}
int main(){
	int t,n;
	cin>>t;
	memset(memo, -1, sizeof memo);
	while(t--){
		cin>>n;
		cout<<dp(M,M,n)<<endl;
	}
	return 0;
}