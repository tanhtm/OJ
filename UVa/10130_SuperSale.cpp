#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1003,MAX_W = 33;
int n,g,x,t;
int P[MAX_N],W[MAX_N];
int F[MAX_N][MAX_W]; // F[i][j] la gia tri co the lay lon nhat
// khi xet den mon do thu i voi khoi luon <= j
/*
F[i][j] = max(F[i-1][j],F[i][j-W[i]]+ P[i])
*/
void dp(){ //DP
	for(int i= 0;i<=30;i++)
		F[0][i] = 0;
	for(int i= 0;i<=n;i++)
		F[i][0] = 0;
	for(int i= 1;i <= n ;i++){
		for(int w= 1;w <= 30;w++){
			if(w < W[i]){
				F[i][w] = F[i-1][w];
				//cout<<F[i][w]<<" ";
				continue;
			}
			F[i][w] = max(F[i-1][w],F[i-1][w-W[i]] + P[i]);
			//cout<<F[i][w]<<"s ";
		}
		//cout<<endl;
	}
}
void run(){
	cin>>n;
	for(int i= 1;i<=n;i++){
		cin>>P[i]>>W[i];
	}
	dp();
	int res = 0;
	cin>>g;
	for(int i =0;i< g;i++){
		cin>>x;
		res+= F[n][x];
	}
	cout<<res<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>> t;
	while(t--){
		run();
	}
	return 0;
}