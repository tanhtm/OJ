#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct VLR
{
	int v = 0;
	int l = 0;
	int r = 0;
};
int a[200005],n,q;
VLR v[200005];
int st[800020];
void init(int id, int l, int r){
	if(l == r){
		st[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
	st[id] = min(st[id*2],st[id*2+1]);
}
int get(int id, int l,int r, int u,int v){
	if(l > v || r < u){
		return 10000000;
	}
	if(l >= u && r <= v) return st[id];
	int mid = (l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
} // l r // min O(logn)
int main(){
	cin>>n>>q;
	int pos0 = 0;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		if(a[i] == 0){
			pos0 = i;
			if(i == 1 || i == n) a[i] = 1;
			else a[i] = a[i-1];
		}
	}
	bool check = false;
	for(int i =1;i<=n;i++){
		if(a[i] ==  q) {
			check = true;
			break;
		}
	}
	if(check == false){
		if(pos0 == 0){
			cout<<"NO";
			return 0;
		}else a[pos0] = q;
	}
	init(1,1,n);
	for(int i= 1;i<=n;i++){
		if(v[a[i]].v == 0){
			v[a[i]].l = i;
			v[a[i]].r = i;
			v[a[i]].v = a[i];
		}else{
			v[a[i]].r = i;
		}
	}
	for(int i = 1;i<=n;i++){
		int Min = get(1,1,n,v[a[i]].l,v[a[i]].r);
		//cout<<Min<<endl;
		if(Min < a[i]){
			cout<<"NO";
			return 0;
		}
	}
	/*for(int i= 1;i<=n;i++){
		cout<<a[i]<<" "<<v[a[i]].l<<" "<<v[a[i]].r<<endl;
	}*/
	cout<<"YES"<<endl;
	for(int i =1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}