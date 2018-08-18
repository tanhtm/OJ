#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
long n,s;
vector<long> t;
void open(const char* f){
    freopen(f,"r",stdin);
}
void solve(){
    sort(t.begin(),t.end());
    for(long i=n-1;i>=0;i--){
        s-= t[i];
        if(s<=0){
            cout<<n-i<<endl;
            return;
        }
    }
    cout<<"impossible"<<endl;
}
int main(){
    long c;
    cin>>c;
    for(long i=0;i<c;i++){
        t.clear();
        cin>>s>>n;
        long x;
        for(long i=0;i<n;i++){
            cin>>x;
            t.push_back(x);
        }
        cout<<"Scenario #"<<i+1<<":"<<endl;
        solve();
    }
    return 0;
}

