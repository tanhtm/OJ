#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n, m, d;
	cin>>n>>m>>d;
	vector<int> b;
	set < int > a;
	int t;
	for (int i = 0; i < n; i++) {
		cin>>t;
		a.insert(t);
		b.push_back(t);
	}
	long long int ans = 0, sum = 0;
	//vector<int> kq;
	set<int>::iterator it;
	map <int, int> save;
	while (!a.empty()) {
		sum = *a.begin();
		sum += d;
		sum++;
		//kq.push_back(ans);
		save[*a.begin()] = ans + 1;
		a.erase(a.begin());
		while (sum <= m && !a.empty()) {
			it = a.upper_bound(sum);
			if (*it < sum)
				break;
			sum += d;
			sum++;
			save[*it] = ans + 1;
			a.erase(it);
			//kq.push_back(ans);
		}
		ans ++;
	}
	cout<<ans<<endl;
	for (int i = 0; i < b.size(); i++) {
		cout<<save[b[i]]<<" ";
	}
	return 0;
}