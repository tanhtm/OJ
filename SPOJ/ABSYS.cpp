#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
string s1,s2,s3;
int n1,n2,n3;
void open(const char* f){
    freopen(f,"r",stdin);
}
bool isNumber(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='m') return false;
    }
    return true;
}
int toInt(string s){
    stringstream ss;
    ss<<s;
    int n;
    ss>>n;
    return n;
}
void solve(){
    if(!isNumber(s1)){
        n2= toInt(s2);
        n3= toInt(s3);
        n1= n3-n2;
    }
    if(!isNumber(s2)){
        n1= toInt(s1);
        n3= toInt(s3);
        n2= n3-n1;
    }
    if(!isNumber(s3)){
        n1= toInt(s1);
        n2= toInt(s2);
        n3= n1+n2;
    }
}
int main(){
    int c;
    cin>>c;
    char cc;
    for(int i=0;i<c;i++){
        cin>>s1>>cc>>s2>>cc>>s3;
        solve();
        cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
    }
    return 0;
}
