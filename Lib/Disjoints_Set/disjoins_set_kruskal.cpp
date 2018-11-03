#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream fi("mst.inp");
ofstream fo("mst.out");
struct edge { int u, v; double w; };
bool operator < (const edge x, const edge y){return x.w > y.w;}
priority_queue<edge> heap;
vector<int> pa;
vector<edge> tree;
int n, m;
void get_data(){
	fi >> n >> m;
	edge c;
	for (int i = 0; i < m ; i++){ 
		fi >> c.u >> c.v >> c.w; 
		heap.push(c); 
	}
}

void init(){
	pa.resize(n+1);
	for(int i = 1; i <= n; i++) pa[i] = -1;
}

int GetRoot(int r){
	while(pa[r] > 0) r = pa[r];
	return r;
}
void Union(int r1, int r2){
	int x = pa[r1] + pa[r2];
	if(pa[r1] > pa[r2]){
		pa[r1] = pa[r2];
		pa[r2] = x;
	}
	else{
		pa[r2] = pa[r1];
		pa[r1] = x;
	}
}
bool kruskal(){
	int r1, r2;
	edge e;
	while(!heap.empty()){
		e = heap.top(); heap.pop();
		r1 = GetRoot(e.u);
		r2 = GetRoot(e.v);
		if (r1 != r2){
			tree.push_back(e);
			if(tree.size() == n-1) return true;
			Union(r1, r2);
		}
	}
	return false;
}
void print(){
	int weight = 0;
	for(int i = 0; i < tree.size(); i++){
		fo <<'('<< tree[i].u <<','<<tree[i].v<<") = "<<tree[i].w << endl;
		weight += tree[i].w;
	}
	fo << weight <<endl;
	}
int main(){
	get_data();
	init();
	if(kruskal())print(); else fo ≪ "The graph isn't connected!";
	return 0;
}