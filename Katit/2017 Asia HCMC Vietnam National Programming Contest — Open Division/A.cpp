#include <bits/stdc++.h>
using namespace std;
int n,m;
int t,x,y;
static int st[4*100004], lazy[4*100004][4];
const int MOD = 1e9 + 7;
int a[10004][4];
/*  i = [u...v]
	(i-u+1)(i-u+2)(i-u+3)
	= i^3*1 
	+ i^2*(-3*u^2+6)
	+ i^1*(3*u^2-12*u+11)
	+ i^0*(-u^3+6*u^2-11*u+6)

	st[l..r] += (l^3 ... + r^3)*1
			 + (l^2 ... + r^2)*(-3*u^2+6)
			 + (l^1 ... + r^1)*(3*u^2-12*u+11)
			 + (l^0 ... + r^0)*(-u^3+6*u^2-11*u+6)
*/
int getC(int deg,int u){
	if(deg == 0) return -1*(u*u*u)+6*u*u-11*u+6;
	if(deg == 1) return 3*u*u-12*u+11;
	if(deg == 2) return -3*u*u+6;
	return 1;
}
int getL(int l, int r, int i){
	if(l == 0) return a[r][i];
	return (a[r][i] - a[l-1][i] + MOD)%MOD;
}
void down(int id, int l, int r, int mid){
	for(int i=0;i<4;i++){
		if(lazy[id][i] == 0) continue;
		lazy[id*2][i]+= lazy[id][i];
		lazy[id*2+1][i]+= lazy[id][i];
		st[id*2]+= getL(l,mid,i)*lazy[id][i] + MOD;
		st[id*2]%= MOD;
		st[id*2+1]+= getL(mid+1,r,i)*lazy[id][i] + MOD;
		st[id*2+1]%= MOD;
		lazy[id][i]= 0;
	}
}
int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 0;
	if(l >= u && r <= v)
		return st[id];
	int mid = (l+r)/2;
	down(id,l,r,mid);
	int res = get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
	st[id] = st[id*2] + st[id*2+1];
	st[id] %= MOD;
	return res%MOD;
}
void update(int id,int l, int r, int u, int v, int sign){
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		for(int i=0;i<4;i++){
			int c = getC(i,u);
			int L = getL(l-u,r-u,i);
			st[id]+= c*L*sign;
			st[id] %= MOD;
			lazy[id][i]+= c*sign; // khoi doi voi u
		}
		return;
	}
	int mid = (l+r)/2;
	down(id,l,r,mid);
	update(id*2,l,mid,u,v,sign);
	update(id*2+1,mid+1,r,u,v,sign);
	st[id] = st[id*2]+st[id*2+1];
	st[id] %= MOD;
}
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j= 0;j<4;j++) a[i][j] = pow(i,j);
	}/*
	for(int i=1;i<=n;i++){
		for(int j= 0;j<4;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i= 0;i<4;i++){
		for(int j=2;j<=n;j++){
			a[j][i]+= a[j-1][i];
			a[j][i]%=MOD;
		}
	}
	for(int i=0;i<m;i++){
		cin>>t>>x>>y;
		if(t == 0) cout<<get(1,1,n,x,y)<<endl;
		if(t == 1) update(1,1,n,x,y,1);
		if(t == 2) update(1,1,n,x,y,-1);
		for(int i =1;i<=n;i++){
			cout<<get(1,1,n,i,i)<<" ";
		}
		cout<<endl;
	}
	return 0;
}