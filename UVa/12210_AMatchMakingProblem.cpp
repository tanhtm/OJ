#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int b,s;
const int MAX =10007;
int listB[MAX], listS[MAX];
int main(){
	//freopen("data.txt","r",stdin);
	int c = 1;
	while(cin>>b>>s && b != 0){
		printf("Case %d: ",c++);
		for(int i=0;i<b;i++) cin>>listB[i];
		for(int i=0;i<s;i++) cin>>listS[i];
		sort(listB,listB+b);
		//sort(listS,listS+s);
		int r = b-s;
		if(r < 0) r = 0;
		cout<<r;
		if(r != 0){
			cout<<" "<<listB[0];
		}
		cout<<endl;
	}
	return 0;
}