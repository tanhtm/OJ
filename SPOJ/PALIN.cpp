#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
string s;
void open(const char* f){
    freopen(f,"r",stdin);
}
int cmp(string &a, string &b){
    if(a.size()> b.size())return 1;
    if(b.size()> a.size())return -1;
    for(int i=0; i<a.size();i++){
        if(a[i]> b[i]) return 1;
        if(a[i]< b[i]) return -1;
    }
    return 0;
}
void toPal(string &a){
    int sz= a.size();
    for(int i=0;i<sz/2;i++){
        a[sz-i-1] = a[i];
    }
}
void addOne(string &a){
    int mid= a.size()/2;
    if(s.size()%2 ==0) mid--;
    for(int i=mid; i>=0;i--){
        a[i]++;
        if(a[i]<='9') break;
        a[i]-= 10;
        if(i==0){
            a= "1"+ a;
            break;
        }
    }
}
string solve(){
    string r= s;
    toPal(r);
    if(cmp(r,s) == 1) return r;
    addOne(r);
    toPal(r);
    return r;
}
int main(){
    //open("PALIN.txt");
    int c;
    cin>>c;
    for(int i=0; i<c;i++){
        cin>>s;
        cout<<solve()<<endl;
    }
    return 0;
}
