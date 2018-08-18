#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair < int , int > ii;
int L,G;
ii listG[10007];
int main(){
	//freopen("data.txt","r",stdin);
	while (cin>>L>>G && L != 0){
		for(int i = 0;i< G;i++){
			int x, r;
			cin>>x>>r;
			ii a(x-r,x+r);
			if(a.first < 0) a.first= 0;
			if(a.second > L) a.second= L;
			listG[i]= a;
		}
		sort(listG,listG+G);
		int d=0,i=0,pos=0,posT,check = 1;
		while(pos != L){
			posT = pos;
			for(;i<G;i++){
				if(pos < listG[i].first) break;
				posT = max(posT,listG[i].second);
			}
			if(posT == pos){
				check = 0;
				break;
			}
			d++;
			pos = posT;
			//cout<<pos<<endl;
		}
		if(check) cout<<G-d<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}