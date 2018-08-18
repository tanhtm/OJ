#include <iostream>
#include <vector>
#include <string>
using namespace std;
void canbang(string &a, string &b){
    int szA= a.size(), szB= b.size();
    if(szA > szB){
        b= string(szA- szB,'0') + b;
    }else
        a= string(szB- szA,'0') + a;
}
string add(string a,string b){
    canbang(a,b);
    int nho =0;
    for(int i= a.size()-1; i>=0;i--){
        a[i] = a[i] + b[i] -48 + nho;
        nho =0;
        if(a[i]>'9'){
            a[i]-= 10;
            nho =1;
        }
    }
    if(nho == 1) a= "1" + a;
    return a;
}
string mulChar(string a,char b){
    int nho =0;
    for(int i= a.size()-1; i>=0;i--){
        a[i] = (a[i]-48) * (b-48) + nho;
        nho =0;
        if(a[i] > 9){
            nho  = a[i]/10;
            a[i] = a[i]%10;
        }
        a[i]+= 48;
    }
    if(nho != 0) a= char(nho + 48) + a;
    return a;
}
string div10(string a){
    a= string(a.begin(), a.end()-1);
    return a;
}
string mul(string a, string b){
    //a*b = a*b/10*10 + a*b%10
    if(b.size() == 1) return mulChar(a, b[0]);
    string x = mul(a,div10(b));
    x+='0';
    x= add(x, mulChar(a,b[b.size()-1]));
    return x;
}
string sub1(string a){
    for(int i= a.size()-1 ; i>= 0 ;i--){
        a[i] = a[i] -1;
        if(a[i]>='0') break;
        a[i]+= 10;
    }
    if(a[0] == '0') a= string(a.begin()+1, a.end());
    return a;
}
string gt(string a){
    if(a == "1") return "1";
    return mul(a,gt(sub1(a)));
}
int main() {
    int c;
    cin>>c;
    string x;
    for(int i=0; i< c;i++){
        cin>>x;
        cout<<gt(x)<<endl;
    }
	return 0;
}
