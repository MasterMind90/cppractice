#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    ll ans = 0; 
    vector<ll> nix , naxx ; 
    ll t = n ; 
    for(ll i = 0; i < n; i++){
        ll l ;
        cin >> l ; 
        set<ll> s ; 
        bool ok = false ;
        ll val = INF ; 
        ll nax = -INF ; 
        for(ll j = 0; j < l; j++){
            ll x ; 
            cin >> x ;
            val = min(val, x) ; 
            nax = max(nax, x) ; 
            if ( x > val ) ok = true ;
            s.insert(x) ;
        }
        if ( ok ) {
            ans += (t + (t - 1)) ; 
            t--;
        }
        else {
            nix.push_back(val) ;
            naxx.push_back(nax) ;
        }
    }
    sort(nix.begin(), nix.end()) ;
    sort(naxx.begin(), naxx.end()) ;
    for(ll i = 0; i < (ll)nix.size(); i++){
        ll index = upper_bound(naxx.begin(), naxx.end(), nix[i]) - naxx.begin() ;
        ans += (naxx.size() - index);
    }
    cout << ans << endl;
    return 0; 
}