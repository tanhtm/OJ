#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
int col=1,row;
string s;
char c[21][21];
string solve(){
    row= s.size()/col;
    int k= 0;
    string res;
    for(int i=0; i<row;i++){
        if(i%2==0)
            for(int j=0;j<col;j++)
               c[i][j]= s[k++];
        else
            for(int j=col-1;j>=0;j--)
               c[i][j]= s[k++];
    }

    /*for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            res+=c[j][i];
        }
    }
    return res;
}
int main(){
    cin>>col;
    while(col){
        cin>>s;
        cout<<solve()<<endl;
        cin>>col;
    }
    return 0;
}

