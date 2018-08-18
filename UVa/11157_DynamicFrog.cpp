#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,d,c= 1;
vector < int > a;
int main(){
	freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);
	cin>>t;
	while(c<=t){
		cin>>n>>d;
		a.clear();
		a.push_back(0);
		for(int i=0;i<n;i++){
			char ch,cha;
			int m;
			cin>>ch>>cha>>m;
			if(ch == 'B') a.push_back(m);
		}
		a.push_back(d);
		int res = 0;
		for(int i = 1;i<a.size();i++){
			res = max(a[i] - a[i-1],res);
		}
		printf("Case %d: %d\n",c++,res);
	}
	return 0;
}