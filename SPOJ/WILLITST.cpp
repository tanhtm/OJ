#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
long long int n;
void open(const char* f){
    freopen(f,"r",stdin);
}
void solve(){
    while(n!=1){
        if(n%2 != 0){
            cout<<"NIE";
            return;
        }
        n= n/2;
    }
    cout<<"TAK";
}
int main(){
    cin>>n;
    //cout<<n<<endl;
    solve();
    return 0;
}

