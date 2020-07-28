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
signed main(){
    fastio
    int n , m , l ;
    cin >> n >> m >> l ;
    vector<vector<int> > g(n, vector<int>(n, INF)) ;
    vector<vector<int> > dist(n, vector<int>(n, INF)) ;
    vector<vector<int> > dist2(n, vector<int>(n, INF)) ;
    vector<vector<int> > next(n, vector<int>(n, -1)) ;
    for(int i = 0; i < m; i++){
        int a , b , c ;
        cin >> a >> b >> c ;
        a--, b-- ;
        g[a][b] = c ;
        g[b][a] = c ;
        dist[a][b] = g[a][b] ;
        dist[b][a] = g[b][a] ;
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0 ;
        dist2[i][i] = 0 ;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if ( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j] ;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ( dist[i][j] <= l ) dist2[i][j] = 1;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if ( dist2[i][j] > dist2[i][k] + dist2[k][j] ){
                    dist2[i][j] = dist2[i][k] + dist2[k][j] ;
                }
            }
        }
    }
    debug() << imie(dist) ;
    int q ;
    cin >> q; 
    while(q--){
        int a , b ;
        cin >> a >> b ;
        a--, b--;
        if ( dist2[a][b] == INF ) {
            cout << -1 << endl;
        }
        else cout << dist2[a][b] - 1 << endl;
    }
    return 0; 
}