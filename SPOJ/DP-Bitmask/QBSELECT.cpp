#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll bit[]={0,1,2,4,5,8,9,10};
/*
0 = 0000
1 = 0001
2 = 0010
4 = 0100
8 = 1000
5 = 0101
9 = 1001
10 = 1010
*/
ll n;
ll a[5][10001], f[10001][8]; // f[i][x] la ket qua khi xet tu 0->i voi cau hinh tai i la bit[x]
ll s[10001][8]; // s[i][x] la tong tat ca cac thanh phan duoc chon tai cot i voi cau hinh bit[x]
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n;
	ll maxX = -30000;
	for(ll i=0;i<4;i++){
		for(ll j=0;j<n;j++){
			cin>>a[i][j];
			maxX = max(maxX,a[i][j]);
		}
	}
	if(maxX <= 0){ /// 94.12 ??? => 100
		cout<<maxX;
		return 0;
	}
	for(ll k=0;k<8;k++){
		for(ll i= 0;i<n;i++){
			ll sum = 0;
			for(ll j= 0;j<4;j++)
				if(bit[k] & (1<<j)) sum+= a[j][i]; 
			s[i][k] = sum;
			//cout<<s[i][k]<<" ";
		}
		//cout<<endl;
	}
	memset(f,0,sizeof f); // min = 0 vi co the ko can lay cai nao
	ll ans = 0;
	for(ll k= 0;k<8;k++) {
		f[0][k] = s[0][k]; // base
		ans = max(ans, f[0][k]);
	}
	for(ll i =1;i<n;i++){
		for(ll k=0;k<8;k++){ // cau hinh cua i-1
			for(ll h=0;h<8;h++){ // cau hinh cua i
				if((bit[k] & bit[h]) != 0) continue;
				f[i][h] = max(f[i][h], f[i-1][k] + s[i][h]);
				ans = max(ans, f[i][h]);
			}
		}
	}
	cout<<ans;
	return 0;
}