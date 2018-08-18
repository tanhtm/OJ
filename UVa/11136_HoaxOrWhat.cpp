// not yet
#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
#include <bitset>
#include <queue>
#include <string>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
multiset < int > ms;
multiset < int > :: iterator itMax, itMin, it;
int n,k;
int main(){
	//freopen("data.txt","r",stdin);
	while( cin>> n && n != 0){
		int res = 0;
		ms.clear();
		for(int i = 0 ;i<n;i++){
			cin>>k;
			int x;
			while(k!=0){
				cin>>x;
				ms.insert(x);
				k--;
			}
			itMin = ms.begin();
			itMax = ms.end();
			itMax--;
			res += *itMax - * itMin;
			ms.erase(itMax);
			ms.erase(itMin);
		}
		cout<<res<<endl;
	}
    return 0;
}
