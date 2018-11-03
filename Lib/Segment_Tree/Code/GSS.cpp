#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int Sum;
	int MaxSum;
	node(){
		Sum = 0;
		MaxSum = -1e9;
	}
	node(int s, int m){
		Sum = s;
		MaxSum = m;
	}
};
vector < node > st;
void update(int id, int l, int r, int i , int val){
	if(i< l || i > r) return;
	st[id].Sum += val;
	st[id].MaxSum = max(st[id].MaxSum,st[id].Sum);
	if(l == r){
		st[id].MaxSum = val;
		return;
	}
	int mid = (l+r)/2;
	update(id*2,l,mid,i,val);
	update(id*2+1,mid+1,r,i,val);
	st[id].MaxSum = max(st[id].MaxSum,st[id*2].MaxSum);
	st[id].MaxSum = max(st[id].MaxSum,st[id*2+1].MaxSum);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return -1e9;
	if(l >= u && r <= v) return st[id].MaxSum;
	int mid = (l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
	int n,m;
	cin>>n;
	st.resize(n*4);
	for(int i=1;i <= n;i++){
		int x;
		cin>>x;
		update(1,1,n,i,x);
	}
	cin>>m;
	for(int i=1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		cout<<get(1,1,n,u,v)<<endl;
	}
	return 0;
}