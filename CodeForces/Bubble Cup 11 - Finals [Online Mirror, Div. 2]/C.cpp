#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, D;
	cin>>N>>D;
	vector<int> s;
	multiset<int> p;
	multiset<int>::iterator it;
	int x;
	for (int i = 0; i < N; i++) {
		cin>>x;
		s.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		cin>>x;
		p.insert(x);
	}
	int sD = s[D - 1];
	it = p.end();
	it--;
	int t = s[D - 1] + *it;
	//cout<<t<<endl;
	p.erase(it);
	int i;
	for (i = D-2; i >=0; i--) {
		it = p.lower_bound(t-s[i]+1);
		it--;
		//cout<<s[i]<<" "<<*it<<endl;
		if(*it + s[i] > t ){
			cout<<i + 2<<endl;
			return 0;
		}
		p.erase(it);
	}
	cout<<1<<endl;
	return 0;
}