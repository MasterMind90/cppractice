#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<pair<ll,pair<ll,ll> > > v(n);
    for(auto &p : v){
        cin >> p.second.first >> p.second.second ;
        p.first = min(p.second.first*2LL,p.second.second) - min(p.second.first,p.second.second);
    }
    sort(v.rbegin(),v.rend());
    ll ans = 0 ;
    for(auto &p : v){
        //cout << p.first << ":" << p.second.first << "," << p.second.second << endl;
        if ( k && p.second.first ){
            ans += min(p.second.first*2LL,p.second.second);
            k--;
        }
        else
            ans += min(p.second.first,p.second.second);
    }
    cout << ans << endl;
    return 0 ;
}
