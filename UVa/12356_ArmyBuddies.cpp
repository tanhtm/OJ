#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector < int > L,R; 
/*
L[i] : tu i den L[i] da chet
R[i] : tu R[i] den i da chet
*/
int main(){
	int s,b;
	while(true){
		cin>>s>>b;
		if(s == 0 && b== 0) break;
		L.assign(s+1,0);
		R.assign(s+1,0);
		int l,r;
		for(int i=0 ;i<b;i++){
			cin>>l>>r;
			while(R[l-1] != 0) l = R[l-1];
			while(L[r+1] != 0) r = L[r+1];
			L[l] = r;
			R[r] = l;
			if(l-1 == 0) cout<<'*';
			else cout<<l-1;
			cout<<' ';
			if(r+1 > s) cout<<'*';
			else cout<<r+1;
			cout<<endl;


		}
		cout<<"-"<<endl;
	}
    return 0;
}