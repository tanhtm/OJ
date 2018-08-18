#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int k;
typedef pair < int , int > ii;
int sub (int k, int y){
	int m = k * y;
	int t = y - k;
	if(m%t==0) return m/t;
	return -1;
}
int main(){
	while(cin>>k){
		vector < ii > res;
		for(int i=k+1;;i++){
			int x = sub(k,i);
			if(x == -1) continue;
			res.push_back(ii(x,i));
			if(x == i) break;
		}
		cout<<res.size()<<endl;
		for(int i=0; i<res.size();i++){
			cout<<1<<'/'<<k<<" = 1/"<<res[i].first<<" + 1/"<<res[i].second<<endl;
		}
	}
	return 0;
}