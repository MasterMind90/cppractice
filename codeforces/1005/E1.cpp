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
    ll n , m ;
    cin >> n >> m ;
    vector<ll> v(n) ; 
    ll index = 0 ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        if ( v[i] == m ) index = i ; 
    }
    ll ss = 0 ; 
    map<ll,ll> mp ; 
    mp[ss]++ ;
    for(ll i = index + 1; i < n; i++){
        if ( v[i] > m ) ss++ ; 
        else ss-- ; 
        mp[ss]++;
    }
    ll sum = 0 ; 
    ll ans = 0; 
    for(ll i = index; i >= 0; i--){
        if ( v[i] > m ) sum++ ; 
        else sum--; 
        ans += mp[-sum] + mp[-sum - 1] ; 
    }
    cout << ans << endl;
    return 0; 
}