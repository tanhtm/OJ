#include <iostream>
using namespace std;
int main() {
	long long int n, q;
	cin>>n>>q;
	long long int kq;
	for (long long int i = 0; i < q; i++) {
		long long int x, y;
		cin>>x>>y;
		if (x % 2 == 1) {
			if (y % 2 == 1)
				kq = (y + 1)/2;
			else if (y % 2 == 0)
				kq = ((n * n + 1) / 2 + 1) + (y - 1)/2;
			cout<<kq + ((x - 1)/2) * n<<endl;
		} else {
			if (y % 2 == 0)
				kq = (y + 1)/2 + (n + 1)/2;
			else if (y % 2 == 1)
				kq = ((n * n + 1) / 2 + 1) + (y - 1)/2 + n/2;
			cout<<kq + ((x - 1)/2) * n<<endl;
		}
	}
	return 0;
}
/*inputCopy
5 4
2 1
4 2
3 3
3 4
outputCopy
16
9
7
20 */