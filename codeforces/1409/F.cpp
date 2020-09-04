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
int n , k ;
string s , t ;
int dp[201][201][201] ;
int dfs(int x, int curs, int curk){
    if ( x < 0 ) {
        return 0 ;
    }
    if ( dp[x][curs][curk] != -1 ) return dp[x][curs][curk] ;
    int ans = 0 ;
    if ( s[x] == t[1] ) {
        ans = max(ans, dfs(x - 1, curs + 1, curk)) ;
        if ( curk > 0 ) ans = max(ans, curs + dfs(x - 1, curs, curk - 1)) ;
    }
    else if ( s[x] == t[0] ) {
        ans = max(ans, curs + dfs(x - 1, curs, curk)) ;
        if ( curk > 0 ) ans = max(ans, dfs(x - 1, curs + 1, curk - 1)) ;
    }
    else{
        ans = max(ans, dfs(x - 1, curs, curk)) ;
        if ( curk > 0 ) {
            ans = max(ans, curs + dfs(x - 1, curs, curk - 1)) ;
            ans = max(ans, dfs(x - 1, curs + 1, curk - 1)) ;
        }
    }
    return dp[x][curs][curk] = ans ;
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> k ;
    cin >> s >> t ;
    if ( t[0] == t[1] ) {
        int cnt = 0 ;
        for(char &c : s){
            if ( c != t[0] ) cnt++ ;
        }
        int total = (n - cnt) + min(cnt, k) ;
        cout << total * (total - 1) / 2 << endl;
        return 0; 
    }
    int ans = dfs(n - 1, 0, k) ;
    cout << ans << endl;
    return 0; 
}