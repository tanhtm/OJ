#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n,k;
int F[MAX+5][MAX+5]; // F[i][j] la dap so voi n = i, k= j
void dp(){ // n = 100, k= 100
	memset(F,0,sizeof F);
	for(int i= 0;i<= MAX;i++) F[i][1] = 1;
	for(int k= 2;k<=MAX;k++){
		for(int n = 0;n<=MAX;n++){
			for(int x= 0;x<=n;x++){
				F[n][k]+= F[n-x][k-1];
				F[n][k]%= 1000000;
			}
		}
	}
}
int main(){
	dp();
	while(cin>>n>>k && n != 0 ){
		cout<<F[n][k]<<endl;
	}
	return 0;
}