

#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u, v, w;
	void Print(){
		cout<<u<<" "<<v<<" "<<w<<endl;
	}
};
bool operator < (edge e1, edge e2){return e1.w > e2.w;}
priority_queue < edge > Heap;
vector < int > Par;
vector < int > Rank;
vector < edge > Tree;
int n,m;
void in(){
	cin>>n>>m;
	edge e;
	for(int i=0; i<m; i++){
		cin>>e.u>>e.v>>e.w;
		//e.Print();
		Heap.push(e);
	}
}
void init(){
	Par.resize(n+1);
	Rank.resize(n+1);
	for(int i=1;i<=n;i++){
		Par[i] = i;
		Rank[i] = 0;
	}
}
int GetRoot(int r){
	while(Par[r] != r) r = Par[r];
	return r;
}
void Union(int r1, int r2){
	// r1, r2: root
	if(Rank[r1] > Rank[r2])
		Par[r2] = r1;
	else
		if(Rank[r1] < Rank[r2])
			Par[r1] = r2;
		else{
			Par[r2] = r1;
			Rank[r1]++;
		}
}
bool kruskal(){
	int r1, r2;
	edge e;
	while(!Heap.empty()){
		e = Heap.top(); Heap.pop();
		r1 = GetRoot(e.u);
		r2 = GetRoot(e.v);
		if(r1 != r2){
			Tree.push_back(e);
			if(Tree.size()== n-1) return true;
			Union(r1, r2);
		}
	}
	return false;
}
int main(){
	freopen("data.in","r",stdin);
	in();
	init();
	cout<<kruskal()<<endl;
	for(int i=0;i<n-1;i++){
		edge e = Tree[i];
		e.Print();
	}
	return 0;
}
for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
				a[i][j] = oo;
for (i=1; i<=n; i++)
		a[i][i] = 0;
for (i=1; i<=m; i++){
		cin>>p>>q>>w;
		a[p][q] = a[q][p] = w;
}
for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
				for (j=1; j<=n; j++)
						a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
