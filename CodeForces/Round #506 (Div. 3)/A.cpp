#include <bits/stdc++.h>
using namespace std;
int n,k;
string t;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n>>k>>t;
	int d = 0;
	string r(k*n,'.');
	for(int i=0;i<r.size();i++){
		int x= i,y= 0;
		if(r[i] == '.'){
			for(;y<t.size();y++){
				r[x] = t[y];
				x++;
			}
			d++;
			if(d==k) break;
			continue;
		}
		if(r[i] != t[0]) continue;
		while(r[x] == t[y]){
			x++;
			y++;
		}
		if(r[x] != '.') continue;
		for(;y<t.size();y++){
			r[x] = t[y];
			x++;
		}
		d++;
		i++;
		if(d==k) break;
	}
	string ans;
	for(int i=0;i<r.size();i++){
		if(r[i]=='.') break;
		ans+= r[i];
	}
	cout<<ans<<endl;
	return 0;
}