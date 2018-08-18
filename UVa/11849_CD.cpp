#include <iostream>
#include <map>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	int n,m;
	map < int , int > cd;
	while (cin>>n>>m && n != 0){
		cd.clear();
		for(int i = 0;i< n ;i++) {
			int x;
			cin>>x;
			cd[x]++;
		}
		int res = 0;
		for(int i = 0;i< m ;i++) {
			int x;
			cin>>x;
			if(cd[x]) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}