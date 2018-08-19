
#include <iostream>
#include<set>
using namespace std;

int main()
{
    int t;
    static int a[10005];
    cin>>t;
	while(t--){
	    bool ok = true;
	    int n,x;
	    cin>>n;
		set<int> b;
		if (n > 40100) {
    		for (int i = 0; i < n; i++) {
        		cin>>x;
        		a[x]++;
        		if (a[x] == 4) {
        		    cout<<x<<" "<<x<<" "<<x<<" "<<x<<" ";
        		    for (int j = i + 1; j < n; j++)
        		        cin>>x;
        		    ok = false;
        		    break;
        		}
    		}
		} else {
		    for (int i = 0; i < n; i++) {
        		cin>>x;
        		a[x]++;
        		if (a[x] == 4) {
        		    cout<<x<<" "<<x<<" "<<x<<" "<<x<<" ";
        		    for (int j = i + 1; j < n; j++)
        		        cin>>x;
        		    ok = false;
        		    break;
        		}
                b.insert(x);
    		}
		}
        set <int> :: iterator itr;
        for (itr = b.begin(); itr != b.end(); ++itr)
        {
            cout << '\t' << *itr;
        }
		if (ok) {
            set < int > :: iterator it = b.begin();
		    cout<<*it<<" "<<*it<<" ";
            it++;
            cout<<*it<<" "<<*it<<" ";
		}
	}
	return 0;
}