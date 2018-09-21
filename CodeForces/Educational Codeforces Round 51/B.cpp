#include <bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	long long int l,r;
	cin>>l>>r;
	cout<<"YES"<<endl;
	for(long long int i=l;i<=r;i+=2){
		cout<<i<<" "<<i+1<<endl;
	}
	return 0;
}