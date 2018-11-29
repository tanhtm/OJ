#include <bits/stdc++.h>
using namespace std;
long long int k;
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
	string s;
	cin>>k>>s;
	string t = ok(k);
	int ans = 0;
	if (s <= t && s.size() == t.size() || s.size() < t.size()) {
		cout<<0<<endl;
		return 0;
	}
	for (int i = 1; i < s.size() && s.size() > t.size(); i++) {
		if (s[i] == '1') {
			s.erase(s.begin() + i);
			i--;
			ans++;
		}
	}
	if (s <= t && s.size() == t.size()) {
		cout<<ans<<endl;
	} else if (s.size() == t.size()) {
		cout<<ans+1<<endl;
	} else {
		cout<<ans + s.size() - t.size()<<endl;
	}
	//cout<<s.size()<<endl<<t.size()<<endl;
	return 0;
}