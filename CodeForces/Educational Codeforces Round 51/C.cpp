#include <bits/stdc++.h>
using namespace std;
int n;
static int Count[101];
vector < int > a;
string r;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		Count[x]++;
		a.push_back(x);
	}
	r.resize(n,'-');
	int dA = 0, dB = 0;
	for(int i=0;i<n;i++){
		if(Count[a[i]] == 1){
			if(dA > dB){
				 r[i] ='B';
				 dB++;
			}
			else {
				r[i] = 'A';
				dA++;
			}
		}
		if(Count[a[i]] == 2) r[i] = 'A';
	}
	if(dA == dB){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(r[i] == '-') cout<<'A';
			else cout<<r[i];
		}
		cout<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(Count[a[i]] > 2){
			if(dA > dB){
				r[i] = 'B';
				cout<<"YES"<<endl;
				for(int i=0;i<n;i++){
					if(r[i] == '-') cout<<'A';
					else cout<<r[i];
				}
				cout<<endl;
				return 0;
			}else{
				r[i] = 'A';
				cout<<"YES"<<endl;
				for(int i=0;i<n;i++){
					if(r[i] == '-') cout<<'B';
					else cout<<r[i];
				}
				cout<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}