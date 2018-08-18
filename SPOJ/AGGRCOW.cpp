#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,c;
        cin>>n>>c;
        long long a[100009];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        long long i=1,j=1000000001,ans=0,l=0;
        while(i<=j)
        {
            long long mid=((j+i)/2);
            int fi=a[0],temp=1;
            for(int k=1;k<n;k++)
            {
                if(a[k]-fi>=mid)
                    temp++,fi=a[k];
            }
            if(temp<c)
                j=mid-1;
            else
            {
                ans=mid;
                i=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
