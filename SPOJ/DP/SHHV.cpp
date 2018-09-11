#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
 
using namespace std;
 
typedef long long int ll;
ll    n, a[20], vt[20], s, t, l, x;
ll    f[20], res;
int main()
{
	//freopen("data.txt","r",stdin);
	n = 0;
    while (cin>>x) a[++n] = x;
    s = a[n]; n--;
    f[0] = 1;
    for (int i=1;i<=n;i++) f[i] = f[i-1]*i;
 
    /////////////////////////////
 
    for (int i=1;i<=12;i++) vt[i] = i;
    res = 1;
    for (int i=1;i<=n;i++) {
        res += (vt[a[i]]-1) * f[n-i];
        for (int j=a[i]+1;j<=n;j++) vt[j]--;
    }
    cout<<res<<endl;
 
    ////////////////////////////
 
    for (int i=1;i<=n;i++) vt[i] = i;
    t = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            if (t + j * f[n-i] > s) {
                l = j-1;
                break;
            }
        t += l*f[n-i];
        a[i] = vt[l+1];
        for (int j=l+1;j<=n;j++) vt[j] = vt[j+1];
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

    //////////////////////////

    return 0;
}