#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;

typedef pair < int , int > Query;
int n,q;
vector < int > a; 
vector < Query > aQuery;
bool in(){
	cin>>n;
	if(!n) return false;
	cin>>q;
	a.resize(n+1);
	aQuery.clear();
	for(int i = 1;i<= n;i++)
		cin>>a[i];
	for(int i = 0;i< q;i++){
		int x, y;
		cin>>x>>y;
		aQuery.push_back(Query(x,y));
	}
	return true;
}

vector < int > st;
void update(int id, int l, int r, int i, int val){
	if(i < l || i > r) return;
	st[id] = val;
	if(l == r) return;
	int mid = (l +r) /2;
	update(id*2, l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);
	st[id] = max(st[id*2],st[id*2+1]);
}
int get(int id, int l, int r, int u, int v){
	if(u==v) return 1;
	if( l > v  || r < u) return 0;
	if( l >= u && r <= v) return st[id];
	int mid = (l + r) /2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void solve(){
	st.assign(4*n,0);
	map < int , int >  Map; // Map[i] luu tan so cua a[i]
	map < int , int > last; // last[i] vi tri cuoi cung xuat hien so a[i]
	for(int i= 1; i<= n; i++){
		Map[a[i]]++;
		last[a[i]]= i;
		//cout<<Map[a[i]]<<" ";
		update(1,1,n,i,Map[a[i]]);
	}
	//cout<<endl;
	// for(int i= 1; i<= n; i++){
	// 	cout<<last[a[i]]<<" ";
	// }
	// cout<<endl;
	int res;
	for(int i= 0; i< q; i++){
		int u = aQuery[i].first, v= aQuery[i].second;
		int l = last[a[u]]; 
		//cout<<l<<endl;
		if(l >= v) res = v-u+1;
		else res = max(l-u+1,get(1,1,n,l+1,v));
		cout<<res<<endl;
		//cout<<get(1,1,n,u,v)<<endl;
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	while(in()){
		solve();
	}
	return 0;
}