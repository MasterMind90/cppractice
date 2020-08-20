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
vector<vector<int> > g ;
vector<vector<bool> > vis ;
int cnt = 0 ;
bool inRange(int x, int y){
    if ( x < 0 || x >= n ) return false ;
    if ( y < 0 || y >= m ) return false ;
    return true ;
}
int X[] = {0, 0, -1, 1} ;
int Y[] = {1,-1, 0, 0} ;
int black = 0 ; 
int white = 0 ;
void dfs(int x, int y, int px, int py){
    int cur = g[x][y] ;
    vis[x][y] = true ;
    if ( cur == 1 ) black++ ;
    else white++ ;
    for(int i = 0; i < 4; i++){
        int a = x + X[i] , b = y + Y[i] ;
        if ( not inRange(a, b) ) continue  ;
        if ( a == px && b == py ) continue ;
        if ( vis[a][b] ) continue ;
        if ( g[a][b] == cur ) continue ;
        dfs(a, b, x, y) ;
    }
}
signed main(){
    fastio
    cin >> n >> m ;
    g = vector<vector<int> >(n, vector<int>(m)) ;
    vis = vector<vector<bool> >(n, vector<bool>(m)) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c ;
            cin >> c ;
            if ( c == '#' ) g[i][j] = 1 ;
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( not vis[i][j] ) {
                black = 0 ;
                white = 0 ;
                dfs(i , j, -1, -1) ;
                debug() << imie(cnt) ;
                ans += white * black ;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}

// .#.
// ..#
// #..

// 4 3
// ###
// .##
// ...
// ###

