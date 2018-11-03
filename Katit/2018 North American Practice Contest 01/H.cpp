#include <bits/stdc++.h>
using namespace std;
int m,n;
char a[105][105];
void dfs(int x, int y){
	if(a[x][y] == '.') return;
	a[x][y] = '.';
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	dfs(x+1,y-1);
	dfs(x+1,y+1);
	dfs(x-1,y-1);
	dfs(x-1,y+1);
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>m>>n;
	memset(a,'.',sizeof a);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int d = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] == '#'){
				dfs(i,j);
				d++;
			}
		}
	}
	cout<<d<<endl;
	return 0;
}