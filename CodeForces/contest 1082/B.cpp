#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("PALIN.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	int n;
	string s;
	cin>>n>>s;
	n = s.size();
	vector < int > F;
	string v; 
	v+= s[0];
	F.push_back(1);
	int d = 0;
	if(s[0] =='G') d++;
	for(int i=1;i<n;i++){
		if(s[i] == v.back()) F[F.size()-1]++;
		else{
			v+=s[i];
			if(s[i] == 'G') d++;
			F.push_back(1);
		}
	}
	/*for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "<<F[i]<<endl;
	}
	cout<<d<<endl;*/
	int ans = 0;
	if(d == 1){
		for(int i=0;i<v.size();i++){
			if(v[i] == 'G') ans = max(ans, F[i]);
		}
	}
	if(d == 2){
		for(int i=0;i<v.size();i++){
			if(v[i] == 'S'){
				if(i == 0) continue;
				ans = max(ans, F[i-1]+1);
				if(i == v.size()-1) continue;
				if(F[i] == 1) ans = max(ans, F[i-1]+F[i+1]);
				else {
					ans = max(ans, F[i-1]+1);
					ans = max(ans, F[i+1]+1);
				}
			}
		}
	}
	if(d >= 3){
		for(int i=0;i<v.size();i++){
			if(v[i] == 'S'){
				if(i == 0) continue;
				ans = max(ans, F[i-1]+1);
				if(i == v.size()-1) continue;
				if(F[i] == 1) ans = max(ans, F[i-1]+F[i+1]+1);
				else {
					ans = max(ans, F[i-1]+1);
					ans = max(ans, F[i+1]+1);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}