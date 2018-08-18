#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
// xuất ra màng hình vói k = 1 2 3 4 ta sẽ thấy quy luật r= 192 + (k-1)*250
void open(const char* f){
    freopen(f,"r",stdin);
}
int main(){
    long long c,k;
    cin>>c;
    for(long long i=0 ;i<c; i++){
        cin>>k;
        cout<< (long long)192 + (k-1)*250<<endl;
    }

    return 0;
}

