#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    int ans = 1e9+1;
    for(int i=1;i<n-1;i++){
        int t = i;
        int m = min(v[0],v[i]);
        int res = m / t ;
        ans = min(res,ans);
        t = n-1-i;
        m = min(v[i],v[n-1]);
        res = m / t ;
        ans = min(res,ans);
    }
    int t = n-1;
    int m = min(v[0],v[n-1]);
    int res = m / t ;
    ans = min(ans,res);
    cout << ans << endl;
    return 0 ;
}
