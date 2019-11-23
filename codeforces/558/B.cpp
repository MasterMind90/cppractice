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
~debug() { cerr << endl; }
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
    vector<ll> v(n) ; 
    vector<ll> freq(N) ; 
    ll nax = 0 ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        freq[v[i]]++ ; 
        nax = max(nax, freq[v[i]]) ; 
    }
    vector<ll> first(N, -1) ; 
    vector<ll> last(N, -1) ; 
    for(ll i = 0; i < n; i++){
        ll x = v[i] ; 
        if ( first[x] == -1 ){
            first[x] = i ; 
        }
    }
    for(ll i = 0; i < n; i++){
        ll x = v[n - i - 1] ; 
        if ( last[x] == -1 ){
            last[x] = n - i - 1 ; 
        }
    }
    ll ans = INF ; 
    pair<ll,ll> res = make_pair(0, 0) ; 
    for(ll i = 0; i < N; i++){
        if ( freq[i] == nax ){
            ll x = first[i] ; 
            ll y = last[i] ; 
            ll len = y - x + 1 ;
            if ( len < ans ){
                ans = len ; 
                res = {x + 1, y + 1} ; 
            }
        }
    }
    cout << res.first << ' ' << res.second << endl;
    return 0 ; 
}