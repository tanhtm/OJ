#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int LOGMAX = 20;
int n,m; // m = log n
typedef pair < int , int > ii;
vector < ii > DSK[MAX+1];
struct node{int Root;int Max;int Min;};
node Up[MAX+1][LOGMAX]; // Up[i][j] la node mang root thu 2^j cua dinh i, max, min tu i den root  
bool dd[MAX+1];
int H[MAX+1]; // H[i] la tang cua dinh i tren cay
void inputGraph(){
	cin>>n;
	m = log2(n);
	for(int i=1 ;i< n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		DSK[u].push_back(ii(v,w));
		DSK[v].push_back(ii(u,w));
	}
}
void build(int u){ // khoi tao
	dd[u] = true;
	for(int i=0;i<DSK[u].size();i++){
		int v = DSK[u][i].first;
		if(!dd[v]){
			Up[v][0].Root = u;
			Up[v][0].Max = DSK[u][i].second;
			Up[v][0].Min = DSK[u][i].second;
			build(v);
		}
	}
}
int h = 0;
void dfs(int u,int h){
	H[u] = h;
	dd[u] = true;
	for(int i= 1; i<= m;i++){
		int r = Up[u][i-1].Root;
		Up[u][i].Root = Up[r][i-1].Root;
		Up[u][i].Max = max(Up[u][i-1].Max, Up[r][i-1].Max);
		Up[u][i].Min = min(Up[u][i-1].Min, Up[r][i-1].Min);
	}
	for(int i=0;i<DSK[u].size();i++){
		int v = DSK[u][i].first;
		if(!dd[v]) dfs(v,h+1);
	}

}
void solve(int u, int v){

}
void runQuery(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int u, v;
		cin>>u>>v;
		solve(u,v);
	}
}
int main(){
	freopen("data.txt","r",stdin);
	inputGraph();
	build(1);
	cout<<m<<endl;
	for(int i=1;i<=n;i++){
		cout<<Up[i][0].Root<<" ";
	}
	cout<<endl;
	for (int i=1;i<=n;i++) dd[i] = 0;
	dfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<H[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<Up[i][j].Root<<" "<<Up[i][j].Max<<" "<<Up[i][j].Min<<"; ";
		}
		cout<<endl;
	}
	cout<<endl;
	runQuery();
	return 0;
}