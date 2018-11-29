#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int n;
	cin>>n;
	int d = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x == 1) d++;
	}
	cout<<n-d<<endl;
	return 0;
}