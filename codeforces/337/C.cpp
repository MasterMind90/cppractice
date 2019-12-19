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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 9 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
ll fastPow(ll a, ll b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    if ( b & 1 ){
        return ((a % MOD) * (fastPow(a, b - 1) % MOD) ) % MOD ; 
    }
    ll y = fastPow(a, b / 2) ; 
    return ((y % MOD) * (y % MOD)) % MOD ;
}
ll fix(ll x){
    return ((x % MOD) + MOD) % MOD ; 
}
int main(){
    fastio;
    ll n , m , k ; 
    cin >> n >> m >> k ; 
    ll t = n / k * (k - 1) + n % k;
    if ( t >= m ) {
        cout << m << endl;
        return 0; 
    }
    ll spots = m - t;
    ll rest = m - spots * k;
    ll c = fix(fastPow(2, spots + 1) - 2) ; 
    ll ans = ((c % MOD) * (k % MOD)) % MOD ; 
    ans = (ans + rest) % MOD ; 
    cout << ans << endl;
    return 0; 
}
