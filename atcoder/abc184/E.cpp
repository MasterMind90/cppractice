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
signed main(){
    fastio
    int n , m ;
    cin >> n >> m ;
    vector<vector<char> > v(n, vector<char>(m)) ;
    int startx , starty ; 
    int endx , endy ; 
    vector<vector<pair<int,int> > > k(26) ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j] ;
            if ( v[i][j] == 'S' ) {
                startx = i ; 
                starty = j ;
            }
            else if ( v[i][j] == 'G' ) {
                endx = i ; 
                endy = j ; 
            }
            else if ( v[i][j] >= 'a' && v[i][j] <= 'z' ) {
                k[v[i][j] - 'a'].emplace_back(i, j) ;
            }
        }
    }
    debug() << imie(endx) imie(endy) ;
    vector<int> X = {0, 0, -1, 1} ;
    vector<int> Y = {1, -1, 0, 0} ;
    queue<pair<int,int> > q ;
    vector<vector<int> > dist(n, vector<int>(m, INF)) ;
    vector<vector<bool> > vis(n, vector<bool>(m, 0)) ;
    dist[startx][starty] = 0 ;
    vis[startx][starty] = true ;
    q.emplace(startx, starty) ;
    auto inRange = [&](int x, int y){
        if ( x < 0 ) return false ;
        if ( y < 0 ) return false ;
        if ( x >= n  ) return false ;
        if ( y >= m  ) return false ;
        if ( v[x][y] == '#'  ) return false ;
        if ( vis[x][y] ) return false ;
        return true ;
    };
    vector<bool> flag(26) ;
    while(not q.empty()){
        // debug() << imie(q.front()) ;
        int x = q.front().first ;
        int y = q.front().second ;
        q.pop() ;
        for(int i = 0; i < 4; i++){
            int newx = x + X[i] , newy = y + Y[i] ;
            // debug() << imie(newx) imie(newy) ;
            if ( inRange(newx, newy) && not vis[newx][newy] ) {
                dist[newx][newy] = dist[x][y] + 1 ;
                vis[newx][newy] = true ;
                q.emplace(newx, newy) ;
            }
        }
        if ( v[x][y] >= 'a' && v[x][y] <= 'z' && flag[v[x][y] - 'a'] == false ){
            flag[v[x][y] - 'a'] = true ;
            for(auto &p : k[v[x][y] - 'a']){
                if ( not vis[p.first][p.second] ){
                    dist[p.first][p.second] = dist[x][y] + 1 ;
                    vis[p.first][p.second] = true ;
                    q.emplace(p.first, p.second) ;
                }
            }
        }
    }
    if ( vis[endx][endy] == false ) {
        cout << -1 << endl;
    }
    else cout << dist[endx][endy] << endl;
    return 0; 
}