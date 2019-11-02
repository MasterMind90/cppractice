#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
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
~debug() { cerr << endl; }
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ;
using ll = long long ;
const int N = 1010;
const int INF = 1e9 + 10 ;
int n, m;
vector<vector<int> > graph;
vector<int> vis; 
ll dp[100010];
int dfs(int x){
    if ( vis[x] ) return 0;
    if ( dp[x] != -1 ) return dp[x] ;
    int ans = 0 ; 
    for(int v : graph[x]){
        if ( !vis[v] )
            ans = max(ans, 1 + dfs(v));
    }
    return dp[x] = ans;
}
int main(){
    fastio 
    memset(dp, -1, sizeof dp) ;
    cin >> n >> m ; 
    graph.resize(n + 1) ;
    vis.resize(n + 1) ;
    for(int i = 0; i < m; i++){
        int x , y ;
        cin >> x >> y ; 
        graph[x].push_back(y) ;
    }
    int ans = 0 ; 
    for(int i = 1; i <= n; i++){
        if ( !vis[i] ){
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << endl;
    return 0 ;
}
