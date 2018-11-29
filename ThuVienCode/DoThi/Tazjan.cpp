#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[10005];
int cnt = 0, low[10005], num[10005], isPoint[10005];
int points = 0, bridges = 0;
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
            if (low[v] > num[u])
                 bridges++;
            low[u] = min(low[u], low[v]);
        } else if (v != p)
            low[u] = min(low[u], num[v]);
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {         
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(num, -1, sizeof num);
    memset(low, 0, sizeof low);
    memset(isPoint, 0, sizeof isPoint);
    for(int u = 0; u < n; u++)
        if (num[u] == -1) dfs(u, u);
    return 0;
}