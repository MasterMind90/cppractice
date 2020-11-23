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

int n , m ;
vector<vector<char> > v ;
vector<vector<int> > dp , SUM[3] ;
// int dfs(int x, int y){
//     if ( x == n - 1 && y == m - 1 ) {
//         return 1 ;
//     }
//     if ( dp[x][y] != -1 ) return dp[x][y] ;
//     int ans = 0 ;
//     for(int i = x + 1; i < n; i++){
//         if ( v[i][y] == '#' ) break ;
//         ans += dfs(i, y) ;
//         ans %= MOD ;
//     }
//     for(int i = y + 1; i < m; i++){
//         if ( v[x][i] == '#' ) break ;
//         ans += dfs(x, i) ;
//         ans %= MOD ;
//     }
//     for(int i = 1; x + i < n && y + i < m; i++){
//         if ( v[x + i][y + i] == '#' ) break ;
//         ans += dfs(x + i, y + i) ;
//         ans %= MOD ;
//     }
//     return dp[x][y] = ans ;
// }

signed main(){
    fastio
    cin >> n >> m ;
    v = vector<vector<char> >(n, vector<char>(m)) ;
    SUM[0] = SUM[1] = SUM[2] = dp = vector<vector<int> >(n, vector<int>(m, 0)) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j] ;
        }
    }
    // int ans = dfs(0, 0) ;
    // debug() << imie(ans) ;
    // cout << ans << endl;
    dp[0][0] = 1 ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( i == j && i == 0 ) continue ;
            if ( v[i][j] == '#' ) continue ;
            if ( i > 0 ) SUM[0][i][j] = (SUM[0][i - 1][j] + dp[i - 1][j]) % MOD ;
            if ( j > 0 ) SUM[1][i][j] = (SUM[1][i][j - 1] + dp[i][j - 1]) % MOD ;
            if ( i > 0 && j > 0 ) SUM[2][i][j] = (SUM[2][i - 1][j - 1] + dp[i - 1][j - 1]) % MOD ;
            dp[i][j] = (SUM[0][i][j] + SUM[1][i][j] + SUM[2][i][j]) % MOD ;
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0; 
}
// (2 + 1 + 3) * (3 + 2 + 2 + 3 + 3 + 5 + 2)

// dp[i][j] = number of moves to reach position i , j 

// dp[i][j] = sum of dp[i - 1][j] + dp[i - 2][j] + .... + dp[i][j - 1] + dp[i][j - 2] + .... + dp[i - 1][j - 1] ;
