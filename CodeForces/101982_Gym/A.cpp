#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int k;
	string s1, s2;
	cin>>k>>s1>>s2;
	int n = s1.size();
	int df = 0;
	for(int i= 0;i<n;i++){
		if(s1[i] != s2[i]) df++;
	}
	int y = min(n-df, k);
	//cout<<y<<endl;
	cout<<y + min(df,n - k)<<endl;
	return 0;
}