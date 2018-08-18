#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

stack< char > opera;
stack< string > suffix;
bool isOperator(char c){
    char a[]={'+','-','*','/','^'};
    for(int i =0; i<5;i++) if(c==a[i]) return true;
    return false;
}
int getLever(char c){
    if(c=='+' || c=='-') return 0;
    if(c=='*' || c=='/') return 1;
    if(c=='^') return 2;
    return -1;
}
void addSuffix(){
    string b= suffix.top();suffix.pop();
    string a= suffix.top();suffix.pop();
    suffix.push(a+b+opera.top());
    //cout<<suffix.top()<<endl;
    opera.pop();
}
string Transform(string a){
    for(int i=0; i<a.size(); i++){
        if(a[i]>= 'a' && a[i]<= 'z') suffix.push(string()+a[i]);
        if(isOperator(a[i])){
            if(opera.empty()) opera.push(a[i]);
            else{
                while(getLever(a[i]) <= getLever(opera.top())){
                    addSuffix();
                    if(opera.empty()) break;
                }
                opera.push(a[i]);
            }
        }
        if(a[i]=='(') opera.push(a[i]);
        if(a[i]==')'){
            while(opera.top()!='('){
                addSuffix();
            }
            opera.pop();
        }
    }
    while(!opera.empty()){
        addSuffix();
    }
    return suffix.top();
}
int main(){
    int c;
    cin>>c;
    string x;
    for(int i=0;i<c;i++){
        cin>>x;
        cout<<Transform(x)<<endl;
        suffix.pop();
    }
    return 0;
}
