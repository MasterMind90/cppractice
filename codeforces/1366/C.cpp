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
void solve(){
    int n , m ;
    cin >> n >> m ; // 8 2
    // 1 0 1 
    // 0 1 1
    // 1 0 1
    // 0 0 1
    // 1 1 1
    vector<vector<int> > g(n, vector<int>(m));
    if ( n > m ){
        swap(n, m) ; // 3 8
        g.clear() ;
        g = vector<vector<int> >(n, vector<int>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> g[j][i] ;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j] ;
            }
        }
    }
    for(auto &v : g){
        debug() << imie(v) ;
    }
    int half = (n + m - 1) / 2;
    debug() << imie(half) ;
    int ans = 0 ;
    for(int i = 0; i < half ; i++){
        int row = 0, col = i ;
        int zero = 0 ;
        int one = 0 ;
        while(col >= 0 && row < n){
            debug() << imie(row) imie(col) imie(n - row - 1) imie(m - col - 1) ;
            if ( g[row][col] == 0 ) zero++ ;
            if ( g[row][col] == 1 ) one++ ;
            if ( g[n - row - 1][m - col - 1] == 0 ) zero++ ;
            if ( g[n - row - 1][m - col - 1] == 1 ) one++ ;
            col--;
            row++;
        }
        debug() << imie(one) imie(zero) ;
        ans += min(zero, one) ;
    }
    debug() << imie(ans) ;
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}