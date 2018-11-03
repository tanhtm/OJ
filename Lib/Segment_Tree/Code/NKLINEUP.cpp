#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,q;
struct node
{
	int Min;
	int Max;
	node(){
		Max = 0;
		Min = 1e9;
	}
	node(int m , int n){
		Max = m ;
		Min = n;
	}
};
vector < node > it;
void update(int id, int l , int r , int i, int val ){
	if(i > r || i < l) return;
	it[id].Max = max(it[id].Max, val);
	it[id].Min = min(it[id].Min, val);
	if( l == r) return;
	int mid = (l+r)/2;
	update(id*2, l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);
}
node get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return node();
	if(l >= u && r <= v){
		return it[id];
	}
	int mid = (l+r)/2;
	node n1 = get(id*2,l,mid,u,v);
	node n2 = get(id*2+1,mid+1,r,u,v);
	return node(max(n1.Max, n2.Max), min(n1.Min, n2.Min));

}
int main(){
	cin>>n>>q;
	it.resize(4*n);
	for(int i=0 ;i<n;i++){
		int x;
		cin>>x;
		update(1,1,n,i+1,x);
	}
	for(int i=0 ;i<q;i++){
		int u,v;
		cin>>u>>v;
		node Node;
		Node = get(1,1,n,u,v);
		cout<<Node.Max - Node.Min<<endl;
	}
	return 0;
}