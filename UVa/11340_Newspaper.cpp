#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main(){
	int c,n,m;
	cin>>c;
	for(int i=0; i<c; i++){
		cin>>n;
		map < char , int > Map;
		for(int j= 0; j<n; j++){
			char ch;
			int v;
			cin>>ch>>v;
			Map[ch] = v;
		}
		cin>>m;
		string s;
		cin.ignore();
		int money= 0;
		for(int j=0;j<m;j++){
			getline(cin,s);
			for(int k = 0 ;k<s.size();k++){
				money+=Map[s[k]];
			}
		}
		//money = 609;
		cout<<money/100<<'.';
		if(money%100 < 10) cout<<0;
		cout<<money%100<<"$"<<endl;
	}
    return 0;
}