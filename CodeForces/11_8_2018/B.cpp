#include <iostream>
#include <math.h>
using namespace std;
int patent[1003];
int  f[1003]; // tan so
int n;
void reset(){
	for(int i = 1;i<= n; i++){
		f[i] = 0;
	}
}
int dfs(int i){
	while(true){
		f[i]++;
		if(f[i] == 2) return i;
		i = patent[i];
	}
}
void solve(){
	for(int i = 1;i <=n;i++){
		reset();
		cout<<dfs(i)<<" ";
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n;
	for(int i = 1; i<=n;i++){
		cin>>patent[i];
	}
	solve();
	return 0;
}