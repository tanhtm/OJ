#include <bits/stdc++.h>
using namespace std;
vector < int > v[1000005];
int b[1000005];
int n,k;
vector < bool > mark;
vector < vector < int > > tree;
vector < int > V;
void dfs(int x){
	mark[x] = true;
	V.push_back(x);
	for(int i=0;i<v[x].size();i++){
		int u = v[x][i];
		if(mark[u]) continue;
		dfs(u);
	}
}
bool find(vector < int > &a, int l, int r, int v){
	if(a[l] == v) return true;
	if(l == r) return false;
	int mid = (l + r)/2;
	if(a[mid] == v) return true;
	if(v > a[mid]) return find(a,mid+1,r,v);
	return find(a,l,mid,v);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n;
	memset(b,0,sizeof b);
	cin>>k;
	int x,y;
	for(int i= 0;i<k;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(n%2==1) b[n/2 + 1] = true;
	mark.assign(n+1,false);
	for(int i=1;i<=n;i++){
		if(mark[i]) continue;
		dfs(i);
		tree.push_back(V);
		V.clear();
	}
	//cout<<endl;
	if(!V.empty()) tree.push_back(V);
	for(int i=0;i<tree.size();i++){
		sort(tree[i].begin(),tree[i].end());
		for(int j=0;j<tree[i].size();j++){
			x= tree[i][j];
			//cout<<x<<" ";
			if(x > n/2) continue;
			if(binary_search(tree[i].begin(),tree[i].end(),n-x+1))
				b[x] = true;
			else b[x] = false;
		}
		//cout<<endl;
	}
	for(int i=1;i<=n/2;i++){
		//cout<<b[i]<<" ";
		if(!b[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}