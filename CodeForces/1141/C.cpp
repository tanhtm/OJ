#include <bits/stdc++.h> 
using namespace std;
const int N = 2*1e5+5;
int n;
int p[N], q[N];
bool tonTai[N];
void input(){
	cin>>n;
	for(int i=1;i<n;i++) cin>>q[i];
	memset(tonTai,0,sizeof(tonTai));
}
int run(int P1){
	tonTai[P1] = 1;
	p[1] = P1;
	for(int i=1;i<n;i++){
		p[i+1] = p[i] + q[i];
		if(p[i+1] < 1) return -1;
		if(p[i+1] > n) return 1;
		if(tonTai[p[i+1]]){
			for(int j=p[i+1];j<=n;j++){
				if(!tonTai[j]) return -1;
			}
			return 1;
		} 
		tonTai[p[i+1]] = 1;
	}
	return 2;
}
int findP1(int l, int r){
	memset(tonTai,0,sizeof(tonTai));
	if(l > r) return -1;
	int mid = (l+r)/2;
	int x = run(mid);
	//reset
	if(x == -1) return findP1(mid+1,r);
	if(x == 1 ) return findP1(l,mid-1);
	if(x == 2) return mid;
	return -1;
}
int main(){
	input();
	int xp = findP1(1,n);
	cout<<xp;
	if(xp == -1){
		return 0;
	}
	p[1] = xp;
	for(int i=1;i<n;i++){
		p[i+1] = p[i] + q[i];
		cout<<" "<<p[i+1];
	}
	return 0;
}