#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
int n;
int sum;
vector <int> a;
int solve(){
    if(sum%n!=0) return -1;
    int k= sum/n;
    int res=0;
    for(int i=0; i< n;i++){
        if(a[i]>k) res+= a[i]-k;
    }
    return res;
}
int main(){
    cin>>n;
    int x;
    while(n!=-1){
        a.clear();
        sum= 0;
        for(int i=0; i< n;i++){
            cin>>x;
            sum+= x;
            a.push_back(x);
        }
        cout<<solve()<<endl;
        cin>>n;
    }
    return 0;
}

