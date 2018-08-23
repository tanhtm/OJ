#include <bits/stdc++.h>
using namespace std;
void balence(string &a, string &b){
	if(a.size() < b.size()) swap(a,b);
	b = string (a.size() - b.size(),'0')+ b;
}
string add(string a, string b){
	balence(a,b);
	int flat = 0;
	for(int i=a.size()-1;i>=0;i--){
		a[i] = a[i] + b[i] - 48 + flat;
		flat = 0;
		if(a[i] > '9'){
			a[i]-= 10;
			flat = 1;
		}
	}
	if(flat == 1)
		a = '1'+ a;
	return a;
}
string mulC(string a, int x){
	int flat = 0;
	if(x == 0) return string("0");
	for(int i=a.size()-1;i>=0;i--){
		a[i] = (a[i]-48)*x + flat;
		flat = 0;
		if(a[i] > 9){
			flat = a[i]/10;
			a[i] %= 10;
		}
		a[i]+= 48;
	}
	if(flat != 0)
		a = char(flat+48) + a;
	return a;
}
string mul(string a, string b){
	if(b.size() == 1)
		return mulC(a,b[0]-48);
	int c = b[b.size()-1]-48;
	b.resize(b.size()-1);// xoa don vi
	string r = mul(a,b);
	r+='0';
	r = add(r,mulC(a,c));
	return r;
}
int a[101],n,MAX = -999999;
string toString(int x){ // >= 0
	if(x < 0) x*= -1;
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}
int cmp(string a,string b){
	int n = a.size(), m= b.size();
	if(n > m) return 1;
	if(n < m) return -1;
	for(int i= 0;i< n;i++){
		if(a[i] > b[i]) return 1;
		if(a[i] < b[i]) return -1;
	} 
	return 0;
}
void solve(){
	//cout<<n<<endl;
	string res("0");
	string m("1");
	int d= 0;
	for(int i=0;i<=n;i++){
		if(a[i] < 0) d++;
		if(a[i] == 0){
			m=string("1");
			d= 0;
			continue;
		}
		m = mul(m,toString(a[i]));
		if(d%2==0 && cmp(m,res) == 1)  res= m;
	}
	//cout<<res<<endl;
	d= 0;
	m = string("1");
	for(int i=n;i>=0;i--){
		if(a[i] < 0) d++;
		if(a[i] == 0){
			m=string("1");
			d= 0;
			continue;
		}
		m = mul(m,toString(a[i]));
		if(d%2==0 && cmp(m,res) == 1)  res= m;
	}
	if(res == string("0")) cout<<MAX<<endl;
	else cout<<res<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	n= 0;
	while(cin>>a[n]){
		MAX = max(MAX,a[n]);
		if(a[n] == -999999){
			a[n]=0;
			solve();
			MAX = -999999;
			n=0;
			continue;
		}
		n++;
	}
	return 0;
}