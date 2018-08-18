#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int n,m;
vector < int > DSK[1000003];
vector < bool > mark(1000003);
int p[1000003];
void dfs(int v){
	mark[v] = true;
	for(int i=0;i<DSK[v].size();i++){
		int u = DSK[v][i];
		if(p[v] == 1) p[u] = 2;
		else p[u] = 1;
		if(!mark[u]) dfs(u);
	}
}
int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int x,y;
		cin>>x>>y;
		DSK[x].push_back(y);
	}
	p[1] = 1;
	dfs(1);
	vector < int > v1,v2;
	for(int i=1;i<=n;i++){
		if(p[i] == 1) v1.push_back(i);
		else v2.push_back(i);
	}
	cout<<v1.size()<<endl;
	for(int i = 0;i <v1.size();i++){
		cout<<v1[i]<<" ";
	}
	return 0;
}