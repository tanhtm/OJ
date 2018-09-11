#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_N = 51;
const int MAX_P = 13;
int n,m,p;
int D[MAX_N][MAX_N];
int ind[MAX_P], val[MAX_P];
int memo[MAX_P][1<<MAX_P]; //memo[i][mask] so tien tiet kiem dc khi xet den ind[i] tai trnag thai mask
void reset(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++) D[i][j] = INF;
	}
	memset(memo,-1,sizeof memo);
}
void floy(){
	for(int i=0;i<=n;i++) D[i][i] = 0;
	for(int k = 0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
int tsp(int i, int mask){
	if(mask == (1<<(p+1))-1) return -D[ind[i]][0];
	if(memo[i][mask] != -1) return memo[i][mask];
	int ans = -D[0][ind[i]];
	for(int j=0;j<=p;j++){
		if(mask & (1<<j)) continue;
		int x = val[j] - D[ind[i]][ind[j]] + tsp(j,mask + (1<<j));
		ans = max(ans,x);
	}
	return memo[i][mask] = ans;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);*/
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		reset();
		int x,y;
		double v;
		for(int i=0;i<m;i++){
			cin>>x>>y>>v;
			int t = v*1000;
			D[x][y] = D[y][x] = min(D[x][y],t);
		}
		floy();
		cin>>p;
		val[0] = 0;
        ind[0] = 0;
		for(int i=1;i<=p;i++){
			cin>>ind[i]>>v;
			val[i] = v*1000;
		}
		int r = tsp(0,1);
		if(r > 0)
			printf("Daniel can save $%.2f\n", double(r)/1000);
        else
            printf("Don't leave the house\n");
	}
	return 0;
}