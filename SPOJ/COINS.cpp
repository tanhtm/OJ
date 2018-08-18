#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
long long n;
map< int , long long > d;
long long solve(long long n){
    if(n ==0 ) return 0;
    if(d[n] != 0) return d[n];
    long long r= solve(n/2) + solve(n/3) + solve(n/4);
    if(r> n) d[n] = r;
    else d[n] = n;
    return d[n];
}
int main(){
    while(cin>>n){
        cout<<solve(n)<<endl;
	}
    return 0;
}

