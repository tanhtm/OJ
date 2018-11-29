#include <bits/stdc++.h>
using namespace std;
const int oo = 1<<30;
struct edge{
	int u, w;
	edge(){}
	edge(int U, int W){
		u = U;
		w = W;
	}
};
bool operator < (edge e1, edge e2){return e1.w > e2.w;}

vector < vector < edge > > dsk;
vector < int > dist, pre;
vector < bool > visited;
priority_queue < edge > heap;
int n,m;

void in(){
	cin>>n>>m;
	dsk.resize(n+1);
	for(int i = 0; i< m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dsk[u].push_back(edge(v,w));
		dsk[v].push_back(edge(u,w));
	}
}
int dijktra(int s, int t){
	dist.resize(n+1); pre.resize(n+1);
	visited.resize(n+1);
	for(int i = 1; i<= n ;i++){
		dist[i]= oo;
		pre[i] = s;
		visited[i] = 0;
	}
	dist[s] = 0;
	heap.push(edge(s,0));
	while(!heap.empty()){
		edge e = heap.top(); heap.pop();
		int u = e.u;
		if(u == t) break;
		if(visited[u]) continue;
		for(int i= 0;i < dsk[u].size(); i++){
			int v,w;
			v = dsk[u][i].u;
			w = dsk[u][i].w;
			if(visited[v]) continue;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pre[v] = u;
				heap.push(edge(v,dist[v]));
			}
		}
		visited[u] = 1;
	}
	return dist[t];
}
int main(){
	in();
	int s,t;
	cin>>s>>t;
	cout<<dijktra(s,t)<<endl;
	return 0;
}