#include <bits/stdc++.h>
using namespace std;
struct coffe
{
	int s, m, l;
};
unordered_map < string , coffe > M;
int t, c, p;
int main(){
	freopen("coffee.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>c>>p;
		for(int i=0;i<c;i++){
			string n;
			coffe Coffe;
			cin>>n>>Coffe.s>>Coffe.m>>Coffe.l;
			M[n] = Coffe;
		}
		int ship = 100/p;
		for(int i=0;i<p;i++){
			string n, sz, type;
			cin>>n>>sz>>type;
			int mon = ship;
			if(sz == "medium"){
				mon+=M[type].m;
			}
			if(sz == "large"){
				mon+=M[type].l;
			}
			if(sz == "small"){
				mon+=M[type].s;
			}
			int du = mon%5;
			if(du == 1) mon--;
			if(du == 4) mon++;
			cout<<n<<" "<<mon<<endl;
		}
	}
	return 0;
}