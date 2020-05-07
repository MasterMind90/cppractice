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
bool vis[1001][1001] ;
char grid[1001][1001] ;
int n , m ;
void dfs(int x, int y){
    vis[x][y] = true ;
    if ( x - 1 >= 0 && grid[x - 1][y] == '#' && not vis[x - 1][y] )  dfs(x - 1, y) ;
    if ( y - 1 >= 0 && grid[x][y - 1] == '#' && not vis[x][y - 1] )  dfs(x, y - 1) ;
    if ( x + 1 < n && grid[x + 1][y] == '#' && not vis[x + 1][y] )  dfs(x + 1, y) ;
    if ( y + 1 < m && grid[x][y + 1] == '#' && not vis[x][y + 1] )  dfs(x, y + 1) ;
}
signed main(){
    fastio
    cin >> n >> m ; 
    vector<bool> blackRow(n) , blackCol(m) ;
    vector<bool> whiteRow(n) , whiteCol(m) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j] ;
            if ( grid[i][j] == '#' ) {
                blackRow[i] = true ;
                blackCol[j] = true ;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( grid[i][j] == '.' ) {
                if ( not blackRow[i] && not blackCol[j] ) {
                    whiteRow[i] = true ;
                    whiteCol[j] = true ;
                }
            }
            if ( grid[i][j] == '#' ){
                whiteRow[i] = true ;
                whiteCol[j] = true ;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if ( not whiteRow[i] ) {
            cout << -1 << endl;
            return 0 ; 
        }
    }
    for(int i = 0; i < m; i++){
        if ( not whiteCol[i] ){
            cout << -1 << endl;
            return 0 ;
        }
    }
    vector<int> row[n] ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( grid[i][j] == '#' ){
                row[i].push_back(j) ;
            }
        }
    }
    vector<int> col[m] ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( grid[i][j] == '#' ){
                col[j].push_back(i) ;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( grid[i][j] == '.' ){
                vector<int> &r = row[i] ;
                int before = (upper_bound(r.begin(), r.end(), j) - r.begin()) ; 
                int after = (int)r.size() - before ;
                if ( before > 0 && after > 0 ){
                    cout << -1 << endl;
                    return 0 ; 
                }
                vector<int> &c = col[j] ;
                before = upper_bound(c.begin(), c.end(), i) - c.begin() ;
                debug() << imie(c) ;
                after = (int) c.size() - before ;
                debug() << imie(i) imie(j) imie(before) imie(after) ;
                if ( before > 0 && after > 0 ){
                    cout << -1 << endl;
                    return 0 ; 
                }
            }
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( grid[i][j] == '#' && not vis[i][j] ){
                ans++ ;
                dfs(i, j) ;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}