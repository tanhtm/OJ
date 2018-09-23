#include<bits/stdc++.h>
using namespace std;
int n;
int arr[300005];
int mp[15000010];
static bool s[15000010];
int main()
{
    int x,ucln;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(i == 0)
            ucln = x;
        else
            ucln = __gcd(ucln,x);
        arr[i] = x;
    }
    int flag = 1, Max = 0;
    for(int i=0;i<n;i++)
    {
        arr[i] /= ucln;
        mp[arr[i]]++;
        if(arr[i] != 1)
            flag = 0;
        Max = max(Max,arr[i]);
    }
    if(flag == 1)
    {
        printf("-1\n");
        return 0;
    }
    int ans = 0;
    for(int i=2;i<=Max;i++)
    {
        if(!s[i])
        {
            x = 0;
            for(int j=i;j<=Max;j+=i)
            {
                x += mp[j];
                s[j] = 1;
            }
            ans = max(ans,x);
        }
    }
    if(ans == 0)
        ans = 1;
    printf("%d\n",n-ans);
    return 0;
}