#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v,w;
	Edge(){
		v= w= 0;
	}
	Edge(int V, int W){
		v = V;
		w = W;
	}
};
bool operator < (Edge e1, Edge e2){
	return e1.w > e1.w;
}
int n,m;
vector < Edge > dsk[505];

vector < int > Time; // Time[i] la thoi gian ngan nhat di tu 1 -> i

void getTime(){
	//Dijktra
	priority_queue < Edge > Q;	
	vector < bool > visited(n+1);
	Time.resize(n+1,1e9);
	Time[1] = 0;
	visited[1] = 1;
	Q.push(Edge(1,0));
	while(!Q.empty()){
		Edge e = Q.top();Q.pop();
		int u = e.v;
		int t = e.w;
		if(Time[u] != t) continue;
		for(int i=0;i<dsk[u].size();i++){
			e = dsk[u][i];
			int v = e.v;
			if(Time[v] > Time[u] + e.w){
				Time[v] = Time[u] + e.w;
				Q.push(Edge(v,Time[u]+e.w));
			}
		} 
	}

	/*for(int i=1;i<=n;i++) cout<<Time[i]<<" ";
	cout<<endl;*/
}
void run(){
	double r = 0;
	int x = 1,y=-1;
	for( int i=1; i<=n; ++i ){
		if(Time[i] > r){
			r = Time[i];
			x = i;
		}
	}
	for( int u=1; u<=n; ++u ){
		for( int j=0; j<dsk[u].size(); ++j ){
			int v = dsk[u][j].v;
			int w = dsk[u][j].w;
			int a = Time[u];
			int b = Time[v];
			if( a < b ) swap(a, b);
			double c = (double)a + (double)(w - (a - b)) / 2.0;
			if( c > r ){
				x = min( u, v );
				y = max( u, v );
				r = c;
			}
		}
	}
	printf("The last domino falls after %.1lf seconds,",r);
	if(y == -1)
		printf(" at key domino %d.\n",x);
	else printf(" between key dominoes %d and %d.\n",x,y);
}
void reset(){
	Time.clear();
	for(int i=1;i<=n;i++) dsk[i].clear();
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int t = 1;
	while(cin>>n>>m && n!=0){
		reset();
		printf("System #%d\n",t++);
		for(int i=0;i<m;i++){
			int a,b,l;
			cin>>a>>b>>l;
			dsk[a].push_back(Edge(b,l));
			dsk[b].push_back(Edge(a,l));
		}
		getTime();
		run();
		cout<<endl;
	}
	return 0;
}