#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct car
{
	string Name;
	int Min;
	int Max;
};
int d,q;
vector < car > db;
int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>d;
		car c;
		db.clear();
		for(int i=0;i<d;i++){
			cin>>c.Name>>c.Min>>c.Max;
			db.push_back(c); 
		}
		cin>>q;
		int Q;
		for(int i=0;i<q;i++){
			cin>>Q;
			string s;
			for(int j= 0; j<d;j++){
				if(db[j].Min<=Q && db[j].Max>=Q){
					if(!s.size()) s = db[j].Name;
					else{
						s.clear();
						break;
					}
				}
			}
			if(s.size()) cout<<s<<endl;
			else cout<<"UNDETERMINED"<<endl;
		}
		if(test != 0) cout<<endl;
	}
	return 0;
}