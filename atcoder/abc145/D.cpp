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
const ll N = 2e6 + 10 ;
const ll INF = 1e18 + 10 ;
ll fact[N];
ll fastPow(ll a, ll b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    ll y = fastPow(a, b / 2) ; 
    if ( b & 1 ){
        return (((y % MOD) * (y % MOD)) % MOD * a) % MOD ;
    }
    else return (y % MOD * y % MOD) % MOD;
}
ll inverse(ll x){
    return fastPow(x, MOD - 2) ; 
}
ll comb(ll n, ll k){
    fact[0] = fact[1] = 1 ; 
    for(ll i = 2; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        fact[i] = fact[i] % MOD ; 
    }
    return (((fact[n] % MOD) * (inverse(fact[k]) % MOD)) % MOD * (inverse(fact[n - k]) % MOD) ) % MOD ;
}
int main(){
    fastio
    ll x , y ; 
    cin >> x >> y ; 
    if ( (x + y) % 3 != 0 ){
        puts("0") ; 
        return 0 ; 
    }
    ll cnt = (x + y) / 3 ;
    x -= cnt , y -= cnt ; 
    if ( x < 0 || y < 0 ) {
        puts("0") ;
        return 0 ; 
    }
    cout << comb(x + y, x) << endl;
    return 0; 
}