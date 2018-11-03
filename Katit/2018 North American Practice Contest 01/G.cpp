#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int memo[205][30005];
int dp(int i, int calo){
    if(memo[i][calo] != -1) return memo[i][calo];
    if(i > n) return 0;
    if(calo == 0){
        return memo[i][calo] = dp(i + 2, m);
    }
    // an
    int x = min(a[i], calo) + dp(i + 1, (calo * 2) / 3);
    // ko an
    int y = dp(i+1, calo);
    int z = dp(i+2, m);
    int p = min(a[i], calo) + dp(i+2, calo);
    x = max(x, y);
    x = max(x, z);
    x = max(x, p);
    //cout<<i<<" "<<calo<<" "<<x<<endl;
    return memo[i][calo] = x;
}
int main(){
    //freopen("data.txt","r",stdin);
    //freopen("dataOut.txt","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    memset(memo, -1, sizeof memo);
    cout<<dp(1, m)<<endl;
    return 0;
}