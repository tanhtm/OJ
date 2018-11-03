#include <bits/stdc++.h>
using namespace std;
string s;
int n,m;
int D[1001][10];
int Pow(int i) // pow(10^i) % n
{
	if(i == 0) return 1;
	int r = Pow(i/2);
	r *= r;
	if(i%2 == 1) r*= 10;
	return r%n;
}
void pre(){
	for(int i=0;i<m;i++){
		D[i][0] = 0;
		D[i][1] = Pow(m-i-1);
		//cout<<D[i][1]<<" ";
		for(int j =2;j<10;j++){
			D[i][j] = (D[i][1]*j)%n;
			//cout<<D[i][j]<<" ";
		}
		//cout<<endl;
	}

}
int memo[1001][1001];
bool DP(int i, int d){
	if(d < 0) d+= n;
	d %= n;
	if(d == 0 && i == m) return 1;
	if(i == m) return 0;
	if(memo[i][d] != -1) return memo[i][d];
	if(s[i] != '?') return memo[i][d] = DP(i+1, d - D[i][s[i]-'0']);
	for(int j = 0;j < 10;j++){
		if(i == 0 && j == 0) continue;
		if(DP(i+1,d - D[i][j])){
			s[i] = j+ '0';
			return memo[i][d] = 1;
		}
	}
	return memo[i][d] = 0;
}
int main(){
	cin>>s>>n;
	m = s.size();
	pre();
	memset(memo, -1, sizeof memo);
	bool b = DP(0,n);
	if(!b) cout<<"*"<<endl;
	else cout<<s<<endl;
	return 0;
}