#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	while (N--) {
		string s;
		cin>>s;
		bool low = 0, up = 0, digit = 0;
		int clow = 0, cup = 0, cdigit = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				digit = 1;
				cdigit++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				low = 1;
				clow++;
			}
			else {
				up = 1;
				cup++;
			}
		}
		if (digit && !low && !up) {
			cout<<"aA";
			for (int i = 2; i < s.size(); i++) {
				cout<<s[i];
			}
		} else if (!digit && low && !up) {
			cout<<"1A";
			for (int i = 2; i < s.size(); i++) {
				cout<<s[i];
			}
		} else if (!digit && !low && up) {
			cout<<"1a";
			for (int i = 2; i < s.size(); i++) {
				cout<<s[i];
			}
		} else if (digit && low && !up) {
			if (cdigit > 1) {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= '0' && s[i] <= '9') {
						cout<<'A';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			} else {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= 'a' && s[i] <= 'z') {
						cout<<'A';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			}
		} else if (digit && !low && up) {
			if (cdigit > 1) {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= '0' && s[i] <= '9') {
						cout<<'a';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			} else {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						cout<<'a';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			}
		} else if (!digit && low && up) {
			if (clow > 1) {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= 'a' && s[i] <= 'z') {
						cout<<'1';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			} else {
				int i = 0;
				for (i = 0; i < s.size(); i++) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						cout<<'1';
						break;
					} else {
						cout<<s[i];
					}
				}
				i++;
				for (; i < s.size(); i++) {
					cout<<s[i];
				}
			}
		} else {
			cout<<s;
		}
		cout<<endl;
	}
	return 0;
}