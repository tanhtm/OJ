#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Char
{
	char c;
	int posBegin = -1;
	int posEnd;
};
bool operator < (Char a, Char b){
	return a.c < b.c;
}
string s;
int n;
vector < Char > a;
Char BS(int l, int r, char ch){
	if(l==r){
		if(a[l].c == ch) return a[l];
		else return Char();
	}
	int mid = (l+r)/2;
	if(a[mid].c == ch) return a[mid];
	if(a[mid].c > ch) return BS(l,mid,ch);
	return BS(mid+1,r,ch); 
}
void solve(){
	bool b = true;
	Char ch;
	for(int i=0;i<s.size();i++){
		char c = s[i];
		int Begin = i;
		int d = 0;
		while(c == s[i]){
			d++;
			i++;
		}
		i--;
		ch = BS(0,n,c);
		//cout<<ch.c<<ch.posBegin<<ch.posEnd<<endl;
		if(ch.posBegin == -1){
			b = false;
			break;
		}
		if(d > ch.posEnd - ch.posBegin){
			b = false;
			break;
		}
	}
	if(b) cout<<"Matched 0 "<<ch.posBegin<<endl;
	else cout<<"Not matched"<<endl;
}
int main(){
	freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i = 0; i<s.size();i++){
		Char ch;
		ch.c = s[i];
		ch.posBegin = i;
		while(i< s.size() && ch.c == s[i]) i++;
		ch.posEnd = i;
		a.push_back(ch);
		i--;
	}
	n = a.size();
	sort(a.begin(),a.end());
	/*for(int i=0;i<a.size();i++){
		cout<<a[i].c<<" "<<a[i].posBegin<<" "<<a[i].posEnd<<endl;
	}*/
	int q;
	cin>>q;
	for(int i=0 ;i<q;i++){
		cin>>s;
		solve();
	}
	return 0;
}