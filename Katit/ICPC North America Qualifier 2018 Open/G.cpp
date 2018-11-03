#include <bits/stdc++.h>
using namespace std;
int n;
string s;
queue < int > q;
vector < int > v;
vector < int > r;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>s;
	s+='.';
	for(int i = 2;i<=n;i++){
		 q.push(i);
	}
	int d = 1;
	r.push_back(1);
	for(int i=1;i<s.size();i++){
		if(s[i] == s[i-1]) d++;
		else{
			v.clear();
			int x = r.back();
			r.pop_back();
			while(d != 0){
				v.push_back(q.front());
				q.pop();
				d--;
			}
			d = 1;
			if(s[i-1] == 'R'){
				r.push_back(x);
				for(int j = 0;j<v.size();j++) r.push_back(v[j]);
			}
			else{
				for(int j = v.size()-1;j>=0;j--) r.push_back(v[j]);
				r.push_back(x);
			}
		}
	}
	for(int i=0;i<n;i++) cout<<r[i]<<endl;
	return 0;
}