#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string s,k_;
string ok(long long int k) {
	string r = "";
	while(k != 0){
		r+= k%2 + '0';
		k/=2;
	}
	reverse(r.begin(), r.end());
	return r;
}
int main(){
	ll k;
	string s,s_;
	cin>>k>>s;
	s_ = s;
	sort(s.begin(),s.end());
	if(s[0] != '1'){
		s[0] = '1';
		s.pop_back();
		s.insert(s.begin()+1,'0');
	}
	k_ = ok(k);
	int ans = 0;
	while(s.size() > k_.size()){
		s.pop_back();
		ans++;
	}
	while(s.size() != k_.size()){
		s.insert(s.begin(),'0');
	}
	if(s_.size() == k_.size()){
		if(s_ > k_) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	//cout<<s<<" "<<k_<<endl;
	if(k_ >= s) cout<<ans<<endl;
	else{
		cout<<ans+1<<endl;
	}
	//cout<<S<<endl;
	return 0;
}

