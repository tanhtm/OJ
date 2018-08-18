#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;
int n;
vector <long > r(10005,1);
int solve(){
    if(n==1) return 1;
    for(int i=2;i<= n;i++){
        for(int j= 2; j<=sqrt(i);j++){
            if(i%j==0) r[i]++;
        }
        r[i]+= r[i-1];
        //cout<<r[i]<<endl;
    }
    return r[n];
}
int main(){
    cin>>n;
    cout<<solve();
    return 0;
}

