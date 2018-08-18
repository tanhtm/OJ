#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;

string s;
vector < stack < char > > containers;
set < char > setC;
void putContainer(int i){
	for(int j =0 ; j< containers.size();j++){
		if(s[i] <= containers[j].top()){
			containers[j].push(s[i]);
			return;
		}
	}
	containers.push_back(stack < char > ());
	containers[containers.size()-1].push(s[i]);
}
int t = 0;
int main(){
	while(cin>>s && s != string("end")){
		t++;
		containers.clear();
		setC.clear();
		for(int i =0 ;i< s.size(); i++){
			putContainer(i);
			setC.insert(s[i]);
		}
		cout<<"Case "<<t<<": "<<min(setC.size(),containers.size())<<endl;
	}
    return 0;
}