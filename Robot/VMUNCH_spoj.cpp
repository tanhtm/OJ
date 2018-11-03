#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n,m;
char M[1005][1005];
int D[1005][1005];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue < ii >  Q;
int xB,yB,xC,yC;
void Push(int x, int y){
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++){
		int u = x+ dx[i];
		int v = y+ dy[i];
		//cout<<u<<" "<<v<<" "<<M[u][v]<<endl;
		if(M[u][v] == '.'){
			Q.push(ii(u,v));
			D[u][v] = D[x][y] + 1;
			M[u][v] ='#';
		}
	}
}
void Print(){
	for(int i= 0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			cout<<M[i][j];
		}
		cout<<endl;
	}
}
int bfs(int x, int y){
	Q.push(ii(x,y));
	M[x][y] ='#';
	D[x][y] = 0;
	while(!Q.empty()){
		ii t = Q.front();
		x = t.first;
		y = t.second;
		if(x == xC && y == yC) return D[x][y];
		Q.pop();
		Push(x,y);
		//Print();
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n>>m;
	memset(M,'*',sizeof M);
	for(int i= 1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>M[i][j];
			if(M[i][j] == 'B'){
				xB = i;
				yB = j;
			}
			if(M[i][j] == 'C'){
				xC = i;
				yC = j;
			}
		}
	}
	M[xC][yC] = '.';
	cout<<bfs(xB,yB)<<endl;
	return 0;
}