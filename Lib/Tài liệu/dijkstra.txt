#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int oo = 1000111000;
typedef pair<int, int> ii;

vector <ii> a[2309];
int n, m;

int d[2309];

void dijkstra(){
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int i, u, v, du, uv;

    for (i=1; i<=n; i++) d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (i=0; v=a[u][i].second; i++)
        {
            uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }

}

main(){
    int p, q, i, m, w;
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    for (i=1; i<=n; i++) a[i].push_back(ii(0,0));
    dijkstra();
    for (i=1; i<=n; i++) printf("d( 1 -> %d ) = %d\n", i, d[i]);
}
