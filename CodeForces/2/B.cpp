#include <bits/stdc++.h>
using namespace std;
int n;
int f2[1005][1005],f5[1005][1005],F2[1005][1005],F5[1005][1005],F[1005][1005];
string r[1005][1005];
int main()
{
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i =1 ;i<=n;i++){
		for(int j =1 ;j<=n;j++){
			f2[i][j] = f5[i][j] = 0;
			int x;
			cin>>x;
			int t = x;
			while(t%5 == 0 && t!=0){
				f5[i][j]++;
				t/=5;
			}
			t= x;
			while(t%2 == 0 && t!=0){
				f2[i][j]++;
				t/=2;
			}
		}
	}
	for(int i =1 ;i<=n;i++){
		for(int j =1 ;j<=n;j++){
			cout<<f2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i =1 ;i<=n;i++){
		for(int j =1 ;j<=n;j++){
			cout<<f5[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	F2[1][1] = f2[1][1];
	F5[1][1] = f5[1][1];
	F[1][1] = min(F2[1][1],F5[1][1]);
	for(int i = 2;i<=n;i++){
		F2[i][1] = F2[i-1][1] + f2[i][1];
		F5[i][1] = F5[i-1][1] + f5[i][1];
		F[i][1] = min(F2[i][1],F5[i][1]);
	}
	for(int j = 2;j<=n;j++){
		F2[1][j] = F2[1][j-1] + f2[1][j];
		F5[1][j] = F5[1][j-1] + f5[1][j];
		F[1][j] = min(F2[1][j],F5[1][j]);
	}
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=n;j++){
			F2[i][j] = min(F2[i-1][j],F2[i][j-1]);
			F2[i][j] += f2[i][j];
			F5[i][j] = min(F5[i-1][j],F5[i][j-1]);
			F5[i][j] += f5[i][j];
			F[i][j] = min(F2[i][j],F5[i][j]);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}