#include <bits/stdc++.h>
using namespace std;
const int NMAX = 16, BMAX = 1<<16;
int n;
int a[NMAX][NMAX];
int f[NMAX][BMAX];// f[i][x] : quang duong ton it phi nhat khi di het trang thai x ket thuc tai thanh pho i
void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
}
int dp(int pos, int mask){
	if(mask == 0) return 0;
	if(mask == (1<<pos)) return f[pos][mask];
	if(f[pos][mask] != -1) return f[pos][mask];
	int ans = 1e9;
	for(int i=0;i<n;i++){
		if(i==pos) continue;
		if((mask & (1<<i)) == 0) continue;
		ans = min(ans,dp(i,mask - (1<<pos))+ a[i][pos]); 
	}
	return f[pos][mask] = ans;
}
int main(){
	input();
	memset(f,-1,sizeof f);
	for(int i=0;i<n;i++) f[i][1<<i] = 0;
	int ans = 1e9;
	for(int i=0;i<n;i++){
		ans = min(ans,dp(i,(1<<n)-1));
	}
	cout<<ans<<endl;
	return 0;
}