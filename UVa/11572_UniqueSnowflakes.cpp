#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
#include <bitset>
#include <queue>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int c,n;
map< int , int > M;
int main(){
	//freopen("data.txt","r",stdin);
	cin>>c;
	for(int i = 0; i< c; i++){
		int Max = 0,posW = -1;
		M.clear();
		cin>>n;
		int res = 0;
		for(int j = 1 ;j<=n;j++){
			int x;
			cin>>x;
			//cout<<x<<" ";
			if(!M[x]){
				res++;
				M[x] = j;
			}else
			{
				posW = max(posW, M[x]);
				Max = max(Max,res);
				res = j - posW;
				M[x] = j;
			}
		}
		Max = max(Max,res);
		//cout<<endl;
		cout<<Max<<endl;
	}
    return 0;
}