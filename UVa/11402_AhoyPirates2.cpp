#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N,Q;
string land;
vector < int > ST,Query;
// Query[i]: nho de cac not do i quan ly de lam
void down (int id, int l, int r){
	if(l==r) return;
	int stt = Query[id];
	if(stt == -2) return;
	int mid = (l + r) /2;
	if(stt == 1){
		ST[id*2] = mid - l + 1;
		ST[id*2+1] = r - (mid+1) + 1;
		Query[id*2] = Query[id*2+1] = 1;
	}
	if(stt == 0)
		ST[id*2] = ST[id*2+1] = Query[id*2] = Query[id*2+1] = 0;
	if(stt == -1){
		ST[id*2] = (mid - l + 1) - ST[id*2];
		ST[id*2+1] = r - (mid+1) + 1 - ST[id*2+1];
		//Query[id*2] = Query[id*2+1] = -1;
		if(Query[id*2]== 0) Query[id*2] = 1;
		if(Query[id*2]== 1) Query[id*2] = 0;
		if(Query[id*2]== -2) Query[id*2] = -1;
		if(Query[id*2]== -1) Query[id*2] = -2;
		if(Query[id*2+1]== 0) Query[id*2+1] = 1;
		if(Query[id*2+1]== 1) Query[id*2+1] = 0;
		if(Query[id*2+1]== -2) Query[id*2+1] = -1;
		if(Query[id*2+1]== -1) Query[id*2+1] = -2;
	}
	Query[id] = -2;
}
void init(int id, int l, int r){
	if(l == r){ 
		ST[id] = land[l] - '0';
		return;
	}
	int mid = (l+r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	ST[id] = ST[id*2] + ST[id*2+1];
	//cout<<ST[id]<<" "<<l<<" "<<r<<endl;
}
void update(int id, int l, int r, int u, int v, int stt){
	down(id,l,r);
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		Query[id] = stt;
		if(stt == 1) ST[id] = r - l + 1;
		if(stt == 0) ST[id] = 0;
		if(stt == -1) ST[id] = (r - l + 1) - ST[id];
		//cout<<ST[id]<<" "<<l<<" "<<r<<endl;
		return;
	}
	int mid = (l + r)/2;
	update(id*2,l,mid,u,v,stt);
	update(id*2+1,mid+1,r,u,v,stt);
	ST[id] = ST[id*2] + ST[id*2+1];
	//cout<<ST[id]<<" "<<l<<" "<<r<<endl;
}
int get(int id, int l , int r, int u, int v){
	down(id,l,r);
	if(l > v || r < u) return 0;
	if(l >= u && r <= v){
		return ST[id];
	}
	int mid = (l + r)/2;
	int x =get(id*2,l,mid,u,v);
	int y =get(id*2+1,mid+1,r,u,v);
	return x+y;
}
void run(){
	int M;
	cin>>M;
	land.clear();
	while(M--){
		int T;
		string s;
		cin>>T>>s;
		while(T--)
			for(int i = 0; i<s.size();i++)
				land += s[i];
	}
	//cout<<land<<endl;
	N = land.size();
	//cout<<N<<endl;
	ST.assign(4*N,0);
	Query.assign(4*N,-2);
	/*int l=0,r;
	for(int i= 0; i<N;i++){
		if(land[i] == '0') continue;
		l = i; 
		while(i != N && land[i]=='1') i++;
		r = i - 1;
		//update(1,1,N,l+1,r+1,1);
		//cout<<l<<" "<<r<<endl;
	}*/
	init(1,1,N);
	cin>>Q;
	char c;
	int a,b,d=0;
	for(int i=0; i< Q;i++){
		cin>>c>>a>>b;
		a++;b++;
		if(c == 'F') update(1,1,N,a,b,1);
		if(c == 'E') update(1,1,N,a,b,0);
		if(c == 'I') update(1,1,N,a,b,-1);
		if(c == 'S'){ 
			d++;
			int x = get(1,1,N,a,b);
			cout<<'Q'<<d<<": "<<x<<endl;
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
}