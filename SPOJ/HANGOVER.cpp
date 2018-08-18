#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
float f;
void open(const char* f){
    freopen(f,"r",stdin);
}
int solve(){
    int i=1;
    while(f > 0){
        f-= float(1)/(i+1);
        i++;
    }
    return --i;
}
int main(){
    cin>>f;
    while(f != 0){
        cout<<solve()<<" card(s)"<<endl;
        cin>>f;
    }
    return 0;
}

