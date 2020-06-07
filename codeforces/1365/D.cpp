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
int n , m ;
char grid[55][55] ;
bool vis[55][55] ;
int countGood = 0 ;
int countBad = 0 ;
void dfs(int x, int y){
    if ( x < 0 || x >= n ) return ;
    if ( y < 0 || y >= m ) return ;
    if ( grid[x][y] == '#' ) return ;
    if ( vis[x][y] ) return ;
    vis[x][y] = true ;
    if ( grid[x][y] == 'G' ) countGood++ ; 
    else if ( grid[x][y] == 'B' ) countBad++;
    dfs(x - 1, y) ;
    dfs(x, y - 1) ;
    dfs(x, y + 1) ;
    dfs(x + 1, y) ;
}
void clear(){
    countGood = 0 ;
    countBad = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = false ;
        }
    }
}
void solve(){
    cin >> n >> m ;
    int good = 0 ;
    int bad = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j] ;
            if ( grid[i][j] == 'G' ) good++ ;
            else if ( grid[i][j] == 'B' ) bad++ ;
        }
    }
    if ( good == 0 ){
        cout << "Yes" << endl ;
        return ;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( i == n - 1 && j == m - 1 ) continue ;
            if ( grid[i][j] == 'B' ){
                if ( i > 0 && grid[i - 1][j] == '.' ){
                    grid[i - 1][j] = '#' ;
                    clear() ;
                    dfs(n - 1, m - 1) ;
                    if ( countGood != good ){
                        grid[i - 1][j] = '.' ;
                    }
                }
                if ( i < n - 1 && grid[i + 1][j] == '.' ){
                    grid[i + 1][j] = '#' ;
                    clear() ;
                    dfs(n - 1, m - 1) ;
                    if ( countGood != good ){
                        grid[i + 1][j] = '.' ;
                    }
                }
                if ( j > 0 && grid[i][j - 1] == '.' ){
                    grid[i][j - 1] = '#' ;
                    clear() ;
                    dfs(n - 1, m - 1) ;
                    if ( countGood != good ){
                        grid[i][j - 1] = '.' ;
                    }
                }
                if ( j < m - 1 && grid[i][j + 1] == '.' ){
                    grid[i][j + 1] = '#' ;
                    clear() ;
                    dfs(n - 1, m - 1) ;
                    if ( countGood != good ){
                        grid[i][j + 1] = '.' ;
                    }
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if ( i == n - 1 && j == m - 1 ) continue ;
    //         if ( grid[i][j] == '.'){
    //             grid[i][j] = '#' ;
    //             clear() ;
    //             dfs(n - 1, m - 1) ;
    //             if ( countGood != good ){
    //                 grid[i][j] = '.' ;
    //             }
    //         }
    //     }
    // }
    clear() ;
    dfs(n - 1, m - 1) ;
    if ( countBad > 0 || countGood != good ){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}
signed main(){
    fastio
    int t; 
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
/*
3 3
.G.
.G#
.#.


*/
