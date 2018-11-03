#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int main(){
    int N;
    cin>>N;
    int a[1005];
    for (int i = 0; i < N; i++) {
        cin>>a[i];
    }
    sort(a, a + N);
    long long int ans = 0;
    int vl = N;
    if (N == 1) {
        cout<<a[0]<<endl;
        cout<<a[0]<<endl;
        return 0;
    }
    vector <  ii > vii;
    while (vl > 0) {
        if (vl == 3) {
            vii.push_back(ii(a[0],a[1]));
            vii.push_back(ii(a[0],-1));
            vii.push_back(ii(a[0],a[2]));
            ans += a[2] + a[0] + a[1];
            break;
        } else if (vl == 2) {
            ans += a[1];
            vii.push_back(ii(a[0],a[1]));
            break;
        }
        if (a[1] * 2 + a[0] + a[vl - 1] <= a[vl - 1] + a[vl - 2] + a[0] * 2) {
            ans += a[1];
            //cout<<a[0]<<" "<<a[1]<<endl;
            vii.push_back(ii(a[0],a[1]));
            vl -= 2;
            if (vl <= 0)
                break;
            ans += a[0];
            //cout<<a[0]<<endl;
            vii.push_back(ii(a[0],-1));
            ans += a[vl + 1];
            //cout<<a[vl]<<" "<<a[vl + 1]<<endl;
            vii.push_back(ii(a[vl],a[vl+1]));
            ans += a[1];
            //cout<<a[1]<<endl;
            vii.push_back(ii(a[1],-1));
        } else {
            ans += a[vl - 1] + a[vl - 2] + a[0] * 2;
            vii.push_back(ii(a[0],a[vl - 1]));
            vii.push_back(ii(a[0],-1));
            vii.push_back(ii(a[0],a[vl - 2]));
            vii.push_back(ii(a[0],-1));
            vl -= 2;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<vii.size();i++){
        ii x = vii[i];
        cout<<x.first;
        if(x.second != -1) cout<<" "<<x.second;
        cout<<endl;
    }
    return 0;
}