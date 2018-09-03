#include <bits/stdc++.h>
using namespace std;
struct dot
{
	int x,y;
};
int n;
dot dots[10];
double m[10][10];
double dp[10][1<<8];
int pFlat[10][1<<8],maskFlat[10][1<<8];
double run(int p, int mask){
	if(mask == (1<<n)-1) return 0;
	if(dp[p][mask] > 0) return dp[p][mask];
	double res = 2000;
	int p2 = p, mask2= mask;
	for(int i=0;i<n;i++){
		if((mask & (1<<i)) != 0) continue;
		//res = min(res,run(i,mask + (1<<i))+m[i][p]);
		double x = run(i,mask + (1<<i))+m[i][p];
		if(res > x){
			res= x;
			p2 = i;
			mask2 = mask + (1<<i);
		}
	}
	pFlat[p][mask] = p2; // luu vet
	maskFlat[p][mask] = mask2; // luu vet
	return dp[p][mask] = res;
}
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x = dots[i].x - dots[j].x;
			x*=x;
			int y = dots[i].y - dots[j].y;
			y*=y;
			m[i][j] = sqrt(x+y);
			m[i][j]+=16;
			//cout<<m[i][j]<<" ";
		}
		//cout<<endl;
	}
	double ans = 2000; // 000001
	int p = 0,mask = 1;
	for(int i=0;i<n;i++){
		memset(dp,-1,sizeof dp);
		double x = run(i,1<<i);
		if(ans > x){
			ans = x;
			p = i;
			mask = 1<<i;
		}
	}
	int d = 0,x,y;
	while(pFlat[p][mask] != p){ // truy vet
		x = p;
		d++;
		printf("Cable requirement to connect (%d,%d)",dots[p].x,dots[p].y);
		int temp = p;
		p = pFlat[temp][mask];
		y = p;
		printf(" to (%d,%d) is %.2lf feet.\n",dots[p].x,dots[p].y,m[x][y]);
		mask = maskFlat[temp][mask];
		if(d == n-1) break;
	}
	printf("Number of feet of cable required is %.2lf.\n",ans);
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int c = 1;
	while(cin>>n && n != 0){
		cout<<"**********************************************************\n";
		cout<<"Network #"<<c++<<endl;
		for(int i=0;i<n;i++) cin>>dots[i].x>>dots[i].y;
		solve();
	}
	return 0;
}