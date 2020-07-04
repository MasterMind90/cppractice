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
    cin >> n >> m ; 
    vector<vector<int> > v(n, vector<int>(m)) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j] ; 
        }
    }
    if ( v[0][0] > 2 || v[0][m - 1] > 2 || v[n - 1][0] > 2 || v[n - 1][m - 1] > 2 ) {
        cout << "NO" << endl ;
        return ;
    }
    vector<vector<int> > ans(n, vector<int>(m)) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( j == 0 && i > 0 && i < n - 1 && v[i][j] > 3 ) {
                cout << "NO" << endl ;
                return ;
            }
            if ( j == m - 1 && i > 0 && i < n - 1 && v[i][j] > 3 ) {
                cout << "NO" << endl ;
                return ;
            }
            if ( i == 0 && j > 0 && j < m - 1 && v[i][j] > 3 ) {
                cout << "NO" << endl ;
                return ;
            }
            if ( i == n - 1 && j > 0 && j < m - 1 && v[i][j] > 3 ) {
                cout << "NO" << endl ;
                return ;
            }
            ans[i][j] = 3 ;
        }
    }
    ans[0][0] = ans[0][m - 1] = ans[n - 1][0] = ans[n - 1][m - 1] = 2 ;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if ( v[i][j] > 4 ) {
                cout << "NO" << endl ;
                return ;
            }
            ans[i][j] = 4 ;
        }
    }
    cout << "YES" << endl ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << ' ' ;
        }
        cout << endl ;
    }
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}