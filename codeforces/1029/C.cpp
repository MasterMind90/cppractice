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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    vector<pair<ll,ll> > v(n) ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second ; 
    }
    vector<pair<ll,ll> > left(n + 1) ; 
    left[0] = make_pair(0, 1e9) ; 
    for(ll i = 0; i < n; i++){
        left[i + 1].first = max(left[i].first, v[i].first);
        left[i + 1].second = min(left[i].second, v[i].second);
    }
    vector<pair<ll,ll> > right(n + 1) ; 
    right[n] = make_pair(0, 1e9) ; 
    for(ll i = 0; i < n; i++){
        right[n - i - 1].first = max(right[n - i].first, v[n - i - 1].first);
        right[n - i - 1].second = min(right[n - i].second, v[n - i - 1].second);
    }
    debug() << imie(left) ; 
    debug() << imie(right) ;
    ll ans = 0 ; 
    for(ll i = 1; i <= n; i++){
        pair<ll,ll> L = left[i - 1]  ; 
        pair<ll,ll> R = right[i] ; 
        ans = max(ans, min(L.second, R.second) - max(L.first,R.first)) ; 
    }
    cout << ans << endl;
    return 0; 
}