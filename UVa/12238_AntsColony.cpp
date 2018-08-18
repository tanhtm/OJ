#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair < int , int > ii;
int n;
vector < vector < ii > > G;
void inputGraph(){
	G.assign(n+1,vector < ii >());
	for(int i =1;i<n;i++){
		int x, w;
		cin>>x>>w;
		G[x].push_back(ii(i,w));
		G[i].push_back(ii(x,w));
	}
}
// LCA
vector < int > E,L,H;
vector < bool > mark;
vector < long long int > D; // D[i] la tong duong di tu dinh i ve dinh 0
void EulerTour(int v, int k){
	mark[v]= true;
	if(H[v] == -1) H[v] = E.size();
	E.push_back(v);
	L.push_back(k);
	for(int i = 0 ;i < G[v].size();i++){
		int u = G[v][i].first, w= G[v][i].second;
		if(mark[u]) continue;
		D[u] = D[v] + w;
		EulerTour(u,k+1);
		E.push_back(v);
		L.push_back(k);
	}
}
void LCA(){
	mark.assign(n+1,false);
	D.assign(n+1,0);
	H.assign(n+1,-1);
	E.assign(1,0);
	L.assign(1,0);
	EulerTour(0,0);
}
// ST
vector < ii > st;
void init(int id, int l, int r){
	if(l == r){
		st[id].first = L[l];
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
	int N = 2*n-1;
	st.assign(4*N+1,ii(1e5,0));
	init(1,1,N);
	int q;
	cin>>q;
	for(int i= 0; i< q;i++){
		int x,y;
		cin>>x>>y;
		int a = H[x], b= H[y];
		//cout<<a<<" "<<b<<endl;
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
		inputGraph();
		LCA();
		Query();
	}
	return 0;
}