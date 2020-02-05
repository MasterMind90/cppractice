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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n , a , b , k ;
    cin >> n >> a >> b >> k ; 
    vector<ll> v(n) ; 
    vector<ll> cnt(n) ;
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        v[i] %= (a + b) ; 
        if ( v[i] == 0 ) v[i] = a + b;
        v[i] -= a ;
        if ( v[i] <= 0 ) continue ;
        int c = (v[i] + a - 1) / a ; 
        cnt[i] = c ; 
    }
    debug() << imie(v) ; 
    debug() << imie(cnt) ;
    sort(cnt.begin(), cnt.end()) ;
    ll ans = 0 ; 
    for(ll i = 0; i < n; i++){
        debug() << imie(k) imie(cnt[i]) ;
        if ( k - cnt[i] >= 0 ) {
            k -= cnt[i] ; 
            ans++ ;
        }
    }
    cout << ans << endl;
    return 0 ; 
}