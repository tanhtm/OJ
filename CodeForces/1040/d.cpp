#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
void run(int l, int r){
	if(l<1) l = 1;
	if(r > n) r = n;
	int mid = (l + r) /2;
	if(r - l <= k*2 + 1) {
		srand(time(0));
		int t = rand() % (r - l) + 1;
		if (k == 0)
			t = 0;
		cout<<l + t<<" "<<l + t<<endl;
		cout.flush();
		cin>>s;
		if (s == "Yes")
			return;
		else 
			run(l - k, r + k);
	} else {
		cout<<l<<" "<<mid<<endl;
	}
	
	
	cout.flush();
	cin>>s;
	if(s == "Yes") return run(l-k,mid+k);
	else run(mid-k,r+k);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n>>k;
	run(1,n);
	return 0;
}