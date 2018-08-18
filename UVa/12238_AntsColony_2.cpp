#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair < int , int > ii;
const int nMax = 200007, NSTMax = 900056;
int n;
vector < ii > G[nMax];
int L[nMax],H[nMax];
vector< int > E;
ii  st[NSTMax];
long long D[nMax];
bool Mark[nMax];
void reset(){
	E.resize(1);
	for(int i = 0;i<n;i++){
		G[i].clear();
		H[i] = -1;
		D[i] = 0;
		Mark[i] = false;
	}
}
void inputGraph(){
	for(int i =1;i<n;i++){
		int x, w;
		cin>>x>>w;
		G[x].push_back(ii(i,w));
		G[i].push_back(ii(x,w));
	}
}
// LCA
void EulerTour(int v, int k){
	Mark[v]= true;
	if(H[v] == -1) H[v] = E.size();
	E.push_back(v);
	L[v] = k;
	for(int i = 0 ;i < G[v].size();i++){
		int u = G[v][i].first, w= G[v][i].second;
		if(Mark[u]) continue;
		D[u] = D[v] + w;
		EulerTour(u,k+1);
		E.push_back(v);
	}
}
// ST
void init(int id, int l, int r){
	if(l == r){
		st[id].first = L[E[l]];
		st[id].second = l;
		return;
	}
	int mid = (l+r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	st[id] = min(st[id*2],st[id*2+1]);
}
ii get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return ii(1e5,0);
	if(l >= u && r <= v) return st[id];
	int mid= (l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
long long int getSum(int v, int root){ // lay tong do dai tu i ve root
	return D[v]-D[root];
}
int Query(){
	EulerTour(0,0);
	int N = E.size()-1;
	init(1,1,N);
	int q;
	cin>>q;
	for(int i= 0; i< q;i++){
		int x,y;
		cin>>x>>y;
		int a = H[x], b= H[y];
		if(a > b) swap(a,b);
		int root = E[get(1,1,N,a,b).second];
		cout<<getSum(x,root)+getSum(y,root);
		if(i!=q-1) cout<<" ";
	}
	cout<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while( cin>>n && n!=0){
		reset();
		inputGraph();
		Query();
	}
	return 0;
}