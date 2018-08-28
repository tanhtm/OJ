#include <bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int n,m;
	cin>>n>>m;
	char c;
	int x1,x2,y1,y2;
	x1= x2= y1= y2 = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c == 'B'){
				if(x1 == -1 ){
					x1 = x2 = i;
					y1 = y2 = j;
				}
				else{
					x2 = i;
					y2 = j;
				}
			} 
		}
	}
	cout<<(x1+x2)/2<<" "<<(y1+y2)/2<<endl;
	return 0;
}