#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
typedef set< char >::iterator it;
char table1[6][5],table2[6][5];
set < char > table[5];
int k;
void in(){
	cin>>k;
	for(int i=0;i<6;i++)
		for(int j= 0;j<5;j++)
			cin>>table1[i][j];
	for(int i=0;i<6;i++)
		for(int j= 0;j<5;j++)
			cin>>table2[i][j];
}
void getTable(){
	vector< bool > mark(27);
	for(int i=0;i<5;i++){
		fill(mark.begin(),mark.end(),false);
		for(int j=0;j<6;j++){
			char c = table1[j][i];
			mark[c-'A'] = true;
		}
		for(int j=0;j<6;j++){
			char c = table2[j][i];
			if(mark[c-'A'] == true) 
				table[i].insert(c);
		}
	}
	/*for(int i=0;i<5;i++){
		for(int j= 0;j<table[i].size();j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
}
void solve(){
	getTable();
	char a,b,c,d,e;
	int dem = 0;
	for(it p1 = table[0].begin();p1 != table[0].end();++p1){
		a = *p1;
		for(it p2 = table[1].begin();p2!= table[1].end();++p2){
			b = *p2;
			for(it p3 = table[2].begin();p3!= table[2].end();++p3){
				c = *p3;
				for(it p4 = table[3].begin();p4!= table[3].end();++p4){
					d = *p4;
					for(it p5= table[4].begin();p5!= table[4].end();++p5){
						e = *p5;
						//cout<<a<<b<<c<<d<<e<<endl;
						dem++;
						if(dem == k){
							//cout<<endl;
							cout<<a<<b<<c<<d<<e<<endl;
							//cout<<endl;
							return;
						}
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int t;
	cin>>t;
	while(t--){
		in();
		solve();
		for(int i=0;i<5;i++) table[i].clear();
	}
	return 0;
}