#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int N, M, x, t, DS = 0;
	bool a[1004];
	cin>>N>>M;
	memset(a, 0, sizeof a);
	cin>>x;
	for (int i = 0; i < x; i++) {
		cin>>t;
		a[t] = 1;
		if (t) {
			DS++;
		}
	}
	vector<int> v[N];
	for (int i = 0; i < N; i++) {
		cin>>x;
		for (int j = 0; j < x; j++) {
			cin>>t;
			v[i].push_back(t);
		}
	}
	for (int i = 1; i <= 2 * N; i += N) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				a[v[j][k]] = !a[v[j][k]];
				if (a[ v[j][k] ]) {
					DS++;
				} else {
					DS--;
				}
			}
			if (DS == 0) {
				cout<<i + j<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}