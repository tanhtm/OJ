#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    int c[100];
    for (int i = 0; i < n; i++)
        cin>>c[i];
    int ans = 0;
    int min = a>b?b:a;
    for (int i = 0; i < n / 2; i++) {
        if (c[i] == 0 && c[n - 1 - i] == 2 || c[i] == 2 && c[n - 1 - i] == 0)
            ans += a;
        else if (c[i] == 1 && c[n - 1 - i] == 2 || c[i] == 1 && c[n - 1 - i] == 2)
            ans += b;
        else if (c[i] == 2 && c[n - 1 - i] == 2)
            ans += min * 2;
        else if (c[i] == 0 && c[n - 1 - i] == 1 || c[i] == 1 && c[n - 1 - i] == 0) {
            cout<<-1<<endl;
            return 0;
        }
    }
    if (n % 2 == 1 && c[n / 2] == 2)
        ans += min;
    cout<<ans<<endl;

    return 0;
}
