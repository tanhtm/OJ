#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
int n;
vector< int > m,w;
int solve(){
    sort(m.begin(),m.end());
    sort(w.begin(),w.end());
    int res=0;
    for(int j=0;j<n;j++){
        res+= m[j]*w[j];
    }
    return res;
}
int main(){
    int c;
    cin>>c;
    for(int i=0; i<c;i++){
        m.clear();
        w.clear();
        cin>>n;
        int x;
        for(int j=0;j<n;j++){
            cin>>x;
            m.push_back(x);
        }
        for(int j=0;j<n;j++){
            cin>>x;
            w.push_back(x);
        }
        cout<<solve()<<endl;
    }
    return 0;
}

