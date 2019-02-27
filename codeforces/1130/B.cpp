#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ll n ;
    cin >> n ;
    map<ll,vector<ll> > m ;
    for(int i=1;i<=2*n;i++){
        ll x ;
        cin >> x ;
        m[x].push_back(i);
    }
    ll x = 1 ;
    ll y = 1 ;
    ll ans = 0 ;
    for(int i=1;i<=n;i++){
        ans += min( abs(x-m[i][0])+abs(y-m[i][1]) ,abs(x-m[i][1])+abs(y-m[i][0]));
        x = m[i][0];
        y = m[i][1];
    }
    cout << ans << endl;
    return 0 ;
}
