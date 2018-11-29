#include <bits/stdc++.h>
using namespace std;
int l[1001], r[1001];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	for(int i = n;i >=1 ; i--){
		int d = 0;
		for(int j=0;j<n;j++){
			if(i >= l[j] && i <= r[j]) d++;
		}
		if(d == i){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}