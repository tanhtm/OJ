#include <bits/stdc++.h>
using namespace std;
int n,m;
int t,x,y;
static int st[4*100004], dAdd[4*100004], dSub[4*100004];
long long int a[100004];
const int MOD = 1e9 + 7;
int getUV(int u, int v, int i){
  /*2 3 4 5 6 7 8
	i 1 2 3 4 5 6*/
	if(i == 0) return a[i+v-u]%MOD;
	return (a[i+v-u] - a[i-1])%MOD;
}
void down(int id, int l, int r, int mid){
	if(dAdd[id] != -1){
		dAdd[2*id] = dAdd[id];
		st[2*id] += getUV(l,mid,dAdd[2*id]);
		st[2*id]%= MOD;
		dAdd[2*id+1] = mid + 1 - l + dAdd[id];
		st[2*id+1] += getUV(mid+1,r,dAdd[2*id+1]);
		st[2*id+1]%= MOD;
		dAdd[id] = -1;
	}
	if(dSub[id] != -1){
		dSub[2*id] = dSub[id];
		st[2*id] -= getUV(l,mid,dSub[2*id]);
		st[2*id] += MOD;
		st[2*id]%=MOD;
		dSub[2*id+1] = mid + 1 - l + dSub[id];
		st[2*id+1] -= getUV(mid+1,r,dSub[2*id+1]);
		st[2*id+1] += MOD;
		st[2*id+1]%=MOD;
		dSub[id] = -1;
	}
}
void updateAdd(int id, int l, int r, int u, int v, int i){
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		st[id]+= getUV(l,r,l-u+i);
		st[id]%=MOD;
		//cout<<l<<" "<<r<<" "<<st[id]<<endl;
		dAdd[id]= l-u+i;
		return;
	}
	int mid = (l+r)/2;
	//down
	down(id,l,r,mid);
	updateAdd(2*id,l,mid,u,v,i);
	updateAdd(2*id+1,mid+1,r,u,v,i);
	st[id] = st[id*2] + st[id*2+1] + MOD;
	st[id]%= MOD;
}
void updateSub(int id, int l, int r, int u, int v, int i){
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		//cout<<l<<" "<<r<<" "<<i<<" "<<getUV(l,r,l-u+i)<<endl;
		st[id]-= getUV(l,r,l-u+i);
		//cout<<l<<" "<<r<<" "<<st[id]<<endl;
		dSub[id]= l-u+i;
		st[id] += MOD;
		st[id]%=MOD;
		return;
	}
	int mid = (l+r)/2;
	//down
	down(id,l,r,mid);
	updateSub(2*id,l,mid,u,v,i);
	updateSub(2*id+1,mid+1,r,u,v,i);
	st[id] = st[id*2] + st[id*2+1] + MOD;
	st[id]%=MOD;
}
int get(int id, int l, int r,int u, int v){
	if(l > v || r < u) return 0;
	if(l >= u && r <= v){
		//cout<<l<<" "<<r<<" "<<st[id]<<endl;
		return st[id]%MOD;
	}
	int mid = (l+r)/2;
	//down
	down(id,l,r,mid);
	int x1 = get(2*id,l,mid,u,v);
	int x2 = get(2*id+1,mid+1,r,u,v); 	
	return (x1+x2)%MOD;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>m;
	memset(dAdd,-1,sizeof dAdd);
	memset(dSub,-1,sizeof dSub);
	for(long long int i=0;i<=n;i++){
		a[i] = (i+1)*(i+2)*(i+3);
	}
	for(int i=1;i<=n;i++){
		a[i] += a[i-1];
	}
	for(int i=0;i<m;i++){
		cin>>t>>x>>y;
		if(t == 0) cout<<get(1,1,n,x,y)<<endl;
		if(t == 1) updateAdd(1,1,n,x,y,0);
		if(t == 2) updateSub(1,1,n,x,y,0);
	}
	return 0;
}