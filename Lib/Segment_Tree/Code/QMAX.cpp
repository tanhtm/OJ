#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector < int > it; // it[i] gia tri lon nhat nut i quan ly
int n,m,p;
vector < int > t; // t[i] tat ca cac phan tu trong nut i quan ly deu dc tan them t[i]
void update(int id, int l, int r, int u, int v , int val){
	if(r < u || l > v) return;
	if(l >= u && r <= v){
		it[id] += val;
		t[id] += val;
		return;
	}

	int mid = (l+r)/2;

	t[id*2] += t[id];
	it[id*2] += t[id];
	t[id*2+1] += t[id];
	it[id*2+1] += t[id];
	t[id] = 0;

	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	it[id] = max(it[id*2], it[id*2+1]);
}
int get(int id, int l, int r, int u, int v){
	if(r < u || l > v) return -1;
	if(l >= u && r <= v){
		return it[id];
	}

	int mid = (l+r)/2;

	t[id*2] += t[id];
	it[id*2] += t[id];
	t[id*2+1] += t[id];
	it[id*2+1] += t[id];
	t[id] = 0;

	return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}
int main(){
	cin>>n>>m;
	it.resize(4*n);
	t.resize(4*n);
	for(int i= 0 ;i< m; i++){
		int u,v,k;
		cin>>u>>v>>k;
		update(1,1,n,u,v,k);
	}
	cin>>p;
	for(int i= 0 ;i< p; i++){
		int u,v;
		cin>>u>>v;
		cout<<get(1,1,n,u,v)<<endl;
	}
	return 0;
}