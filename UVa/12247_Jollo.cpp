#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
using namespace std;
int c[6];
bool b[53];
bool cb[3]; // danh giau bo quan bai c[i]
int main(){
	while(true){
		memset(b,0,53);
		memset(cb,0,3);
		for(int i = 0 ;i< 5; i++){
			cin>>c[i];
			b[c[i]] = 1;
		}
		int w,i;
		if(c[0] == 0) break;
		for(i=1; i<=52; i++){
			if(b[i]) continue;
			w = 0;
			c[5] = i;
			if(c[3] > c[0]) w++;
			if(c[4] > c[1]) w++;
			if(c[5] > c[2]) w++;
			if(w < 2 ) continue;
			w = 0;
			if(c[3] > c[0]) w++;
			if(c[5] > c[1]) w++;
			if(c[4] > c[2]) w++;
			if(w < 2 ) continue;
			w = 0;
			if(c[4] > c[0]) w++;
			if(c[3] > c[1]) w++;
			if(c[5] > c[2]) w++;
			if(w < 2 ) continue;
			w = 0;
			if(c[4] > c[0]) w++;
			if(c[5] > c[1]) w++;
			if(c[3] > c[2]) w++;
			if(w < 2 ) continue;
			w = 0;
			if(c[5] > c[0]) w++;
			if(c[3] > c[1]) w++;
			if(c[4] > c[2]) w++;
			if(w < 2 ) continue;
			w = 0;
			if(c[5] > c[0]) w++;
			if(c[4] > c[1]) w++;
			if(c[3] > c[2]) w++;
			if(w < 2 ) continue;
			cout<<i<<endl;
			break;
		}
		if(i == 53) cout<<-1<<endl;
	}
    return 0;
}