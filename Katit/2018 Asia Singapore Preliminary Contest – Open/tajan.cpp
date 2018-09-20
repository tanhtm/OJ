#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n, m;
vector<int> a[10005];
int cnt = 0, low[10005], num[10005], isPoint[10005];
int points = 0, bridges = 0;
vector < ii > Edges;
map < int , bool > M[10005];
void dfs(int u, int p) {
    int children = 0;
    num[u] = low[u] = cnt++;
    for(int v : a[u]) {
        if (num[v] == -1) {
            children++;
            dfs(v, u);

            // u "may" be articulation point
            if (low[v] >= num[u])
                isPoint[u] = (u == p) ? (children > 1) : 1;

            // u-v is bridges
            if (low[v] > num[u]){
                 bridges++;
                 //cout<<u<<" "<<v<<endl;
                 M[u][v] = true;
                 M[v][u] = true;

            }
            low[u] = min(low[u], low[v]);
        } else if (v != p)
            low[u] = min(low[u], num[v]);
    }
}
bool mark[10005];
int dfs1(int x){
    mark[x] = true;
    int r = 1;
    for(int i=0;i<a[x].size();i++){
        int v = a[x][i];
        if(mark[v]) continue;
        r+= dfs1(v);
    }
    return r;
}
int main() {

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {         
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        if(u > v) swap(u,v);
        Edges.push_back(ii(u,v));
    }
    memset(num, -1, sizeof num);
    memset(low, 0, sizeof low);
    memset(isPoint, 0, sizeof isPoint);
    for(int u = 0; u < n; u++)
        if (num[u] == -1) dfs(u, u);
    vector < ii > newEdge;
    for(int i=0;i<m;i++){
        ii e = Edges[i];
        if(M[e.first][e.second]) continue;
        newEdge.push_back(e);
    }
    for(int i=0;i<n;i++) a[i].clear();
    for(int i=0;i<newEdge.size();i++){
        int u,v;
        u = newEdge[i].first;
        v = newEdge[i].second;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    memset(mark,0,sizeof mark);
    cout<<dfs1(0);
    return 0;
}