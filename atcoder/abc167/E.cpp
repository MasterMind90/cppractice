#ifndef LOCAL
#pragma GCC optimize("O3")
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
// const ll MOD = 1e9 + 7 ;
const ll MOD = 998244353 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int fast(int a, int b){
    if ( b == 0 ) return 1; 
    if ( b == 1 ) return a ;
    int y = fast(a, b / 2) % MOD ;
    int ans = 1; 
    if ( b & 1 ) ans = a ;
    int result = y * y ; 
    result %= MOD ;
    result *= ans ;
    return result % MOD ;
}
int inverse(int x){
    return fast(x, MOD - 2) ;
}
signed main(){
    fastio
    int n , m , k ;
    cin >> n >> m >> k ; 
    vector<int> fact(n + 1) ;
    fact[0] = fact[1] = 1 ;
    for(int i = 2; i < n + 1; i++){
        fact[i] = i * fact[i - 1] ;
        fact[i] %= MOD ;
    }
    auto C = [&](int A, int B){
        int ans = fact[A] * inverse(fact[B])  ;
        ans %= MOD ;
        ans *= inverse(fact[A - B]) ;
        ans %= MOD ;
        return ans ;
    };
    int ans = 0 ;
    for(int i = 0; i < k + 1; i++){
        int t = m * C(n - 1, i) ;
        t %= MOD ;
        t *= fast(m - 1, n - 1 - i) ; 
        t %= MOD ;
        ans += t ;
        ans %= MOD;
    }
    cout << ans << endl ; 
    return 0; 
}