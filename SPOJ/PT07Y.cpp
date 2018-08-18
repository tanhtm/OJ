#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
/*
Cây chỉ có 1 thành phần liên thông
Số cạch bằng số đỉnh trừ 1
*/
long v,e;
vector< vector< long > > DSK;
vector< bool > mark;
void open(const char* f){
    freopen(f,"r",stdin);
}
void dfs(long x){
    mark[x]= true;
    long u;
    for(long i=0 ;i<DSK[x].size();i++){
        u= DSK[x][i];
        if(!mark[u]) dfs(u);
    }
}
bool isTree(){
    if(e!=v-1) return false; // nếu số cạnh khác v-1
    long c=0;
    for(long i=1;i<=v;i++){
        if(!mark[i]){
            dfs(i);
            c++;
        }
    }
    if(c!=1) return false; // nếu đồ thị nhiều hơn 1 thành phần liên thông
    return true;
}
int main(){
    cin>>v>>e;
    long a,b;
    DSK.resize(v+1);
    mark.resize(v+1);
    for(long i=0;i<e;i++){
        cin>>a>>b;
        DSK[a].push_back(b);
        DSK[b].push_back(a);
    }
    cout<<(isTree() ? "YES" : "NO");
    return 0;
}

