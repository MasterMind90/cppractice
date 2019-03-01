#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
int main(){
    ll n , m ; 
    cin >> n >> m ;
    vector<pair<ll,ll> > v(m);
    for(int i=0;i<m;i++){
        ll a , b ;
        cin >> a >> b ;
        v[i] = {b,a};
    }
    sort(v.rbegin(),v.rend());
    int index = 0 ;
    ll ans = 0 ;
    for(int i=0;i<m;i++){
        ll MIN = min(v[i].second,n) ; 
        ans += MIN * v[i].first ; 
        n-= MIN ; 
    }
    cout << ans << endl;
    return 0 ;
}
