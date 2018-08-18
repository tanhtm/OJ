// DP bottom up
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,c,k;
vector < int >  price[25];
int shop[25][205];
void input(){
	cin>>m>>c;
	for(int i=0;i<c;i++){
		price[i].clear();	
		cin>>k;
		for(int j = 0;j<k;j++){
			int p;
			cin>>p;
			price[i].push_back(p);
		}
	}
}
void DP(){
	memset(shop,0,sizeof shop);
	for(int i=0;i< price[0].size();i++)
		if(m >= price[0][i]) 
			shop[0][m - price[0][i]] = price[0][i];
	for(int g = 1;g< c;g++){
		for(int money = 0;money<= m;money++){
			if(shop[g-1][money]){
				for(int k = 0;k< price[g].size();k++){
					if(money >= price[g][k])
						shop[g][money- price[g][k]] = shop[g-1][money]+price[g][k];
				}
			} 
		}
	}
	int res = -1;
	for(int money = 0;money <= m;money++){
		if(shop[c-1][money]) res = max(res,shop[c-1][money]);
	}
	if(res == -1) cout<<"no solution"<<endl;
	else cout<<res<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n;
	while(n--){
		input();
		DP();
	}
	return 0;
}