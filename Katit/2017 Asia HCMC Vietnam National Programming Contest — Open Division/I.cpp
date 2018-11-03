#include <bits/stdc++.h>
using namespace std;
int mark[1000005];
int main(){
	int N;
	cin>>N;
	while (N--) {
		int A, B;
		cin>>A>>B;
		int r = 0;
		memset(mark,0,sizeof mark);
		for(int i=A;i<=B;i++){
			int p10 = 1;
			while(p10 <= i) p10*=10;
			p10/=10;
			int j = i;
			for(int turn = 0;turn < 7;turn++){
				j= (j/10) + (j%10)*p10;
				if(i < j && j<=B){
					if(mark[j] == i) break;
					mark[j] = i;
					r++;
				}
			}
		}
		cout<<r<<endl;
	}
	return 0;
}