#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
bool cmp (ii a, ii b){
	return a.second > b.second;
}
int t, n,k;
ii CH[100005];
int main(){
	freopen("icecream.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0;i<n;i++){
			int c,h;
			cin>>c;
			CH[i] .first = c;
		}
		for(int i = 0;i<n;i++){
			int c,h;
			cin>>h;
			CH[i].second = h;
		}
		sort(CH,CH + n);
		/*for(int i = 0;i<n;i++){
			cout<<CH[i].first<<" "<<CH[i].second<<endl;
		}*/
		int MaxCl = CH[k-1].first;
		int d = k - 1;
		for(d = k-1;d<n;d++) if(CH[d].first != MaxCl) break;
		sort(CH, CH + d, cmp);
		long long int Happy = 0;
		for(int i = 0;i<k;i++){
			Happy+= CH[i].second;
		}
		cout<<MaxCl<<" "<<Happy<<endl;
	}
	return 0;
}