#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
int n,m,u,l,k;
int t;
vector < ii > DSK[100005];
int Rank[100005];
int res = 0;
void init(){
	for(int i=1;i<=n;i++) DSK[i].clear();
	memset(Rank, 0, sizeof Rank);
	res = 0;
}
void bfs(int x){
	queue < int > Q;
	Q.push(x);
	Rank[x] = 1;
	while(!Q.empty()){
		int U = Q.front();
		Q.pop();
		for(ii i : DSK[U]){
			int V = i.first;
			if(Rank[V] == 0){
				Rank[V] = Rank[U] + 1;
				Q.push(V);
			}
			if(Rank[V] <= k) res = max(res, i.second);
		}
	} 
}
int main(){
	freopen("path.in","r",stdin);
	t = read();
	while (t -- ) {
		cin>>n>>m>>u>>l>>k;
		init();
		for(int i=0;i<m;i++){
			int x,y,w;
			cin>>x>>y>>w;
			DSK[x].push_back(ii(y,w));
			DSK[y].push_back(ii(x,w));
		}
		bfs(u);
		cout<<res<<endl;
	}
	return 0;
}