#include <bits/stdc++.h>
using namespace std;
// Bipartite Graph Check
int n,l;
vector < int > dsk[200];
int bipar[200];
// bipar[u] == -1 : chua tham u;
// bipar[u] == 0 : u o phan thu nhat
// bipar[u] == 1 : u o phan thu 2
void reset(){
	for(int i=0;i<n;i++) {
		dsk[i].clear();
		bipar[i] = -1;
	}
}
bool dfs(int u, bool p){ // u: dinh den tham, p = 1 : u thuoc phan 1 , p = 2: u thuoc 2
	bipar[u] = p;
	bool flat = 1;
	for(int i=0;i<dsk[u].size();i++){
		int v = dsk[u][i];
		if(bipar[v] == -1)
			flat = dfs(v,!p);
		else if(bipar[u] == bipar[v]) flat = 0; // kiem tra 2 ben
		if(!flat) break;
	}
	return flat;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>n && n!=0){
		reset();
		cin>>l;
		int x,y;
		for(int i=0;i<l;i++){
			cin>>x>>y;
			dsk[x].push_back(y);
			dsk[y].push_back(x);
		}
		if(dfs(0,0)) cout<<"BICOLORABLE.";
		else cout<<"NOT BICOLORABLE.";
		cout<<endl;
	}
	return 0;
}