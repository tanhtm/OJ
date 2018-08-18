#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector < int > a;
    int x= 0;
    while(true){
        cin>>x;
        //cout<<x<<endl;
        if(x==42) break;
        a.push_back(x);
    }
    for(int i=0 ;i< a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
