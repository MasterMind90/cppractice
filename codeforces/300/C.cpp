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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int fast(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    int y = fast(a, b / 2) ;
    y = y % MOD * y % MOD ;
    y %= MOD ;
    if ( b & 1 ) y = y * a ;
    return y % MOD ;
}
int inv(int x){
    return fast(x, MOD - 2) ;
}
vector<int> fact(N) ;
int go(int a, int b){
    int ans = fact[a + b] ;
    ans %= MOD ;
    ans *= inv(fact[a]) ;
    ans %= MOD ;
    ans *= inv(fact[b]) ;
    return ans % MOD ;
}
int a , b , n ;
signed main(){
    fastio
    fact[0] = fact[1] = 1 ;
    for(int i = 1; i < N; i++){
        fact[i] = i * fact[i - 1] ;
        fact[i] %= MOD ;
    }
    cin >> a >> b >> n ;
    int ans = 0 ;
    for(int i = 0; i < n + 1; i++){
        int cur = a * i + (n - i) * b ;
        int x = cur ;
        bool ok = true ;
        while(x != 0) {
            if ( x % 10 != a && x % 10 != b ){
                ok = false ;
                break ;
            }
            x /= 10 ;
        }
        if ( ok ) {
            ans += go(i, n - i) ;
            ans %= MOD ;
        }
    }
    cout << ans << endl;
    return 0; 
}