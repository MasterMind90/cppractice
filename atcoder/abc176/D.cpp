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
vector<string> g ;
bool inRange(int x, int y){
    if ( x < 0 || x >= n ) return false ;
    if ( y < 0 || y >= m ) return false ;
    if ( g[x][y] == '#' ) return false ;
    return true ;
}
signed main(){
    fastio
    cin >> n >> m ;
    g = vector<string>(n) ;
    int a , b , x , y ; 
    cin >> a >> b >> x >> y ; 
    a--, b--, x--, y-- ;
    for(int i = 0; i < n; i++){
        cin >> g[i] ;
    }
    vector<vector<int> > dist(n, vector<int>(m, INF)) ;
    vector<vector<bool> > relaxed(n, vector<bool>(m)) ;
    dist[a][b] = 0 ;
    priority_queue<pair<int,pair<int,int> > > q ;
    q.emplace(0, make_pair(a, b) ) ;
    int X[] = {0, 0, -1, 1} ;
    int Y[] = {1, -1, 0, 0} ;
    while(not q.empty()){
        auto t = q.top() ; q.pop() ;
        int cost = -t.first ;
        int c = t.second.first , d = t.second.second ;
        relaxed[c][d] = true ;
        for(int i = 0; i < 4; i++){
            int newx = c + X[i] , newy = d + Y[i] ;
            if ( not inRange(newx, newy) ) continue ;
            if ( relaxed[newx][newy] ) continue ;
            if ( dist[newx][newy] > cost ){
                dist[newx][newy] = cost ;
                q.emplace(-cost, make_pair(newx, newy) ) ;
            }
        }
        int startx = c - 2 , starty = d - 2 ;
        for(int i = startx ; i < startx + 5; i++){
            for(int j = starty; j < starty + 5; j++){
                if ( not inRange(i, j) ) continue  ;
                if ( relaxed[i][j] ) continue ;
                if ( dist[i][j] > cost + 1){
                    dist[i][j] = cost + 1 ;
                    q.emplace(-dist[i][j], make_pair(i, j) ) ;
                }
            }
        }
    }
    if ( dist[x][y] == INF ) {
        cout << -1 << endl;
    }
    else cout << dist[x][y] << endl;
    return 0; 
}