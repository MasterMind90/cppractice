#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
const double EPS = 1e-6 ; 
int fastPow(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    int y = fastPow(a, b / 2) ; 
    if ( b % 2 == 0 ){
        return ((y % MOD)  * (y % MOD)) % MOD ;
    }
    else return ((((y % MOD)  * (y % MOD)) % MOD) * (a % MOD)) % MOD  ;
}
int inverse(int x){ // The inverse when the mod is prime is always x^(mod - 2) ;
    return fastPow(x, MOD - 2) ;
}
int C(int n, int k){
    int nominator = 1 ;
    for(int i = 0; i < k; i++){
        nominator = (nominator * (n - i)) % MOD ; 
    }
    int denom = 1 ;
    for(int i = 1; i <= k; i++){
        denom = (denom * i) % MOD ; 
    }
    int ans = ( nominator * inverse(denom) ) % MOD ;
    return ans ; 
}
int fix(int x){
    return ( x % MOD + MOD ) % MOD ;
}
signed main(){
    fastio
    int n , a , b ; 
    cin >> n >> a >> b ; 
    int total = fastPow(2, n) - 1 ; // the minus one here for the empty set. Total number of subsets are equal to 2^n including the empty set. 
    int ans = fix(total - C(n , a) - C(n , b)) ;
    cout << ans << endl;
    return 0; 
}