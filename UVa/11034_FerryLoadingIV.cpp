#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
#include <bitset>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int l,m,c;
queue < int > qLeft, qRight;
int solve(){
	l *= 100;
	bool b = 0;
	int s = 0;
	int res = 0;
	while(!qRight.empty() || !qLeft.empty()){
		//cout<<b<<endl;
		if(b){
			while(!qRight.empty()){
				if(s+qRight.front() > l) break;
				s+= qRight.front();
				qRight.pop();
			}
		}else{
			while(!qLeft.empty()){
				if(s+qLeft.front() > l) break;
				s+= qLeft.front();
				qLeft.pop();
			}
		}
		if(b) b = 0;
		else b = 1;
		res++;
		s = 0;
	}
	return res;
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>c;
	int leng;
	string left;
	for(int i= 0 ;i< c;i++){
		cin>>l>>m;
		for(int j = 0; j< m ;j++){
			cin>>leng>>left;
			if(left == string("left")) qLeft.push(leng);
			else qRight.push(leng);
		}
		cout<<solve()<<endl;
	}	
    return 0;
}