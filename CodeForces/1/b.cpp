#include <bits/stdc++.h>
using namespace std;
void solve1(string s){ // R23C55
	int col,row;
	sscanf(s.c_str(),"R %d C %d",&row,&col);
	//cout<<col<<" "<<row<<endl;
	string res;
	while(col > 0){
		int c = col%26;
		col/=26;
		if(c == 0){
			c= 'Z';
			col--;
		}else c = c-1 + 'A';
		res+= char(c);
	}
	reverse(res.begin(),res.end());
	cout<<res<<row<<endl;
}
void solve2(string s){ // BC23
	char col[1000000];
	int row;
	sscanf(s.c_str(),"%s %d",col,&row);
	s = string(col);
	long long int res = s[0]-'A'+1;
	for(long long int i =1;i<s.size();i++){
		res*= 26;
		res+= s[i]-'A'+1;
	}
	cout<<"R"<<row<<"C"<<res<<endl;
}
bool isDigit(char c){
	if(c >='0' && c <='9') return true;
	return false;
}
int main(){
	long long int t;
	cin>>t;
	for(long long int i=0;i<t;i++){
		string s,str;
		cin>>s;
		long long int d = 0;
		for(long long int j =0 ;j<s.size()-1;j++){
			str+=s[j];
			if(isDigit(s[j+1]) && !isDigit(s[j])){
				str+=' ';
				d++;
			}
			if(!isDigit(s[j+1]) && isDigit(s[j])){
				d++;
				str+=' ';
			}
		}
		str+= s[s.size()-1];
		//cout<<str<<endl;
		if(d > 1) solve1(str);
		else solve2(str); 
	}
	return 0;
}