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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int d , m ;
int n ; 
int len  ;
vector<int> v ;
vector<vector<int> > dp ;
int get(int x){
    return (1LL << (x + 1)) - (1LL << x) ;
}
int dfs(int x, int cur){
    if ( x == len ) {
        if ( cur == n ) return 1 ;
        return 0 ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    int ans = dfs(x + 1, cur) ;
    if ( cur < n ) ans += (v[x] % m) * (dfs(x + 1, cur + 1) % m) ;
    ans %= m ;
    return dp[x][cur] = ans ;
    // return ans ;
}
void solve(){
    cin >> d >> m ;
    v.clear() ;
    int ans = d % m ;
    for(int i = 0; i < 32; i++){
        if ( (1LL << (i + 1)) > d ) {
            v.emplace_back(d - (1LL << i) + 1) ;
            break ;
        }
        else v.emplace_back(1LL << i) ;
    }
    debug() << imie(v) ;
    len = (int)v.size() ;
    for(n = 2; n < 35 ; n++){
        dp = vector<vector<int> >(len + 1, vector<int>(n + 1, -1)) ;
        ans += dfs(0, 0) ;
        ans %= m ;
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}

// a_0 = 001 = 1 
// a_1 = 011 = 3

// b_0 = 001 = 1 ; 
// b_1 = 001 | 011