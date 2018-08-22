#include <bits/stdc++.h>
using namespace std;
const int MAX =  7489;
int Coin[]={0,1,5,10,25,50};
int n;
int F[MAX+1][7]; // F[i][j] la so cach doi i xu thanh cac xu tinh tu 1 -> j
void dp(){
	for(int i= 1;i<= MAX;i++){
		F[i][0] = 0;
	}
	for(int i= 1 ;i<= MAX;i++){
		for(int j = 1;j<=5;j++){
			if(i < Coin[j]){
				F[i][j] = F[i][j-1];
				continue;
			}
			if(i == Coin[j]){
				F[i][j] = 1+ F[i][j-1];
				continue;
			}
			F[i][j] = F[i-Coin[j]][j] + F[i][j-1];
			// tong so cach chon coin j va ko chon coin j
		}
	}
}
void solve(){
	cout<<F[n][5]<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	dp();
	while(cin>>n) solve();
	return 0;
}