#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
void open(const char* f){
    freopen("r",f,stdin);
}
long long int getType(long long int x, long long int y){
    if(x==y) return 1;
    if(x-y ==2) return 2;
    return 0;
}
void solve(long long int x,long long int y){
    long long int t= getType(x,y);
    if(t==0){
        cout<<"No Number"<<endl;
        return;
    }
    long long int res=0;
    long long int i = x/2;
    if(t==2){
        res= 2;
        res+= (i-1)*4;
        if(x%2!=0) res++;
    }
    if(t==1){
        res= i*4;
        if(x%2!=0) res++;
    }
    cout<<res<<endl;
}
int main(){
    long long int c,x,y;
    cin>>c;
    for(long long int i=0;i<c;i++){
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}

