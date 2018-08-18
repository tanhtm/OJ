#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
long long n,m;
bool isPrime(long long x){
    if(x<2) return false;
    if(x == 2 || x == 3 || x== 5 || x==7 || x==11) return true;
    if(x%2 == 0 || x%3==0 || x% 5==0 || x%7==0 || x%11==0) return false;

    for(long long i=13;i<=sqrt(x);i++)
        if(x%i == 0) return false;
    return true;
}
void getPrime(long long m,long long n){
    for(long long i=m;i<=n;i++){
        if(isPrime(i)) cout<<i<<endl;
    }
    cout<<endl;
}
int main(){
    long long c;
    cin>>c;
    for(long long i=0; i<c;i++){
        cin>>m>>n;
        getPrime(m,n);
    }
    return 0;
}

