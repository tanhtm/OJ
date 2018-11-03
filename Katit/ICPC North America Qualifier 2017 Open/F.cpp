#include <bits/stdc++.h>
using namespace std;
/*
Forward = 0;
Left = -1;
Right = 1;
*/
int X, Y,n;
int go[550];

bool run(){
	int x = 0, y = 0;
	char h = 'u';
	for (int i = 0; i < n; i++) {
		if (go[i] == 0 && h == 'u') {
			y++;
		} else if (go[i] == 0 && h == 'd') {
			y--;
		} else if (go[i] == 0 && h == 'l') {
			x--;
		} else if (go[i] == 0 && h == 'r') {
			x++;
		} else if (go[i] == -1) {
			if (h == 'u')
				h = 'l';
			else if (h == 'l')
				h = 'd';
			else if (h == 'd')
				h = 'r';
			else if (h == 'r')
				h = 'u';
		}  else if (go[i] == 1) {
			if (h == 'u')
				h = 'r';
			else if (h == 'r')
				h = 'd';
			else if (h == 'd')
				h = 'l';
			else if (h == 'l')
				h = 'u';
		}
	}
	//cout<<x<<" "<<y<<endl;
	if (x == X && y == Y)
		return 1;
	return 0;
	//cout<<x<<y<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>X>>Y;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="Forward") go[i] = 0;
		if(s=="Left") go[i] = -1;
		if(s=="Right") go[i] = 1;
	}
	for(int i=0;i<n;i++){
		int t = go[i];
		for (int j = -1; j <= 1; j++) {
			go[i] = j;
			if (run()) {
				cout<<i + 1<<" ";
				if (j == -1)
					cout<<"Left"<<endl;
				else if (j == 0)
					cout<<"Forward"<<endl;
				else if (j == 1)
					cout<<"Right"<<endl;
				return 0;
			}
		}
		go[i] = t;
	}
	
	return 0;	
}