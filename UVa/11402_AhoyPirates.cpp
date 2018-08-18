#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Buccaneer Pirates : 1
Barbary Pirates   : 0
*/
const int ONE = 1, ZERO = 0, INV = 2, NOT = 3; // INV : dao nguoc, NOT : Ko lam gi ca
int N,M,T,Q,a,b,d;
char c;
string pirates,S;
vector < int > st,t;
vector < int > timeT,timeInv;
vector < bool > inv; // inv[i] : dam bao la da dao tat ca cac thanh phan do nut i quan li
void reset(){
	st.assign(4*N,0);
	t.assign(4*N,NOT);
	inv.assign(4*N,false);
	timeInv.assign(4*N,0);
	timeT.assign(4*N,0);
}
void init(int id, int l ,int r){
	if(l == r){st[id] = pirates[l-1] - '0';return;}
	int mid = (l+r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1]; 
}
void downT(int id, int l, int r){
	if(t[id] != NOT){  // day xuong cho cac con
		int mid = (l+r)/2; 
		if(t[id] == 1){ 
			st[id*2] = mid - l + 1;
			st[id*2+1] = r - (mid+1) + 1;
		}
		else st[id*2] = st[id*2+1] = 0;
		t[id*2] = t[id*2+1] = t[id];
		timeT[id*2] = timeT[id*2+1] = timeT[id];
		t[id] = NOT;
		timeT[id] = 0;
	}
}
void downInv(int id, int l, int r){
	if(inv[id]){
		int mid = (l+r)/2;
		st[id*2] = (mid-l+1)-st[id*2];
		st[id*2+1] = (r-mid)-st[id*2+1];
		timeInv[id*2] = timeInv[id*2+1] = timeInv[id];
		inv[id] = false;
		timeInv[id] = 0;
	}
}
void down(int id, int l, int r){
	if(timeT[id] < timeInv[id]){
		downT(id,l,r);
		downInv(id,l,r);
	}else{
		downInv(id,l,r);
		downT(id,l,r);
	}
}
void update(int id, int l, int r, int u, int v, int x, int tg){ // x : 0 1
	if(l > v || r< u) return;
	if(l >= u && r<= v){
		if(x == 1) st[id] = r - l + 1;
		else st[id] = 0; // x = 0
		t[id] = x;
		timeT[id] = tg;
		return;
	}
	int mid = (l+r)/2;
	down(id,l,r);
	update(id*2,l,mid,u,v,x,tg);
	update(id*2+1,mid+1,r,u,v,x,tg);
	st[id] = st[id*2] + st[id*2+1];
}
void inverse(int id, int l, int r, int u, int v, int tg){
	if(l > v || r< u) return;
	if(l >= u && r<= v){
		st[id] = (r-l+1) - st[id];
		inv[id] = true;
		timeInv[id] = tg;
		return;
	}
	int mid = (l+r)/2;
	down(id,l,r);
	inverse(id*2,l,mid,u,v,tg);
	inverse(id*2+1,mid+1,r,u,v,tg);
	st[id] = st[id*2] + st[id*2+1];
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return st[id];
	int mid= (l+r)/2;
	down(id,l,r);
	return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}
void run(){
	cin>>M;
	pirates.clear();
	while(M--){
		cin>>T>>S;
		while(T--)
			for(int i= 0;i<S.size();i++) pirates+=S[i];
	}
	N = pirates.size();
	reset();
	init(1,1,N);
	cin>>Q;
	d = 1;
	for(int i=0;i<Q;i++){
		cin>>c>>a>>b;
		a++;b++;
		switch (c){
			case 'F': update(1,1,N,a,b,1,i+1);
				break;
			case 'E': update(1,1,N,a,b,0,i+1);
				break;
			case 'I': inverse(1,1,N,a,b,i+1);
				break;
			case 'S': cout<<"Q"<<d++<<": "<<get(1,1,N,a,b)<<endl;
				break;
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	int c;
	cin>>c;
	int i = 1;
	while(i <= c){
		cout<<"Case "<<i<<":"<<endl;
		run();
		i++;
	}
	return 0;
}