#include <bits/stdc++.h>
using namespace std;
char c;
string s;
void solveE(){
	int d = 1;
	for(int i=1;i<s.size();i++){
		if(s[i] == s[i-1]){
			d++;
		}else{
			cout<<s[i-1]<<d;
			d= 1;
		}
	}
	cout<<s[s.size()-1]<<d<<endl;
}
void solveD(){
	char x;
	for(int i=1;i<s.size();i++){
		if(s[i]  < '0'  || s[i] > '9') x = s[i];
		else{
			int j = i;
			while(s[j] >= '0' && s[j] <= '9') j++;
			int y = atoi(string(s.begin()+i,s.begin()+j).c_str());
			//cout<<y<<endl;
			for(int d = 1;d<=y;d++) cout<<s[i-1];
			i = j-1;
		}
	}
	cout<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>c>>s;
	if(c == 'E') solveE();
	else solveD();
	return 0;
}