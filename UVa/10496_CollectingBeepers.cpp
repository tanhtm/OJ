#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int szx,szy,n;
int X[11],Y[11];
int dist[11][11], memo[11][1<<11]; // max 10 beepers
int tsp(int pos, int mask){
	if(mask == (1<<(n+1)) - 1) return dist[pos][0]; //// return trip to close the loop
	if(memo[pos][mask] != -1) return memo[pos][mask];
	int ans = 1e9;
	for(int i = 0;i<=n;i++)
		if(i != pos && !(mask & (1<<i)))
			ans = min(ans,dist[pos][i] + tsp(i,mask|(1<<i)));
	return memo[pos][mask] = ans;
}
void solve(){
	memset(memo,-1,sizeof memo);
	for(int i=0;i<= n;i++) // build distance table
		for(int j= 0;j<= n;j++)
			dist[i][j]= abs(X[i]- X[j])+ abs(Y[i]- Y[j]);
	/*for(int i=0;i<= n;i++){
		for(int j= 0;j<= n;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}*/
	printf("The shortest path has length %d\n", tsp(0, 1)); // DP-TSP

}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>szx>>szy;
		cin>>X[0]>>Y[0];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>X[i]>>Y[i];
		}
		solve();
	}

	return 0;
}