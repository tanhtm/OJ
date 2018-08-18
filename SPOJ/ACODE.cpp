#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
string s;
long long a[50005];
void open(const char* f){
    freopen("r",f,stdin);
}
long long solve(){
    long long x;
    a[0]= 1;
    a[1]= 1;
    for(long long i=1;i<s.size();i++){
        if(s[i]=='0' && (s[i-1]>'2' || s[i-1]=='0')) return 0;
        if(s[i]=='0'){
            a[i+1] = a[i-1];
            continue;
        }
        if(s[i-1]=='0'){
            a[i+1]= a[i];
            continue;
        }
        x= (s[i-1]-48)*10+ (s[i]-48);
        //cout<<x<<endl;
        if(x<=26) a[i+1]=a[i] +a[i-1];
        else a[i+1]= a[i];
        //cout<<a[i+1]<<endl;
    }
    return a[s.size()];
}
int main(){
    cin>>s;
    while(s!="0"){
        cout<<solve()<<endl;
        cin>>s;
    }
    return 0;
}
