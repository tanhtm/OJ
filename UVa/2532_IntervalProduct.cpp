#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector < int > a;
vector < int > st;
void init(int id,int l, int r){
	if(l==r){ 
		st[id] = a[l];
		return;
	}
	int mid = (l + r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	st[id] = st[id*2]*st[id*2+1];
}
void update(int id, int l, int r, int i, int v){
	if(l > i || r < i) return;
	if(l == r){
		st[id]= v;
		return;
	}
	int mid = (l + r)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);
	st[id] = st[id*2]*st[id*2+1];
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 1;
	if(l>= u && r <= v)
		return st[id];
	int mid = (l + r)/2;
	return get(id*2,l,mid,u,v) * get(id*2+1,mid+1,r,u,v);
}
void run(){
	a.resize(n+1);
	for(int i = 1; i <= n;i++){
		cin>>a[i];
		if(a[i] > 0) a[i] = 1;
		if(a[i] < 0) a[i] = -1;
		if(a[i] == 0) a[i] = 0;
	}
	st.assign(4*n,1);
	init(1,1,n);
	char c;
	int x,y;
	for(int i = 1; i <= k;i++){
		cin>>c>>x>>y;
		if(c == 'C'){
			if(y > 0) y = 1;
			if(y < 0) y = -1;
			if(y == 0) y = 0;
			update(1,1,n,x,y);
		}else{
			int g = get(1,1,n,x,y);
			if(g > 0) cout<<'+';
			if(g < 0) cout<<'-';
			if(g == 0) cout<<'0';
		} 
	}
	cout<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	while(cin>>n>>k){
		run();
	}
	return 0;
}