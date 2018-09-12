#include <bits/stdc++.h>
using namespace std;
int t,n,N;
char s[26];
int f[26];
/*
chuyen bai toan ve dang 01 => xoa tu so 1 di(luu y cap nhap luc xoa)
vi du: 
babbbaaabb => 00111 ( >1  thi gan la 1)
=> 011 => 1
*/
map < string , int > dp;// dp[s] = 1 => true  = -1 => false
int DP(string sbit){
	//cout<<sbit<<endl;
	int x = dp[sbit];
	if(x != 0){
		return x;
	}
	if(sbit.size()== 0) return 1;
	for(int i=0;i<sbit.size();i++){
		if(sbit[i] == '1'){
			string t = sbit;
			t.erase(t.begin()+i);
			int b;
			if(i==0 || i == sbit.size() -1) b = DP(t);
			else{
				t[i] = '1';
				t.erase(t.begin()+i-1);
				b = DP(t);
			}
			if(b==1) return dp[sbit] = 1;
		}
	}
	return dp[sbit] = -1;
}
void solve(){
	memset(f,0,sizeof f);
	dp.clear();
	string str;
	cin>>str;
	s[0] = str[0];
	f[0] = 1;
	n = N = 0;
	for(int i=1;i<str.size();i++){
		if(str[i] == s[n])
			f[n]++;
		else{
			n++;
			s[n]=str[i];
			f[n] = 1;
		}
	}
	string sbit(n+1,' ');
	for(int i=0;i<=n;i++){
		if(f[i] > 1) sbit[i] = '1';
		else sbit[i] = '0';
	}
	//cout<<sbit<<endl;
	int x = DP(sbit);
	if(x == 1) cout<<x<<endl;
	else cout<<0<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}