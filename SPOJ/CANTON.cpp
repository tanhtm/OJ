#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
/*
    x
    1    2   3   4   5   6
y
1   1    2

2   3    5

3   4

4   10

5   11

-Tạo mảng v chứa các giá trị tại cội 1
-Tìm kiếm nhị phân
*/
vector<long> v;
long x,y;
void open(const char* f){
    freopen(f,"r",stdin);
}
void pre(){ // ta
    v.push_back(0);
    v.push_back(1);
    long t =1,i=2;
    while(t<= 10000000){
        t= t+ i + (i -1) -1;
        v.push_back(t);
        t++;
        v.push_back(t);
        i+=2;
    }
    /*for(long j=1; j<v.size();j++){
        cout<<v[j]<<" ";
    }*/

}
long binarySearch(long i,long j, long val){
    if(i==j) return j;
    long mid= (i+ j)/2;
    if(v[mid] >= val) return binarySearch(i,mid,val);
    return binarySearch(mid+1,j,val);
}
void solve(long val){
    long pos= binarySearch(1,v.size(),val);
    long z= v[pos]- val;
    if(z < pos){
        x= 1 + z;
        y= pos - z;
    }else{
        z= v[pos-1];
        z= val- z;
        x= 1 + z;
        y= pos- 1 - z;
    }
}
int main(){
    pre();
    long c;
    cin>>c;
    long n;
    for(long i=0;i<c;i++){
        cin>>n;
        solve(n);
        cout<<"TERM "<<n<<" IS "<<y<<"/"<<x<<endl;
    }
    return 0;
}

