
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int size = s.length() - 1;
    bool ok = true;
    while (ok) {
        int vt = 0;
        for (int i = 0; i <= size; i++)
            if (s[i] != s[size - i]) {
                vt++;
            	if (i == size/2)
            		ok = false;
            }
            else
            	break;
        string tempS;
        for (int i = vt - 1; i >= 0; i--)
            tempS += s[i];
        for (int i = size; i >= vt; i--)
            tempS += s[i];
        s = tempS;

        if (s[0] == s[size])
            break;
    }
    int count = 1;
    int max = 1;
    for (int i = 0; i < size; i++)
        if (s[i] != s[i + 1]) {
            count++;
            if (count > max)
                max = count;
        } else {
        	count = 1;
        }
        
    cout<<max;
    return 0;
}
