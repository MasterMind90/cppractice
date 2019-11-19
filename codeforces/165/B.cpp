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
const ll nax = 2e9 ; 
ll power(ll x, ll y){
    ll ans = 1; 
    for(int i = 0; i < y; i++){
        ans *= x ; 
    }
    return ans ; 
}
int main(){
    fastio
    ll n , k ; 
    cin >> n >> k ; 
    ll L = 1, R = 1e18; 
    ll res = -1; 
    while(L <= R){
        ll mid = L + (R - L) / 2 ;
        ll ans = 0 ; 
        for(int i = 0; ; i++){
            ll p = mid / power(k, i) ; 
            if ( p == 0 ) break; 
            ans += p;  
            if ( ans >= n ) break ; 
        }
        debug() << imie(mid) imie(ans) ;
        if ( ans >= n ) {
            res = mid ; 
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << res << endl;
    return 0 ; 
}