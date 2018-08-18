// UVa 11100 - The Trip, 2007

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define datatype unsigned long long int

struct pa {
	datatype b;
	int c;
};

bool operator <(pa x, pa y) {
	return x.c < y.c || x.c == y.c && x.b > y.b;
}

int main() {
	int n;
	bool first = true;
	while (cin >> n && n > 0) {
		datatype a[10000];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);

		priority_queue<pa> q;
		pa p;
		p.b = a[0];
		p.c = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				q.push(p);
				p.b = a[i];
				p.c = 1;
			} else
				p.c++;
		}
		q.push(p);
		int sol = q.top().c;

		if (first)
			first = false;
		else
			cout << endl;
		cout << sol << endl;

		int nn = n;
		for (int j = sol; j >= 1; j--) {
			int mx = nn / j + ((nn % j > 0) ? 1 : 0);
			bool f = true;
			int z = 0;
			priority_queue<pa> r;
			while (!q.empty()) {
				pa p = q.top();
				q.pop();
				if (f) {
					cout << p.b;
					f = false;
				} else
					cout << " " << p.b;
				p.c--;
				if (p.c)
					r.push(p);
				z++;
				if (z == mx)
					break;
			}
			nn -= z;
			cout << endl;
			while (!r.empty()) {
				q.push(r.top());
				r.pop();
			}
		}
	}
	return 0;
}