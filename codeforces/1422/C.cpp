#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
int fast(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    int y = fast(a, b / 2) ;
    y *= y ; 
    y %= MOD ;
    if ( b & 1 ) y *= a ;
    return y % MOD ;
}
int F(int n){
    return (n * (n + 1) / 2LL) % MOD ;
}
signed main(){
    fastio
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        debug() << imie(s[n - i - 1]) ;
        debug() << imie(F(n - i - 1)) ;
        debug() << imie(fast(10, i)) ;
        // may overflow 
        int val = F(n - i - 1) * (s[n - i - 1] - '0') ;
        val %= MOD ;
        val *= fast(10, i) ;
        val %= MOD ;
        ans += val ;
        debug() << imie(ans) ;
        ans %= MOD ;
    }
    // 345678 , n = 6 ;
    vector<int> v(n) ;
    int start = 1 ;
    v[0] = 1 ;
    for(int i = 1; i < n; i++){
        start *= 10 ;
        start %= MOD ;
        v[i] = start * (i + 1) ;
        v[i] %= MOD ;
        v[i] += v[i - 1] ;
        v[i] %= MOD ;
    }
    debug() << "test" ; 
    for(int i = 0; i < n - 1; i++){
        debug() << imie(n - i - 1) ;
        debug() << imie(s[i]) ;
        debug() << imie(n - i - 2) ;
        debug() << imie(v[n - i - 2]) ;
        ans += (s[i] - '0') * v[n - i - 2] ;
        ans %= MOD ;
        debug() << imie(ans) ;
    }
    debug() << imie(ans) ;
    // 107
    // 1 * 10^0 + 1 * 10^1 + 1 * 10^1 + 7 * 10^0 = 1 + 10 + 10 + 7 
    // 7 * 10^0 + 0 * 10^1 + 7 * 10^0  = 7 + 0 + 7 
    cout << ans << endl;
    return 0; 
}