#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>s;
	string s1(s.begin(),s.begin()+s.size()/2);
	string s2(s.begin()+s.size()/2, s.end());
	//cout<<s1<<" "<<s2;
	int sums1= 0, sums2 = 0;
	for(int i=0;i<s1.size();i++){
		sums1+=s1[i]-'A';
		sums2+=s2[i]-'A';
	}
	for(int i=0;i<s1.size();i++){
		int x = s1[i] - 'A';
		x+=sums1;
		x%=26;
		s1[i] = x+ 'A';
		x = s2[i] - 'A';
		x+=sums2;
		x%=26;
		s2[i] = x+ 'A';
	}
	//cout<<s1<<" "<<s2<<endl;
	for(int i=0;i<s1.size();i++){
		s1[i]= (s1[i]-'A' + s2[i]-'A')%26 + 'A';
	}
	cout<<s1<<endl;
	return 0;      
}