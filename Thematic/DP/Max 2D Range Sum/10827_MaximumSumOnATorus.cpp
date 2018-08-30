#include <bits/stdc++.h>
using namespace std;
static int  test, n, torus[200][200];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>torus[i][j];
	}
}
void solve(){
	if(n==1){
		cout<<max(0,torus[1][1]);
		return;
	}
	int N = 2*n;
	for(int i= 1;i<=n;i++){
		for(int j = n+1;j<=N;j++){
			torus[i][j] = torus[i][j-n];
		}
	}
	for(int i= n+1;i<=N;i++){
		for(int j=1;j<=N;j++){
			torus[i][j] = torus[i-n][j];
			//else torus[i][j] = -100; // ko lay goc thua ra
		}
	}
	/*for(int i= 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			cout<<torus[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			torus[i][j] += torus[i-1][j] + torus[i][j-1] - torus[i-1][j-1];
		}
	}
	/*cout<<endl;
	for(int i= 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			cout<<torus[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int ans = -100;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			// x(i,j) diem goc tren ben trai
			for(int k=i;k<=N;k++){
				if(k-i == n) break; // chi lay hinh max size n
				for(int h=j;h<=N;h++){
					if(h-j == n) break;
					int r = torus[k][h] - torus[i-1][h] - torus[k][j-1] + torus[i-1][j-1];
					ans = max(ans,r);
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>test;
	while(test--){
		input();
		solve();
	}
	return 0;
}