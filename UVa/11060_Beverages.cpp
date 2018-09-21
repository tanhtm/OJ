#include <bits/stdc++.h>
using namespace std;
int n,m;
vector < string > beverages;
map < string , int > mapId;
vector < int > dsk[105];
int indeg[105];
void reset(){
	mapId.clear();
	beverages.resize(1);
	memset(indeg,0,sizeof indeg);
	for(int i=1;i<=n;i++)
		dsk[i].clear();
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int c = 1;
	while(cin>>n){
		string x,y;
		reset();
		for(int i=1;i<=n;i++){
			cin>>x;
			mapId[x] = i;
			beverages.push_back(x);
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			int ix = mapId[x], iy= mapId[y];
			dsk[ix].push_back(iy);
			indeg[iy]++;
		}
		priority_queue < int , vector < int > , greater < int > > pQ;
		for(int i=1;i<=n;i++) if(indeg[i] == 0) pQ.push(i);
		printf("Case #%d: Dilbert should drink beverages in this order:",c++);
		// BFS
		while(!pQ.empty()){
			int u = pQ.top(); pQ.pop();
			for(int i=0;i<dsk[u].size();i++){
				int v = dsk[u][i];
				indeg[v]--; //loại bỏ cung U từ đồ thị
				if(indeg[v] == 0) pQ.push(v);
			}
			printf(" %s",beverages[u].c_str());
		}
		printf(".\n\n");
	}
	return 0;
}