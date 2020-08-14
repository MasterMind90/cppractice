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
int n , m , k ;
vector<int> a , b , c ;
int dp[205][205][205] ;
int dfs(int x, int y, int z){
    if ( x == n && y == m && z == k ) {
        return 0 ;
    }
    if ( dp[x][y][z] != -1 ) return dp[x][y][z] ;
    int ans = 0 ;
    if ( x < n && y < m ){
        ans = max(ans, a[x] * b[y] + dfs(x + 1, y + 1, z));
    }
    if ( x < n && z < k ){
        ans = max(ans, a[x] * c[z] + dfs(x + 1, y, z + 1));
    }
    if ( y < m && z < k ){
        ans = max(ans, b[y] * c[z] + dfs(x, y + 1, z + 1));
    }
    return dp[x][y][z] = ans ;
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> m >> k ;
    a = vector<int>(n) ;
    b = vector<int>(m) ;
    c = vector<int>(k) ;
    for(int i = 0; i < n; i++){
        cin >> a[i] ;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i] ;
    }
    for(int i = 0; i < k; i++){
        cin >> c[i] ;
    }
    sort(a.rbegin(), a.rend()) ;
    sort(b.rbegin(), b.rend()) ;
    sort(c.rbegin(), c.rend()) ;
    int ans = dfs(0 , 0 , 0) ;
    cout << ans << endl;
    return 0; 
}