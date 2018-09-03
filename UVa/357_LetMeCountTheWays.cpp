#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int US[]={0,1,5,10,25,50};
int n;
ll F[30005][6];
int main(){
	cout<< false + true<<endl;
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	for(int i=1;i<=30000;i++) F[i][1] = 1;
	for(int i=0;i<=5;i++) F[0][i] = 1;
	for(int i=1;i<=30000;i++){
		for(int j=2;j<=5;j++){
			F[i][j] = F[i][j-1];
			if(i >= US[j])
				F[i][j]+= F[i-US[j]][j];
		}
	}
	while(cin>>n){
		ll r = F[n][5];
		if(r == 1) printf("There is only 1 way to produce %d cents change.\n",n);
		else cout<<"There are "<<r<<" ways to produce "<<n<<" cents change.\n";
	}
	return 0;
}