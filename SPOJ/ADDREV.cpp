#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long Reverse(long long n){
    long long result =0;
    while(n!= 0){
        result*=10;
        result+= n%10;
        n/=10;
    }
    return result;
}
int main(){
    long long c;
    cin>>c;
    long long x,y,sum;
    for(long long i=0; i<c;i++){
        cin>>x>>y;
        x= Reverse(x);
        y= Reverse(y);
        sum = x+ y;
        sum= Reverse(sum);
        cout<<sum<<endl;
    }
    return 0;
}
