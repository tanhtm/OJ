#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
string t,h,k,n;
void open(const char* f){
    freopen(f,"r",stdin);
}

void balance (string &a, string &b){ // làm cho 2 số thành cùng size bằng cách thêm những số 0 đàng trc số bé hơn
    int sz_a = a.size(), sz_b= b.size();
    if(sz_a > sz_b) b= string(sz_a- sz_b,'0') +b;
    else a= string(sz_b- sz_a,'0') +a;
}
string sub(string a, string b){ // trừ , mặc định trả về kết quả dương
    // O(n)
    balance(a,b);
    int sz= a.size(), flag=0;
    for(int i=sz-1; i>=0;i--){
        a[i]= a[i] - b[i] - flag + '0';
        flag =0;
        if(a[i]<'0'){
            flag= 1;
            a[i]+= 10;
        }
    }
    int i=0;
    for(; i< sz; i++) if(a[i]!= '0') break;
    if(i == sz) return "0";
    if(i != 0) return string(a.begin()+i, a.end());
    return a;
}
string add (string a, string b){
    // O(n)
    balance(a,b);
    int sz= a.size(), flag=0;
    for(int i=sz-1; i>=0;i--){
        a[i]= a[i] + b[i] + flag - '0';
        flag =0;
        if(a[i]>'9'){
            flag= 1;
            a[i]-= 10;
        }
    }
    if(flag==1) a = "1" + a;
    return a;
}
string divideBy2( string s){ // chia đôi
    // O(n)
    if(s.size()==1 && s[0]<='1') return "0";
    int flag= 0,c,i=0;
    if(s[0] < '2'){
        i++;
        flag = s[0] - 48;
    }
    string res;
    for(i; i<s.size();i++){
        c= s[i] -48 + flag*10;
        flag= c%2;
        c= c/2;
        res += c+ 48;
    }
    if(res == string()) res= "0";
    return res;
}
void solve(){
    string k2 = add(t,h);
    k= divideBy2(k2);
    n= sub(t,k);
    cout<<k<<endl;
    cout<<n<<endl;
}
int main(){
    for(int i=0; i<10;i++){
        cin>>t>>h;
        solve();
    }
    return 0;
}

