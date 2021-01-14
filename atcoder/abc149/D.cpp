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
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int m ;
int R , P , S ; 
string s ;
vector<int> cost(4) ;
vector<vector<int> > dp ;
int n , k ;
int dfs(int x, int cur){
    if ( x == m ) {
        return 0 ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur];
    int ans = 0 ; 
    for(int c : {1, 2, 3}){
        if ( c != cur ) {
            if ( s[x] == 'r' ){
                if ( c == 3 ) ans = max(ans, cost[c] + dfs(x + 1, c)) ;
                else ans = max(ans, dfs(x + 1, c));
            }
            else if ( s[x] == 's' ){
                if ( c == 1 ) ans = max(ans, cost[c] + dfs(x + 1, c)) ;
                else ans = max(ans, dfs(x + 1, c));
            }
            else if ( s[x] == 'p' ) {
                if ( c == 2 ) ans = max(ans, cost[c] + dfs(x + 1, c)) ;
                else ans = max(ans, dfs(x + 1, c));
            }
        }
    }
    return dp[x][cur] = ans ;
}
int solve(){
    m = (int) s.size() ;
    dp = vector<vector<int> >(m, vector<int>(4, -1));
    return dfs(0, 0) ;
}
signed main(){
    fastio
    cin >> n >> k ;
    cin >> R >> S >> P ;
    cost[1] = R , cost[2] = S , cost[3] = P  ;
    string t;
    cin >> t ;
    int ans = 0;
    for(int i = 0; i < k; i++){
        s = "" ;
        for(int j = i; j < n; j += k){
            s.push_back(t[j]) ;
        }
        ans += solve() ;
    }
    cout << ans << endl;
    return 0; 
}