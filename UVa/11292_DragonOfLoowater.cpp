#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n, m;
int headDragon[20005], heighKnigh[20005];
int main(){
	//freopen("data.txt","r",stdin);
	while(cin>>n>>m && n!= 0){
		for(int i=0;i<n;i++) cin>>headDragon[i];
		for(int i=0;i<m;i++) cin>>heighKnigh[i];
		sort(headDragon,headDragon+n);
		sort(heighKnigh,heighKnigh+m);
		int drag = 0,knig = 0;
		int gold = 0;
		bool b = true;
		while(drag != n){
			while(knig < m && headDragon[drag] > heighKnigh[knig]) knig++;
			if(knig == m){
				b = false;
				break;
			}
			gold+= heighKnigh[knig];
			drag++;
			knig++;
		}
		if(b) cout<<gold<<endl;
		else cout<<"Loowater is doomed!"<<endl;
	}
	return 0;
}