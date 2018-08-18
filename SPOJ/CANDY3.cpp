#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
long long n;
void solve(){
    long long l=0,x;
    for(long long  i=0; i<n;i++){
        cin>>x;
        l+= x%n;
        l= l%n;
    }
    if(l%n == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    long long c;
    cin>>c;
    for(long long i=0 ;i<c; i++){
        cin>>n;
        solve();
    }
    return 0;
}

