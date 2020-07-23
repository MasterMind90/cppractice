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
    int n , m ; 
    cin >> n >> m ;
    vector<pair<int,int> > edge(m) ;
    vector<int> cost(m) ;
    for(int i = 0; i < m; i++){
        cin >> edge[i].first >> edge[i].second ;
        edge[i].first--;
        edge[i].second--;
        cin >> cost[i] ;
    }
    vector<vector<int> > dist(n, vector<int>(n, INF));
    vector<vector<int> > next(n, vector<int>(n, -1));
    for(int i = 0; i < m; i++){
        int u = edge[i].first ;
        int v = edge[i].second ;
        dist[u][v] = cost[i] ;
        dist[v][u] = cost[i] ;
        next[u][v] = v ;
        next[v][u] = u ; 
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0 ;
        next[i][i] = i ; 
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if ( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j] ;
                    next[i][j] = next[i][k] ;
                }
            }
        }
    }
    set<pair<int,int> > s ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ( i == j ) continue ;
            int start = i ; 
            int end = j ;
            while(start != end){
                s.insert(make_pair(start, next[start][end])) ;
                s.insert(make_pair(next[start][end], start)) ;
                start = next[start][end] ;
            }
        }
    }
    int ans = 0 ;
    for(int e = 0; e < m; e++){
        if ( s.count(edge[e]) == 0 ) ans++ ;
    }
    cout << ans << endl;
    return 0; 
}