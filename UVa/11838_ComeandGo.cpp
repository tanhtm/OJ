#include <bits/stdc++.h>
using namespace std;
const int MAX = 2002;
int n,m,cnt = 0;
vector < int > dsk[MAX];
bool visited[MAX];
int low[MAX],num[MAX];
vector < int > S;
void reset(){
	for(int i=1;i<=n;i++){
		dsk[i].clear();
		visited[i] = 0;
		low[i] = num[i] = 0;
	}
	S.clear();
}
int tarjanSCC(int u){
	visited[u] = 1;
	low[u] = num[u] = cnt++;
	S.push_back(u);
	for(int i=0;i<dsk[u].size();i++){
		int v = dsk[u][i];
		if(!visited[v]) tarjanSCC(v);
		low[u] = min(low[u],low[v]);
	}
	int d = 0;
	if(low[u] == num[u]){
		while(true){
			d++;
			int v = S.back();S.pop_back();
			//cout<<v<<" ";
			visited[v] = 0;
			if(v == u) break;
		}
		//cout<<endl;
	}
	return d;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>n>>m && n != 0){
		reset();
		int v,w,p;
		for(int i=0;i<m;i++){
			cin>>v>>w>>p;
			dsk[v].push_back(w);
			if(p == 2) dsk[w].push_back(v); 
		}
		cnt = 0;
		int d = tarjanSCC(1);
		if(d == n && low[1] == num[1]){
			cout<<1<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}