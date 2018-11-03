#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Query
{
	int u;
	int v;
	int k;
	int id;
};
bool operator < (Query& a, Query& b){
	return a.k < b. k;
}
typedef pair < int , int > ii;
const int N = 30000+7, Q = 200000+7;
int n,q;
ii a[N]; // luu gia tri va vi tri
Query listQ[Q];
//vector < int > b; // luu gia tri  0 1, b[i] the hien a[i] co lon hon hay nho hon k dang xet
void in(){
	//freopen("dataKQUERY.txt","r",stdin);
	cin>>n;
	for(int i= 0 ;i< n; i++){
		cin>>a[i].first;
		a[i].second = i;
	}
	cin>>q;
	for(int i= 0 ;i< q; i++){
		cin>>listQ[i].u;
		cin>>listQ[i].v;
		cin>>listQ[i].k;
		listQ[i].id = i;
	}
}
/*// ST
vector < int > st; // st[i] luu tong ca thanh phan ma nut i quan ly
void update(int id, int l, int r, int i, int val){
	if(i < l || i > r) return;
	st[id]+= val;
	if(l == r) return;
	int mid = (l + r) / 2;
	update(id*2,l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 0;
	if(l >= u && r <= v)
		return st[id];
	int mid = (l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}*/
//bit
int bit[N];
void update(int v) {
	for(; v <= n; v += v & -v) ++bit[v];	
}	
int get(int v) {
	int res = 0;
	for(; v != 0; v -= v & -v) res += bit[v];
	return res;	
}
int main(){
	in();
	sort(a, a+n);
	sort(listQ, listQ+q);
	//st.resize(4*n);
	int res[Q];
	int j = n-1;
	for(int i = q-1; i>=0; i--){
		Query &query = listQ[i];
		while(a[j].first > query.k){
			update(a[j].second+1);
			j--;
		}
		res[listQ[i].id] = get(query.v) - get(query.u -1);
		if(j == n) break;

	}
	for(int i= 0 ;i<q; i++){
		cout<<res[i]<<endl;
	}
	return 0;
}