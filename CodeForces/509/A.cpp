#include <bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int n;
	cin>>n;
	int x,Max = 0, Min = 1e9;
	for(int i=0;i<n;i++){
		cin>>x;
		Max = max(Max,x);
		Min = min(Min,x);
	}
	cout<<Max - Min + 1 - n<<endl;
	return 0;
}